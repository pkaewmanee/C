#include <stdio.h>

int main()
{
    int s1,s2,l1,l2,o1,o2;
    
    printf("Input weight1 in(stone:lbs:oz): ");
    scanf("%d:%d:%d",&s1,&l1,&o1);
    
    printf("Input weight2 in(stone:lbs:oz): ");
    scanf("%d:%d:%d",&s2,&l2,&o2);
    
    printf("Total weight is %d St %d lbs %d oz\n", 
    (s1+s2) + (((l1+l2) + (o1+o2)/16))/14 , 
    ((l1+l2) + (o1+o2)/16)%14, 
    (o1+o2)%16);
    
}

