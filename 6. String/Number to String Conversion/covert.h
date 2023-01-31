#include <stdio.h>
#include <string.h>
void num2text(int, char[]); // finished (almost)
int get_num();

void convert1_10(int, char[]);
void convert_teen(int, char[]);
int convert_ty(int, char[]);

int get_num() {
  int num;

  do {
    printf("Input 0 - 10000 numbers: ");
    scanf("%d", &num);
  } while( num <= 0 && num >= 10000);
    
  return num;
}

void num2text(int num, char text[]) { // num=9786 , ""
                                      // ALMOST finished
  int x;
  char temp[20];
  if (num == 0)
    strcpy(text, "Zero");
  else if (num == 10000)
    strcpy(text, "Ten Thousand");
  else { // 1 - 9999
    // if num=9786
    if (num / 1000 > 0) {            //  num/1000 =9 (true)
      convert1_10(num / 1000, text); // text=> "nine"
      strcat(text, " Thousand ");    // "nine thousand"
      num = num % 1000;              // num=786
    }
    if (num / 100 > 0) {            // 786/100  =7 (true)
      convert1_10(num / 100, temp); // temp -->seven
      strcat(text, temp);           //"nine thousand seven"
      strcat(text, " Hundred ");    //"nine thousand seven hundred"
      num = num % 100;              // num = 86
    }
    if (num / 10 > 0) { // 86/10 =8 (true)      // 19/10 =1

      if (num > 10 && num <= 19) {
        convert_teen(num, temp); // 19 = Nineteen (num ->0)
        num = 0;
      } else {
        convert_ty(num, temp); // eighty fourty
      }

      strcat(text, temp); // "nine thousand seven hundred eighty"
      num = num % 10;     // 6
    }
    if (num > 0) {
      convert1_10(num, temp); // six
      strcat(text, " ");
      strcat(text, temp); //"nine thousand seven hundred eighty six
    }
  }
}

void convert1_10(int num, char text[]) {

  if (num >= 0 && num <= 10) { // Zero to Ten
    switch (num) {
    case 1:
      strcpy(text, "One");
      break;
    case 2:
      strcpy(text, "Two");
      break;
    case 3:
      strcpy(text, "Three");
      break;
    case 4:
      strcpy(text, "Four");
      break;
    case 5:
      strcpy(text, "Five");
      break;
    case 6:
      strcpy(text, "Six");
      break;
    case 7:
      strcpy(text, "Seven");
      break;
    case 8:
      strcpy(text, "Eight");
      break;
    case 9:
      strcpy(text, "Nine");
      break;
    case 10:
      strcpy(text, "Ten");
      break;
    default:
      text = "Zero";
    }
  }
}

void convert_teen(int num, char text[]) {
  if (num > 10 && num <= 19) { // Ten to Nineteen
    switch (num) {
    case 11:
      strcpy(text, "Eleven");
      break;
    case 12:
      strcpy(text, "Tweleve");
      break;
    case 13:
      strcpy(text, "Thirteen");
      break;
    case 14:
      strcpy(text, "Fourteen");
      break;
    case 15:
      strcpy(text, "Fifteen");
      break;
    case 16:
      strcpy(text, "Sixteen");
      break;
    case 17:
      strcpy(text, "Seventeen");
      break;
    case 18:
      strcpy(text, "Eighteen");
      break;
    case 19:
      strcpy(text, "Nineteen");
      break;
    default:
      printf(" ");
    }
  }
}

int convert_ty(int num, char text[]) {
  if (num >= 20 && num <= 99) { // Nineteen to Ninety
    int b = num / 10;
    switch (b) {
    case 2:
      strcpy(text, "Twenty");
      break;
    case 3:
      strcpy(text, "Thirty");
      break;
    case 4:
      strcpy(text, "Fourty");
      break;
    case 5:
      strcpy(text, "Fifty");
      break;
    case 6:
      strcpy(text, "Sixty");
      break;
    case 7:
      strcpy(text, "Seventy");
      break;
    case 8:
      strcpy(text, "Eighty");
      break;
    case 9:
      strcpy(text, "Ninety");
      break;
    default:
      printf(" ");
    }
  }
}