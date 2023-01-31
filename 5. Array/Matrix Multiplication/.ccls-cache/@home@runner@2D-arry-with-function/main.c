#include <stdio.h>
#include "matrix.h"
int main()
{
    int RowSize, ColSize;
    int a[MaxRow][MaxCol],//1st input array
     b[MaxRow][MaxCol],//2nd input array
     c[MaxRow][MaxCol];//resulting array

    
    printf("Please specify no. of rows of arrays: ");
    RowSize=ReadArraySize(MinRow,MaxRow);
    
    printf("Please specify no. of columns of arrays: ");
    ColSize=ReadArraySize(MinCol,MaxCol);
    printf("Array size is set to: [%d] [%d]\n", RowSize, ColSize);
/*  For dot matrix
    printf("Please specify no. of columns of arrays b: ");
    ColSize=ReadArraySize(MinColb,MaxColb);
    printf("Array size is set to: [%d] [%d]\n", RowSize, ColSize);

  */
    InitArray(a, b, RowSize, ColSize);//init arrays a & b

//find array c[][] = array a[][] + b[][]
    InitArrayC(a, b, c, RowSize, ColSize);
//***change this to c=a.b ** Challenging option...
    DispResult(a, b, c, RowSize, ColSize);//display result

    printf( "please type any key to exit: ");
    getchar();

    return 0;
}
