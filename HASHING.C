#include <stdio.h>
#include <conio.h>
#define HT_SIZE 10

void initHT(int[]);
void store(int[], int[], int, int);
void searchLinear(int[], int);
void searchQuad(int[], int);
int linearProbe(int[], int);
int quadProbe(int[], int);
void display(int[]);

void main()
{
   int ht[HT_SIZE];
   int arr[10], cr, ch, n, i, k;
   clrscr();

   printf("Enter number of elements: ");
   scanf("%d", &n);
   for(i=0; i<n; i++)
	  scanf("%d", &arr[i]);

   printf("Press 1 for Linear Probing, 2 for Quadratic probing: ");
   scanf("%d", &cr);

   initHT(ht);
   store(ht, arr, n, cr);

   do
   {
	  printf("\nMenu\n1.Search\n2.Display hashtable\n0.Exit\nEnter choice: ");
	  scanf("%d", &ch);
	  switch(ch)
	  {
		 case 1:
		 printf("Enter element to be searched: ");
		 scanf("%d", &k);
		 if(cr==1)
			searchLinear(ht, k);
		 else
			searchQuad(ht, k);
		 break;

		 case 2:
		 display(ht);
	  }
   }while(ch);
}

void initHT(int ht[])
{
   int i;
   for(i=0; i<HT_SIZE; i++)
	  ht[i]=-1;
}

void store(int ht[], int arr[], int n, int cr)
{
   int i, hash;
   for(i=0; i<n; i++)
   {
	  hash = arr[i]%HT_SIZE;
	  if(ht[hash] == -1)
		 ht[hash] = arr[i];
	  else if(cr==1)
	  {
		 printf("Collision at %d\n", arr[i]);
		 hash = linearProbe(ht, arr[i]);

	  }
	  else
		{ printf("Collision at %d\n", arr[i]);
		 hash = quadProbe(ht, arr[i]);}
	  ht[hash] = arr[i];
   }
}

int linearProbe(int ht[], int key)
{
   int i;
   for(i=key%HT_SIZE; ht[i]!=-1; i++)
   {
	  if(i==HT_SIZE)
		 i=0;
	  printf("key=key+1=%d\n",i+1 );
   }
   return i;
}

int quadProbe(int ht[], int key)
{
   int i, h;
   for(i=1, h=key%HT_SIZE; ht[h]!=-1; i++) {
	  printf("key=key+i*i=%d",h);
	  h=h+i*i;
	  printf("+%d*%d=%d\n",i,i,h);
	   }
   return h;
}

void display(int ht[])
{
   int i;
   for(i=0; i<HT_SIZE; i++)
   {

		 printf("%d\t%d\t. ", i, ht[i]);
	  if((i+1)%4==0)
		 printf("\n");
   }
}

void searchLinear(int ht[], int key)
{
   int h;
   for(h=key%HT_SIZE; ht[h]!=-1 && ht[h]!=key; h++)
	  if(h==HT_SIZE)
		 h=0;
   if(ht[h]==-1)
	  printf("%d not found!\n", key);
   else
	  printf("%d found!\n", key);
}

void searchQuad(int ht[], int key)
{
   int h, i;
   for(i=1, h=key%HT_SIZE; ht[h]!=-1 && ht[h]!=key; i++)
   {
	  h=h+i*i;
   }
   if(ht[h]==-1)
	  printf("%d not found!\n", key);
   else
	  printf("%d found!\n", key);
}
