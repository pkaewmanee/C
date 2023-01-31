
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "control.h"

// ALL FUNCTION WILL BE IN "control.h" file ** I want to keep "main.c" as clean
// as possible **

FILE *fp; 
FILE *mp;


int main(void) {
  int numAnimal;
  char name[30];
  double atk1,atk2;
  double hp1,hp2;
  char pname[30];
  int sindex;
  int x;
  atk1 = 30.00;
  atk2 = 19.00;
  hp1 = 60.00;
  hp2 = 90.0;
  printf("Welcome to Plus Ultra Game...\n\n");
  printf("Press ENTER to go next...\n\n");
  getc(stdin);
  printf("This is a game where you can be an animal of your choice and battle for your survival with your opponent\n\n");
  getc(stdin);
  mp = fopen("Players","a+");
  printf("Player 1 : Please enter your student id and name: ");
  scanf("%d %s",&x,pname);
  fprintf(mp,"%d %s\n",x,pname);
  printf("\n");
  printf("Player 2 : Please enter your student id and name: ");
  scanf("%d %s",&x,pname);
  fprintf(mp,"%d %s\n",x,pname);
  fclose(mp);  
  
  printf("Player 1 please choose your Forests... \n\n");
  printf(" Forest 1: Amazon\n Forest 2: Australia\n Forest 3: Thailand \n");
  printf("Please choose number 1 - 3...\n");
  scanf("%d",&x);
 
  forest3(x);
  

  printf("Player 2 please choose your Forests... \n\n");
  printf(" Forest 1: Amazon\n Forest 2: Australia\n Forest 3: Thailand \n");
  printf("Please choose number 1 - 3...\n");
  scanf("%d",&x);

  forest3(x);

  
 while(hp1 > 0 && hp2 > 0){
 
   if(rpc() == 1){
     hp2 -= atk1;
     printf("Player 2 hit with -%.2f damage\n",atk1);
    printf("Player 2 health: %.2f\n",hp2);
   }
   else if(rpc() == 0){
     hp1 -= atk2;
     printf("Player 1 hit with -%.2f damage\n",atk2);
    printf("Player 1 health: %.2f\n",hp1);
   }
   else{
     printf("It's a Draw");
   }
   }
if(hp1 > 0){
  printf("Player 1 won the Animal game !!");
}
  else{
    printf("Player 2 won the Animal game !!");
  }

  
	return 0;
}
