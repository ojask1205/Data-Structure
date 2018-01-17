/*...This program is implemented by Ojas Kapre 1611022.
     In this program we have created a linked list and performed various
     operations such as concatenate , count and reverse...*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

/*...Structure specification of a node of the linked list...*/
typedef struct node
  {
  int data;
  struct node *next;
  }node;

/*...This function creates a link list...*/
node* create(node *p)
{
int x,ch,n,i;
node *prev, *q;
if(p!=NULL)
  {
  printf("Already created!");
  return p;
  }
do
  {
  printf("Enter no of nodes required: ");
  scanf("%d",&n);
  printf("Enter data of %d nodes: ",n);
  for(i=1;i<=n;i++)
    {
    scanf("%d",&x);
    q=(node*)malloc(sizeof(node));	//Dynamic memory allocation
    if(q==NULL)
      {
      printf("Error in memory allocation. Cannot create!\n");
      return NULL;
      }
    q->data=x;
    q->next=NULL;
    if(p==NULL)
      p=prev=q;
    else
      {
      prev->next=q;
      prev=q;
      }
    }
  printf("Enter 1 to continue adding nodes else enter 0: ");
  scanf("%d",&ch);
  }
while(ch==1);
return p;
}

/*...This function counts the number of nodes in the linked list...*/
int count(node *p)
{
int i=0;
while(p!=NULL)
  {
  i++;
  p=p->next;
  }
return i;
}

/*...This function concatenates one linked list at the end of another...*/
node* conc(node *p, node *q)
{
node *last=p;
if(p==NULL)
  return q;
if (q==NULL)
  return p;
while(last->next!=NULL)
  last=last->next;
last->next=q;
return p;
}

//Prints the elements of the linked list
void print(node *p)
{
if(p==NULL)
  printf("Linked list empty.\n");
else
  {
  while(p!=NULL)
    {
    printf("%d ",p->data);
    p=p->next;
    }
  printf("\n");
  }
}

/*...Reverses the linked list...*/
node* reverse(node *p)
{
node *prev, *post;
prev=post=NULL;
while(p!=NULL)
  {
  post=p->next;
  p->next=prev;
  prev=p;
  p=post;
  }
return prev;
}

/*...Used to free the dynamically allocated memory...*/
node* destroy(node *p)
{
node *q;
while(p!=NULL)
  {
  q=p;
  p=p->next;
  free(q);
  }
return p;
}

void main()
{
node *first, *second;
int c,t,flag=1;
second=first=NULL;
clrscr();
do
{
printf("Menu:\n1. Create linked list\n2. Display linked list\n");
printf("3. Count nodes\n4. Concatenate\n5. Reverse\n6. Destroy lists\n0. Exit\n");
printf("Enter choice: ");
scanf("%d", &c);
switch(c)
  {
  case 1 :
  printf("Create list (1 or 2): ");
  scanf("%d", &t);
  if ((t==1)&&(first==NULL))
    first=create(first);
  else if((t==2)&&(second==NULL))
    second=create(second);
  else printf("Invalid choice!\n");
  break;

  case 2 :
  printf("Linked list 1: ");
  print(first);
  printf("Linked list 2: ");
  print(second);
  break;

  case 3 :
  printf("Number of nodes in list 1 = %d\n",count(first));
  printf("Number of nodes in list 2 = %d\n",count(second));
  break;

  case 4 :
  printf("Press 1 to append list 2 at the end of list 1\n");
  printf("Press 2 to append list 1 at the end of list 2\n");
  scanf("%d",&t);
  if(t==1&&flag)
    {
    first=conc(first, second);
    printf("Linked list 1: ");
    print(first);
    flag=0;
    }
  else if(t==2&&flag)
    {
    second=conc(second, first);
    printf("Linked list 2: ");
    print(second);
    flag=0;
    }
  else printf("Already appended cannot append again!\n");
  break;

  case 5 :
  printf("Reverse list (1 or 2): ");
  scanf("%d", &t);
  if(t==1)
    {
    first=reverse(first);
    printf("Linked list 1: ");
    print(first);
    }
  else if(t==2)
    {
    second=reverse(second);
    printf("Linked list 2: ");
    print(second);
    }
  break;

  case 6 :
  printf("Destroy list (1 or 2): ");
  scanf("%d", &t);
  if(t==1)
    {
    first=destroy(first);
    if(first==NULL)
      printf("Linked list 1 destroyed\n");
    }
  else if (t==2)
    {
    second=destroy(second);
    if(second==NULL)
      printf("Linked list 2 destroyed\n");
    }
  }
}
while(c);

if(first!=NULL)
  destroy(first);
if(second!=NULL)
  destroy(second);
}





