#include<stdio.h>
#include<stdlib.h>

typedef struct node{
void* data;
struct node* next;
} node;

typedef struct TList {
node* head;
int len;
} TList;



void init(TList **list)
{
  (*list)=(struct TList*)malloc(sizeof(list));
 (*list)->head=NULL;

}

int add (TList *list, int n, void* data)
{
   if(n<0)return -1;
  int i;
  if (n==0)
  {
    node *nou = malloc(sizeof(node));
    nou->data = data;
    nou->next = list->head;
    list->head = nou;
    list->len++;
    return 0;
  }
 node * aux=list->head;
  for(i=0;i<n-1;i++)
  {
    if (aux->next == NULL)return -1;
     else aux=aux->next;
  }

  struct node *nou;
  nou=(struct node*)malloc(sizeof(struct node));
  nou->next=aux->next;
  nou->data = data;
  aux->next=nou;
return 1;
} 

void* Remove (TList *list, int n)
{


  int i;
 node * aux=list->head;
  for(i=0;i<n-1;i++)
     aux=aux->next;

  struct node *aux2;
  aux2=aux->next;
  void *ret = aux2->data;
  aux->next = aux2->next;
  free(aux2);
  return ret;
  
}
int length(TList *list)
{   int len=1;

    node *aux =list->head;
    if(aux==NULL)return 0;
   while(1)
   {  
     if(aux->next==NULL)break;
     else{
        len++;
        aux=aux->next;
         }

   }
  return len;
}

void print_int_list(TList *list)
{
int n=length(list);
struct node* nod;
nod=list->head;
for(int i=0;i<n;i++)
{printf("%x ",*(int*)nod->data);
nod=nod->next;
}

}

void print_string_list(TList *list)
{
int n=length(list);
struct node* nod;
nod=list->head;
for(int i=0;i<n;i++)
{ printf("%s ",(char*)nod->data);
nod=nod->next;
}

}
void free_list(TList **list)
{
   int n;
   n=length(*list);
   for(int i=0;i <n; i++)
   Remove(*list,n-i);


}


int ex2(TList *list)
{
   
int l=length(list);
if (l%2==0)return l/2;
else return l/2+1;
node *n;
  n=list->head;
    for(int i=0;i<l/2;i++)
      n=n->next;
   return (int)n->data;
    
}

int main()
{
    struct TList *t;
    struct node *n;
     init(&t);
     char x[10] ="a",y[10]="c",z[10]="b";
     add(t,0,x);
     add(t,1,y);
     add(t,2,z);
     printf("%d\n",length(t));
   print_string_list(t);
  Remove(t,1);
  printf("\n");
  printf("%d\n",length(t));
   print_string_list(t);
}
