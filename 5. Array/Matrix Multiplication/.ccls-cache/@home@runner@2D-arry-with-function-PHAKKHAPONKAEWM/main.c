#include "matrix.h"
#include <stdio.h>
int main() {
  int RowSize, ColSize, RowSizeB, ColSizeB;

  int a[MaxRow][MaxCol], // 1st input array
      b[MaxRow][MaxCol], // 2nd input array
      c[MaxRow][MaxCol]; // resulting array

  //setting the first array
  printf("Please specify no. of rows of arrays A: ");
  RowSize = ReadArraySize(MinRow, MaxRow);
  printf("Please specify no. of columns of arrays A: ");
  ColSize = ReadArraySize(MinCol, MaxCol);
  printf("Array A size is set to: [%d] [%d]\n", RowSize, ColSize);

  //setting the second array to dot it with
  RowSizeB = ColSize;
  printf("Please specify no. of columns of arrays B: ");
  ColSizeB = ReadArraySize(MinCol, MaxCol);
  printf("Array size of B is set to: [%d] [%d]\n\n", RowSizeB, ColSizeB);

  //initalizing array in array A
  printf("Input for a\n");
  InitArray(a, RowSize, ColSize);
  DispResult(a, RowSize, ColSize);

  //initalizing array in array B
  printf("Input for b\n");
  InitArray(b, RowSize, ColSize);
  DispResult(b, RowSizeB, ColSizeB);

  //A.B = C
  InitArrayC(a, b, c, RowSize, ColSize);
  DispResult(c, RowSize, ColSizeB);

  printf("\nplease type any key to exit: ");
  getchar();

  return 0;
}