# SpUtil

This is header-only C sparse matrix util library

# funcitons
SpUtil has 5 funcitons:

```c
void SpUtil_read_mm_header(FILE* file, int* N, int* nnz)
```
    - read matrix market format file, and get matrix sizes N and nnz.

```c
void SpUtil_mm2coo(FILE *file, int N, int nnz, int* row_index, int* col_index, double* val)
```
    - create COO from matrix market format file
    - `SpUtil_read_mm_header` must be executed before executing this function

```c
void SpUtil_coo2crs(int N, int nnz, const int* coo_row, const int* coo_col, const double* coo_val, int* row_ptr, int* col_ind, double* val){
```
    - create crs from coo

```c
void SpUtil_print_coo(int N, int nnz, int* row_ptr, int* col_ind, double* val)
void SpUtil_print_crs(int N, int nnz, int* row_ptr, int* col_ind, double* val)
```

    - dump matrix for debug

# test

```
cd test
make 
make run
```
