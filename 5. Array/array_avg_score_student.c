#include <stdio.h>
#define STD 10		
float avg(int[]);
float avgpl(float);
float avgmi(float);
void sort(int[], float, float);

int main(void) {
    int i,arr[STD];
    for (i = 0; i < STD; i++) {
    printf("Input your number:");
    scanf("%d",&arr[i]);
    }
    float a = avg(arr);
    printf("The Average Score of The Students are %.2f\n",a);
    float avg_up = avgpl(a);
    float avg_low = avgmi(a);
    sort(arr,avg_up,avg_low);
    return 0;
}

float avg(int arr[]){
    float avg = 0;
    int i;
    for (i = 0; i < STD; i++) {
        avg += arr[i];
    }
    avg = avg/STD;
}

float avgpl(float avg){
    float avgpl = avg + (avg*0.2);
    return avgpl;
}

float avgmi(float avg){
    float avgmi = avg - (avg*0.2);
    return avgmi;
}

void sort(int arr[], float avgpl, float avgmi){
    int i;
    printf("%s%15s%15s\n", "Student", "Score", "Grade");
    for (i = 0; i < STD; i++) {
        printf("arr[%d]%15d", i, arr[i]);
        if(arr[i] < avgmi){
            printf("%14s\n","F");
        }  else if (arr[i] >= avgpl){
            printf("%14s\n","A");
        } else if (arr[i] > avgpl || arr[i] < avgpl){
            printf("%14s\n","C");
        }
    }
}



