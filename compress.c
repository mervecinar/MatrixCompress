#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

// 1-COMPRES_CRS
void compress_CRS(int *nz, int **A,  int *col_ind, int *row_ptr){        
    int Xcol = 0;      
    int Xrow = 0;      
    int Xindex = 0;      
    int XbykSay;  
    int i;
    int j;  
    // col_ind
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(A[i][j] != 0){
                col_ind[Xcol] = j;
                Xcol++;
            }
        }
    }
    //row_ptr
    for(i=0; i<R; i++){
        XbykSay = 0;
        for(j=0; j<C; j++){
            if(A[i][j] != 0){
                if( XbykSay == 0 ){
                    row_ptr[Xrow] = Xindex;
                    Xrow++;
                    XbykSay = 1;
                }
                Xindex++;
            }
        }
    }
    //son index bulma
   row_ptr[Xrow] = Xindex;
   printf("\n CRS: row_ptr: ");
      for(i=0; i<R+1; i++){
        printf("%d " , row_ptr[i]);
    }

 printf("\n CRS :col_ind : ");
    for(i=0; i<Xindex; i++){
        printf("%d " , col_ind[i]);
    }

 }  
 //2-COMPRES_CCS
void compress_CCS( int *nz, int **A, int *row_ind, int *col_ptr){

                 
    int a = 0;
    int Yrow = 0;      
    int Ycol = 0;      
    int Yindex = 0;      
    int YbykSay;  
  int i;
    int j;
   
     // row_ind
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(A[i][j] != 0){
                row_ind[Yrow] = i;
                Yrow++;
            }
        }
    }
    Yrow = 0;
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(A[j][i] != 0){
                row_ind[Yrow] = j;
                Yrow++;
            }
        }
    }

    printf("\n CSS: row_ind:");
    for(i=0; i<Yrow; i++){
        printf("%d " , row_ind[i]);
    }
     

   
   
    //col_ptr
    for(i=0; i<R; i++){
        YbykSay = 0;
        for(j=0; j<C; j++){
            if(A[j][i] != 0){
                if( YbykSay == 0 ){
                    col_ptr[Ycol] = Yindex;
                    Ycol++;
                    YbykSay = 1;
                }
                Yindex++;
            }
        }
    }
        //son index bulma
    col_ptr[Ycol] = Yindex;

    printf("\n CSS :col_ptr : ");
    for(i=0; i<R+1; i++){
        printf("%d " , col_ptr[i]);
    }
}
//3-COMPRESS_IJ
void compress_IJ( int *nz, int **A, int *rows, int *cols){

 
       
}
//4-DECOMPRESS_CRS
int **decompress_CRS(int *nz, int *col_ind, int *row_ptr){
    int Aindex = 0;
    int **A;          
    int i;
    int j;            
     

    A = malloc(R *( sizeof *A));
    for(i=0; i<R; i++){
        A[i] = malloc(C * (sizeof *A[i]));
    }

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(j==col_ind[Aindex]){
                A[i][j] = nz[Aindex];
                Aindex++;
            }else{
                A[i][j] = 0;
            }  
        }
    }

    printf("\nCRS :Decompressed Matrix \n");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return A;
}

//5-DECOMPRES_CCS

int **decompress_CCS(int *nz, int *row_ind, int *col_ptr){
   int Bindex = 0;  
    int **A;          
    int i;
    int j;          
 

    A = malloc(R * ((sizeof *A)));
    for(i=0; i<R; i++){
        A[i] = malloc(C * (sizeof *A[i]));
    }

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(j==row_ind[Bindex]){
                A[j][i] = nz[Bindex];
                Bindex++;
            }else{
                A[j][i] = 0;
            }  
        }
    }

 
    printf("\nCCS :Decompressed Matrix \n");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return A;
}

//6-DECOMPRESS_IJ
int **decompress_IJ(int *nz, int *rows, int *cols){

}
