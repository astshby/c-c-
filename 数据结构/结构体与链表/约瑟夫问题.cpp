#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int no;
	struct node *link;
}Node;
Node* create(int n)
{
	Node *head=(Node*) malloc(sizeof(Node));
	head->link=head;
	for(int i=n;i>0;i--)
	{
		Node *p=(Node*) malloc(sizeof(Node));//非原来，新申请的 
		p->no=i;
		p->link=head->link;
		head->link=p;
	}
	Node *p=head->link;
	while(p->link!=head) p=p->link;
	p->link=head->link;
	return head;
} 
int main()
{
	int people,hao;//hao<people,people为偶数 
	scanf("%d%d",&people,&hao);
	Node *head=create(people);
	Node *p=head->link;
	for(int i=1;i<=people/2;i++) 
	{
		for(int i=1;i<hao-1;i++) p=p->link;
		Node* si=p->link;
		printf("kill %d\n",si->no);
		p->link=si->link;
		p=p->link;
		if(si==NULL) free(si);
	}
	return 0;
}


