/*This program is implemented by Ojas Kapre 1611022.
   In this program, we accept numbers in unsorted manner from the user and sort these numbers 
   using insertion and selection sorting technique…*/ 

#include <stdio.h>
#include <conio.h>

void select(int x[],int n);
void insert(int y[],int n);

void main()
{
 int i,n,x[50],y[50],choice;
 clrscr();
 printf("Enter number of elements:\n");
 scanf("%d",&n);
 printf("Enter the elements:\n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&x[i]);
    y[i]=x[i];
 }
 do{
 printf("1.Selection sort\n");
 printf("2.Insertion sort\n");
 printf("3.Exit\n");
 printf("Enter the sorting technique..\n");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:select(x,n);
	printf("Sorted Array is\n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
	 break;
  case 2:insert(y,n);
	printf("Sorted Array is\n");
	 for(i=0;i<n;i++)
		printf("%d ",y[i]);
	printf("\n");
	 break;
  case 3:break;
 }
 }while(choice!=3);
 getch();
}

void select(int x[],int n)
{
 int max,index,i,j,pass;
 for(i=n-1;i>=0;i--)
 {
  max=x[0];
  index=0;
  for(j=0;j<=i;j++)
  if(max<x[j])
  {
	max=x[j];
	index=j;
  }
  x[index]=x[i];
  x[i]=max;
  printf("\nPass %d : ",n-i);
  for(pass=0;pass<n;pass++)
  {
	printf("%d ",x[pass]);
  }
 }
  printf("\n");
}

void insert(int y[],int n)
{
 int i,j,temp,pass;
 for(i=1;i<n;i++)
 {
  temp=y[i];
  for(j=i-1;j>=0&&temp<y[j];j--)
	y[j+1]=y[j];
  y[j+1]=temp;
  printf("\nPass %d : ",i);
  for(pass=0;pass<n;pass++)
  {
	printf("%d ",y[pass]);
  }
 }
 printf("\n");
}
