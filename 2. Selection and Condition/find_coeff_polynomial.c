#include <stdio.h>
#include <math.h>

double root_x1(double a, double b, double c);
double root_x2(double a, double b, double c);

int main(void) { 

  int a,b,c;
  double x1,x2;

  printf("Enter the coefficients(a:b:c): ");
  
  scanf("%d:%d:%d",&a,&b,&c);
  
  printf("The polynomial is ");
  
  // first term of the polynomial
  
  switch(a){
    case 1: printf("x^2"); break;
    case -1: printf("-x^2"); break;
    case 0: break;
    default: printf("%dx^2",a) ;
  }
  
  //second term of the polynomial
  
  if(b>=0){
    switch(b){
    case 1: printf("+x"); break;
    case 0: break;
    default: printf("+%dx",b); 
    }
    
  } else if (b<=0){
    switch(b){
    case -1: printf("-x"); break;
    case 0: break;
    default: printf("-%dx",-1*b); 
  }
  }
  
  //third term of the polynomial
  
  if (c>0){
      printf("+%d\n",c);
  } else if (c<0){
      printf("-%d\n",c*-1);
  } else {
      printf("\n");
  }
  
  //root of the polynomial
  
  x1 = root_x1(a,b,c);
  
  x2 = root_x2(a,b,c);
  
  printf("The root x1 is %.2f\n",x1);
  
  printf("The root x2 is %.2f\n",x2);
  
  return 0;
}

double root_x1(double a, double b, double c)
{
    double x; 
    x = (((-1*b) + sqrt(pow(b,2) - (4*a*c))))/(2*a);
    return x;
}

double root_x2(double a, double b, double c)
{
    double x; 
    x = (((-1*b) - sqrt(pow(b,2) - (4*a*c))))/(2*a);
    return x;
}



