#include <string.h>
#include <stdio.h>
#include "covert.h"

int main()
{  //MAIN IF is FINISHED
    int num; // convert this ->text
    char text[100]=""; // \0
    num=get_num(); // ASK FOR INPUT. MAKE SURE THE VALUE IS BETWEEN 0-10,000
    num2text(num,text); // 9786 ,""
                        //Special example 19
   printf("%s",text);//print THE TEXT OUT
  //Nine thousand seven hundred  eighty six

    return 0;
}





