#include <stdio.h>
#include <string.h>
 
int main()
{
  	/*char str[100], rev[100];
  	int i, j, len;
  	j = 0;
 
  	printf("Please Input Any Number :  ");
  	scanf("%s",str);
  	len = strlen(str);
  	
  	for(i = len-1; i >= 0; i--) {
  	    rev[j++] = str[i];
	}
	rev[i] = '\0';
	
	printf("The reverse of %s is %s",str,rev);*/
	
	int i, j, rev;
	
	i = 0;
	j = 0;
	rev = 0;
	
	printf("Please Input Any Number :  ");
	
	scanf("%d",&i);
	
	printf("The reverse of %d is ",i);
	
	while(i != 0){
	    j = i%10;
	    rev = (rev*10)+j;
	    i = i/10;
	}
	
	printf("%d",rev);
	
  	return 0;
}
