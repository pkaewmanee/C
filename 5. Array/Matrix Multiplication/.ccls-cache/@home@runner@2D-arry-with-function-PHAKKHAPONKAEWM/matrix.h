#define MaxRow 10 // array-maximum no of rows
#define MinRow 1  // array-minimum no of rows
#define MaxCol 6  // array-maximum no of columns
#define MinCol 1  // array-minimum no of columns

#include <stdio.h>
#include <stdlib.h>

int ReadArraySize(int MinSize, int MaxSize) // read array size, row then column
{
  int size;
  do {
    printf("\n range[%d..%d] : ", MinSize, MaxSize);
    scanf("%d", &size);

  } while (size > MaxSize || size <= MinSize);

  return size;

} // end

void InitArray(int a[][MaxCol], int RowSize, int ColSize) {
  int i, j;

  printf("\nInitializing arrays \n\n");
  for (i = 0; i < RowSize; i++)
    for (j = 0; j < ColSize; j++) {
      a[i][j] = i+j/*rand()%6*/;
    }
} // end

void InitArrayC(int a[][MaxCol], int b[][MaxCol], int c[][MaxCol], int RowSize,
                int ColSize) {
  int i, j, k;
  printf("\nCalculating array c..\n\n");
  for (i = 0; i < RowSize; i++) {
    for (j = 0; j < ColSize; j++) {
      c[i][j] = 0;
      for (k = 0; k < ColSize; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
} // end InitArrayC()

void DispResult(int a[][MaxCol], int RowSize, int ColSize) {
  int i, j;

  for (i = 0; i < RowSize; i++) {

    for (j = 0; j < ColSize; j++) {

      printf("%4d", a[i][j]);
      printf("  ");
    }
    printf("\n");
  }
  printf("\n");
} // end DispResult()
