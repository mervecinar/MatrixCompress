#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>


int main(void){
srand(time(NULL));//ayný deðer atamamasý için
    int i,j;
    int *nz;
   
   
    int **A;                  
     A = malloc(R * (sizeof *A));
    for(i=0; i<R; i++){
        A[i] = malloc(C * (sizeof *A[i]));
    }              
   
   
    int *col_ind;  
    int *col_ptr;
           
    int *row_ind;                
    int *row_ptr;
 
    int *cols;        
    int *rows;

     
    int c = 0;      
    int sayac = 0;            
    int a;
   
    int   Matrix[R][C];
                    /*= {{10,0,0,0,-2,0},
                            {3,9,0,0,0,3},
                            {0,7,8,7,0,0},
                            {3,0,8,7,5,0},
                            {0,8,0,9,9,13},
                            {0,4,0,0,2,-1}};
            */
      //Random deðer atama
       fflush(stdout);
      printf("\n   Matrix  \n");
for(i=0; i<R; i++){
        for( j=0; j<C; j++){
            Matrix[i][j] = rand() % 10 ;
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
 
    // 0 dan farkli olanlar
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            A[i][j] = Matrix[i][j];

            if( Matrix[i][j] != 0 ){
                c++;
            }
        }
    }

    //bellekte yer ayýrýmý
   nz = (int *) malloc(c*(sizeof(int)));
   col_ind = (int *) malloc(c*(sizeof(int)));
   col_ptr = (int *) malloc((C+1)*(sizeof(int)));
   row_ptr = (int *) malloc((R+1)*(sizeof(int)));
   row_ind = (int *) malloc(c*(sizeof(int)));
   cols = (int *) malloc( R*C*(sizeof(int)));
   rows = (int *) malloc( R*C*(sizeof(int)));
 
 //nz
  puts("\n");
    printf("nz :");
     
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if( Matrix[i][j] != 0 ){
                nz[sayac] = Matrix[i][j];
                sayac++;
            }
        }
    }

    for(i=0; i<c; i++){
        printf("%d ", nz[i]);
    }
    puts("\n\n");

  //çaðýrma
     puts("\n    compress;");
    compress_CRS( nz, A,col_ind, row_ptr);
    compress_CCS( nz,A, row_ind, col_ptr);
    puts("\n \n   decompress;");
     decompress_CRS(nz, col_ind, row_ptr);
     decompress_CCS(nz, row_ind, col_ptr);
   
// Bellekte tutulan yerleri geri verme
     free( col_ind);
     free( col_ptr);
     free(row_ind);
     free( row_ptr);
     free( cols);
     free(rows);
     free(A);
      free(nz);
}
