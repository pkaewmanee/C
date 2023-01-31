#include <string.h>

int rpc(); //Rock Paper Scissor
void stats(); //File function
void stats2();
void stats3();
void forest3(int x);
void skill();



void stats(){
  FILE *fp;
  int numAnimal; 
  char name[30]; 
  double atk; 
  double hp; 
  

  if((fp = fopen("AnimaList","r"))==NULL){
    puts ("File could not be opened ");
  }
  else{
    printf("%-15s%-18s%9s%9s\n","Animal Index","Animal Name","Attack","Health");
    fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);

    while(!feof(fp)){
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    }
    fclose(fp);
  }
 
  return 0;
}

void stats2(){
FILE *fp;
  int numAnimal; 
  char name[30]; 
  double atk; 
  double hp; 
  

  if((fp = fopen("AnimaList2","r"))==NULL){
    puts ("File could not be opened ");
  }
  else{
    printf("%-15s%-18s%9s%9s\n","Animal Index","Animal Name","Attack","Health");
    fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);

    while(!feof(fp)){
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    }
    fclose(fp);
  }
  return 0;
}

void stats3(){
FILE *fp;
  int numAnimal; 
  char name[30]; 
  double atk; 
  double hp; 
  

  if((fp = fopen("AnimaList3","r"))==NULL){
    puts ("File could not be opened ");
  }
  else{
    printf("%-15s%-18s%9s%9s\n","Animal Index","Animal Name","Attack","Health");
    fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);

    while(!feof(fp)){
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    }
    fclose(fp);
  }
  return 0;
}
void forest3(int x){
  FILE *fp;
  FILE *mp;
  int numAnimal,numBattle;
  char name[30],namebattle[30];
  double atk,atkbattle;
  double hp,hpbattle;
  char pname[30];
  int sindex;
  
 switch(x){
    case 1: 
      fp = fopen("AnimaList","r+");
  fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
      printf("Your animal option for Amazon forest...\n");
    stats();
    printf("Please enter animal name to choose: ");
    scanf("%s",pname);
    while(!feof(fp)){
      if(strcmp(name,pname)==0)
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
      
      }
      
    break;
  case 2:
    fp = fopen("AnimaList2","r+");
    fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    printf("Your animal option for Australia forest...\n");
    stats2();
    printf("Please enter animal name to choose: ");
    scanf("%s",pname);
    while(!feof(fp)){
      if(strcmp(name,pname)==0)
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    
      }
    break;
  case 3:
    fp = fopen("AnimaList3","r+");
    fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);
    printf("Your animal option for Thailand forest...\n");
    stats3();
    printf("Please enter animal name to choose: ");
    scanf("%s",pname);
    while(!feof(fp)){
      if(strcmp(name,pname)==0)
      
      printf("%-15d%-18s%9.2f%9.1f\n",numAnimal,name,atk,hp);
      fscanf(fp,"%d %s %lf %lf",&numAnimal,name,&atk,&hp);

      }
    break;
  }

  return 0;
}
int game(char p1, char p2)
{
	
	if (p1 == p2)
		return -1;

	
	if (p1 == 's' && p2 == 'p')
		return 0;

			
			else if (p1 == 'p' && p2 == 's') return 1;

	
	if (p1 == 's' && p2 == 'z')
		return 1;

	
	else if (p1 == 'z' && p2 == 's')
		return 0;

	
	if (p1 == 'p' && p2 == 'z')
		return 0;

	
	else if (p1 == 'z' && p2 == 'p')
		return 1;
}

int rpc(){
	char p1, p2, result,res;
  double atk1,atk2,hp1,hp2;
  atk1 = 15.00;
  atk2 = 25.00;
	hp1 = 100.00;
  hp2 = 100.00;
	
	printf("\n\n\n\n\t\t\t\tPlayer_1 Enter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");


	scanf(" %c", &p1);
  
  printf("****************************************************************************************\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  
  printf("\n\n\n\n\t\t\t\tPlayer_2 Enter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");


	scanf(" %c", &p2);
    
 
  printf("xxxxxxxxx");
  
	result = game(p1, p2);
    if (result == -1) {
		printf("\n\n\t\t\t\tGame Draw!\n");
	}
	else if (result == 1) {
		printf("\n\n\t\t\t\tWow! Player_1 have won the game!\n");
    // hp2 -= atk1;
    // printf("Player 2 hit with -%.2f\n",atk1);
    // printf("Player 2 health: %.2f",hp2);
    return 1;
	}
	else {
		printf("\n\n\t\t\t\tWow! Player_2 have won the game!\n");
    return 0;
	}
		printf("\t\t\t\tPlayer_1 choose : %c and Player_2 choose : %c\n",p1, p2);



}
// Function to implement the game
