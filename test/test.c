#include"../SpUtil.hpp"

int main(){
    int N, nnz;

    //file open and read header to get matrix size
    FILE* fp = fopen("./test.mtx", "r");
    SpUtil_read_mm_header(fp, &N, &nnz);

    printf("N = %d, nnz = %d\n", N, nnz);

    // allocate COO array
    int* coo_row_index = (int*)malloc(sizeof(int)*nnz);
    int* coo_col_index = (int*)malloc(sizeof(int)*nnz);
    double* coo_val = (double*)malloc(sizeof(double)*nnz);

    // create COO from file
    SpUtil_mm2coo(fp, N, nnz, coo_row_index, coo_col_index, coo_val);

    // close
    fclose(fp);

    // print COO (for debug)
    printf("==A in COO format==\n");
    SpUtil_print_coo(N, nnz, coo_row_index, coo_col_index, coo_val);

//////////////////////////////////////////

    // allocate CRS array
    int* crs_row_ptr = (int*)malloc(sizeof(int)*(N+1));
    int* crs_col_ind = (int*)malloc(sizeof(int)*nnz);
    double* crs_val = (double*)malloc(sizeof(double)*nnz);
    
    // crate CRS from COO
    SpUtil_coo2crs(N,nnz,
                coo_row_index, coo_col_index, coo_val,
                crs_row_ptr, crs_col_ind, crs_val);

    printf("==A in CRS format==\n");
    SpUtil_print_crs(N, nnz, crs_row_ptr, crs_col_ind, crs_val);
    return 0;
}
