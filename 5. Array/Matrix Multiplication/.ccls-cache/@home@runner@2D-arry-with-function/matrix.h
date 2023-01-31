
#define MaxRow 10 //array-maximum no of rows
#define MinRow 1 //array-minimum no of rows
#define MaxCol 6 //array-maximum no of columns
#define MinCol 1 //array-minimum no of columns

int ReadArraySize(int MinSize,int MaxSize) //read array size, row then column
{
    int size;
	do{
      	printf(" range[%d..%d] : ",MinSize,MaxSize);
	    scanf("%d", &size);
   	}while(size > MaxSize || size <= MinSize);

    return size;

}//end 



void InitArray(int a[][MaxCol], int b[][MaxCol], int RowSize, int ColSize)
{
	int i, j;

	printf("\nInitializing arrays a and b..\n");
	for(i=0;i<RowSize;i++)
	    for(j=0;j<ColSize;j++)
     	    {
      	a[i][j]= i+j;
		b[i][j]= 2*(i+j);
          }
}//end 




void InitArrayC(int a[][MaxCol], int b[][MaxCol], int c[][MaxCol], int RowSize, int ColSize)
{
	int i, j;
	
	printf("Calculating array c..\n\n");
	for(i=0;i<RowSize;i++)
	    for(j=0;j<ColSize;j++)
		c[i][j]= a[i][j]+ b[i][j];
}//end InitArrayC()



void DispResult(int a[][MaxCol], int b[][MaxCol], int c[][MaxCol], int RowSize, int ColSize)
{
	int i, j;

   	for(i=0;i<RowSize;i++)
	{
   	     for(j=0;j<ColSize;j++)
		printf("%4d",a[i][j]);
      	     printf("  ");
	     for(j=0;j<ColSize;j++)
         	printf("%4d",b[i][j]);
      	     printf("  ");
	     for(j=0;j<ColSize;j++)
		printf("%4d",c[i][j]);
	     printf("\n");
	}
}//end DispResult()


