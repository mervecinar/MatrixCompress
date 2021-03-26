#ifndef COMPRESS_H //kütüphanem
#define compress
#define R 6 // satýr
#define C 6  // sütun

void compress_CRS(int *nz, int **A,  int *col_ind, int *row_ptr); //1
void compress_CCS( int *nz, int **A , int *row_ind, int *col_ptr);//2
void compress_IJ(int *nz, int **A,  int *rows, int *cols);//3

int **decompress_CRS(int *nz, int *col_ind, int *row_ptr);//4
int **decompress_CCS(int *nz, int *row_ind, int *col_ptr);//5
int **decompress_IJ(int *nz, int *rows, int *cols);//6

#endif
