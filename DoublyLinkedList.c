#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *prvs;
}Node;
Node *head=NULL,*p,*q;

int ReadNumberOfNode();
int ReadInput();
void AddNode(int x);
void display(Node *head);
int ReadDeletNode();
Node *DeletNode(int z,Node *head,int b);

int main(){int number,nbrNode,value;
nbrNode=ReadNumberOfNode();
for(int i=0;i<nbrNode;i++){
	number=ReadInput();
	AddNode(number);
}
display(head);

value=ReadDeletNode();
display(DeletNode(value,head,nbrNode));

}

int ReadNumberOfNode()
{int b;
  printf("enter the number of node: ");
  scanf("%d",&b);
  return b;
}

int ReadInput()
{int y;
  printf("enter number: ");
  scanf("%d",&y);
  return y;
}

void AddNode(int x){
  p=(Node*)malloc(sizeof(Node));
  p->data=x;
  if(head==NULL){
  	head=p;
  	p->next=NULL;
  	p->prvs=NULL;
  }else{
  	p->next=head;
  	head->prvs=p;
  	head=p;
  	p->prvs=NULL;
  }
}

void display(Node *head){
	p=head;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

int ReadDeletNode()
{int a;
  printf("Enter the node to be deleted: ");
  scanf("%d",&a);
  return a;
}

Node *DeletNode(int z,Node *head,int b){
  p=head;int count=0;
  while(p->data!=z){
  	count++;
  	p=p->next;
  }
  if(count==0){
  	q=head;
  	head=q->next;
  	free(q);
  }else{
  	if(count==b-1){
  		q=p->prvs;
  		q->next=NULL;
		free(p);
	}else{
		q=p->prvs;
  		q->next=p->next;
  		p->next->prvs=q;
		free(p);
	}
  }
  return head;
}
