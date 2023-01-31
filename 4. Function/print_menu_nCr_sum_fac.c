#include <stdio.h>

void print_menu();
long fac(int);
int nCr(int, int);
int sum(int);

int main() {
    
    int menu;
    int n,r;
    do{
        print_menu();
        scanf("%d",&menu);
        if(menu<4){
            printf("Input your number(n): ");
            scanf("%d",&n);
        }
      switch (menu) {
            case 1:
             printf("Your factorial (n!) is %ld\n", fac(n)); // n!
                break; 
           case 2:
                printf("Input your \'r\': ");
                scanf("%d",&r);
                printf("Your %dC%d is %d\n", n,r,nCr(n,r));
                break;
            case 3:
           printf("Your sumation(Sum(n)) is %d\n", sum(n)); //5+4+3+2+1
                break;
            default:
                break;
        }
    }while(menu!=4);
    return 0;
}

void print_menu(){
    printf("For Factorial, Enter 1\nFor nCr, Enter 2\nFor Summation, Enter 3\nEnter the number: ");
}

long fac(int n) {
    long fac = 1;
    int i;
    for (i = 2; i <= n; i++)
        fac = fac * i;
    return fac;
}
 
int nCr(int n, int r) {
    return fac(n) / (fac(r) * fac(n - r));
}

int sum(int n){
    int i,sum;
    sum = 0;
    for(i=0;i<=n;i++){
        sum += i;
    }
    return sum;
}
