#include <stdio.h>

int main (){
  int i, j, k, col, row, max, space;
  printf ("Enter number: ");
  scanf ("%d", &col);

  row = 2;
  max = col*2;
  space = col-1;

  for (i = max; i > 0; i--){
    for (j = space; j>0; j--) printf(" ");
    
    for (k = 0; k < row; k++){
        printf ("*");
    }
    printf ("\n");
    
    if(i>col+1){
        row += 2;
        space -= 1;
    } else if(i<col+1){
        row -= 2;
        space += 1;
    }
    
  }
}