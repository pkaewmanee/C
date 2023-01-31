#include <stdio.h>
#include <string.h>
 
int main()
{
  	/*char str[100], ch;
  	int i, Count;
  	Count = 0;
 
  	printf("Please Input Any Number : ");
  	scanf("%s",str);
  	
  	//printf("Please Input Any Number That You Want To Count: ");
  	//scanf("%c",ch);
  	
  	ch = '3';
  	
  	for(i = 0; i <= strlen(str); i++)
  	{
  		if(str[i] == ch)  
		{
  			Count++;
 		}
	}
	printf("\n The Total Number of times '%c' has Occured is %d time.", ch, Count);
	
  	return 0;*/
  	
  	unsigned long i,j;
  	int count;
  	
  	i,j,count = 0;
  	
  	printf("Please Input Any Number :  ");
  	
  	scanf("%ld",&i);
  	
  	while(i != 0){
  	    j = i%10;
  	    if(j == 3){
  	        count++;
  	    }
  	    i /= 10;
  	}
  	
  	printf("The Total Number of times '3' has Occured is %d time.",count);
  	
  	return 0;
  	
}