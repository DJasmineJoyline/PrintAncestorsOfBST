#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
int printAncestor(struct node *,int);
void insert(struct node **,int);
void display(struct node *); 
int main()
{
int d,e;
char ch[10];
struct node *root=NULL;
do
{
printf("Enter the element to be inserted\n");
scanf("%d",&d);
insert(&root,d);
printf("Do you want to insert another element\n");
scanf("%s",ch);
}while(!strcmp(ch,"Yes"));
printf("The elements are");
display(root); 
printf("\n");
do{
printf("Enter the element to find its ancestor\n");
scanf("%d",&e);
printAncestor(root,e);
printf("\n");
printf("Do you want to find the ancestor of another element\n");
scanf("%s",ch);
}while(!strcmp(ch,"Yes"));
return 0;
}
void insert(struct node **root,int data)
{
struct node * n= (struct node*)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;

if(*root==NULL)
{
*root=n;
}
else
{
struct node *temp,*prev;
temp=*root;
while(temp!=NULL)
{
prev=temp;
if(temp->data>data)
{
temp=temp->left;
}
else
{
temp=temp->right;
}
}
if((prev->data)>data)
{
prev->left=n;
}
else
{
prev->right=n;
} 
}
}
void display(struct node *s) 
{
if(s!=NULL)
{

  display(s->left);
  printf(" %d",s->data);
  display(s->right);
}
}
int printAncestor(struct node *root,int key)
{

struct node *temp;
if(root->data>key)
{
    temp=root;
    printAncestor(root->left,key);
    printf(" %d",temp->data);
}
else if(root->data<key)
{
    temp=root;
    printAncestor(root->right,key);
    printf(" %d",temp->data);
}
return 0;

}
