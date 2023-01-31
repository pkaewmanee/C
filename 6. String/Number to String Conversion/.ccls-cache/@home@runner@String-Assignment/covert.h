#include <string.h>
void num2text(int,char[]); //finished (almost)
int get_num();

void convert1_10(int, char[]);
void convert_teen(int, char[]);
int convert_ty(int, char[]);


int get_num(){
  /* ASK FOR INPUT.
    MAKE SURE THE VALUE IS BETWEEN 0-10,000
    (ASK UNTIL IT DOES)
    */
}

void num2text(int num,char text[]){  // num=9786 , ""
//ALMOST finished
    int x;
    char temp[20];
    if(num==0) strcpy(text,"zero");
    else if(num==10000)  strcpy(text,"ten thousand");
    else { //1 - 9999
        // if num=9786
        if(num/1000>0) {  //  num/1000 =9 (true)
            
            convert1_10(num/1000,text);  // text=> "nine"
            strcat(text," thousand ");   // "nine thousand" 
            num=num%1000;               // num=786
        }
        if(num/100>0) {                 // 786/100  =7 (true)
            convert1_10(num/100,temp); // temp -->seven
            strcat(text,temp);        //"nine thousand seven" 
            strcat(text," hundred "); //"nine thousand seven hundred" 
            num=num%100;            // num = 86
        }
        if(num/10>0) {              // 86/10 =8 (true)      // 19/10 =1
            convert_ty(num,temp); // eighty fourty       // 19 = Nineteen (num ->0)
            //or convert_teen                                           
            strcat(text,temp);    // "nine thousand seven hundred eighty"
            num=num%10;            //6
        }
        if(num>0) {     
            convert1_10(num,temp);  //six
             strcat(text,temp); //"nine thousand seven hundred eighty six
        }
    }
     
} 

void convert1_10(int num,char text[]){

    switch(num){
       // covent 1 text to "one"
    }
    
}


void convert_teen(int num,char text[]){
    
}
