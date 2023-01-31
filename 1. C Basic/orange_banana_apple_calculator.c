#include <stdio.h>
#define O_Price 25
#define B_Price 9
#define A_Price 12
#define VAT 1.07

int main()
{
    
    char a_name[100], b_name[100], c_name[100];
    int a_quan, b_quan, c_quan;
    
    //Fruit A
    
    printf("Hi, what are fruit are you buying:");
    scanf("%s", a_name);
    
    printf("Enter the amount of %s, you're buying: ", a_name);
    scanf("%d", &a_quan);
    
    double a_total_price = a_quan * O_Price * VAT;
    
    //Fruit B
    
    printf("Hi, what are fruit are you buying:");
    
    scanf("%s", b_name);
    
    printf("Enter the amount of %s, you're buying: ", b_name);
    scanf("%d", &b_quan);
    
    double b_total_price = b_quan * B_Price * VAT;
    
    //Fruit C
    
    printf("Hi, what are fruit are you buying:");
    
    scanf("%s", c_name);
    
    printf("Enter the amount of %s, you're buying: ", c_name);
    scanf("%d", &c_quan);
    
    double c_total_price = c_quan * A_Price * VAT;
    
    //Sum
    
    double val_sum = a_total_price + b_total_price + c_total_price;
    double qty_sum = a_quan + b_quan + c_quan;
    
    //Average
    
    double qty_avg = qty_sum/3;
    double val_avg = val_sum/3;
    
    char space_name[] = "";
    char qty_name[] = "Qty";
    char val_name[] = "Value";
    char sum_name[] = "Sum";
    char average_name[] = "Average";
    
    printf("%15s%15s%15s\n", space_name, qty_name, val_name);
    printf("==============================================\n");
    printf("%15s%15d%15.1f\n",a_name, a_quan, a_total_price);
    printf("%15s%15d%15.1f\n", b_name, b_quan, b_total_price);
    printf("%15s%15d%15.1f\n", c_name, c_quan, c_total_price);
    printf("==============================================\n");
    printf("%15s%15.1f%15.1f\n",sum_name, qty_sum, val_sum);
    printf("%15s%15.2f%15.2f\n",average_name, qty_avg, val_avg);
    
    return 0;
}

