#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int no;
	struct node *link;
}Node;
//void要用指针的指针和考虑结合性
//创造并输入链表 
Node* create(int n,Node *head)
{
	head=(Node*) malloc(sizeof(Node));
	head->link=NULL;
	for(int i=n;i>0;i--)
	{
		Node *p=(Node*) malloc(sizeof(Node));//非原来，新申请的 
		scanf("%d",&p->no);
		p->link=head->link;
		head->link=p;
	}
	return head;
} 
//输出链表 
//遍历顺便求长度
int out(Node *head)
{
	int ans=0;
	Node *p=head->link;
	while(p!=NULL)
	{
		printf("%d ",p->no);
		p=p->link;
		ans++;
	}
	return ans;
} 
//插入链表的值
void insert(int n,int i,Node *head)
{
	Node *p=head->link;
	//仅仅是一个指针，指向当前位置，未分配内存 ，但可以对应内存 
	//p->link对应下一位指针（所以--i）
	//p对应这一位指针 
	if(p==NULL)
	{
		Node *q=(Node*) malloc(sizeof(Node));
		scanf("%d",&q->no);
		q->link=head->link;
		head->link=q;
		return;
	}//处理空链表,有表头结点的 
	else if(i>n)
	{
		printf("i>n\n");
		Node *q=(Node*) malloc(sizeof(Node));
		scanf("%d",&q->no);
		q->link=p->link;
		p->link=q;
		return;
	}
	else
	{
		while(--i&&p->link!=NULL) p=p->link;
		//二者等价，但p！NULL与n--时p==NULL，p->link不存在 
		Node *q=(Node*) malloc(sizeof(Node));
		scanf("%d",&q->no);
		q->link=p->link;
		p->link=q;
		return;
	} 
}
//删除链表的值
void deletelink(int i,Node *head)
{
	Node *p=head->link;
	i--;
	while(--i) p=p->link;//p指向i-1位指针 
	Node *pp=p->link;//pp指向i位指针，pp->link指向i+1位指针
	p->link=pp->link;
	if(pp==NULL) free(pp);//此电脑free有问题 
	return ;
}
int main()
{
	int n,k;
	Node *head;
	scanf("%d%d",&n,&k);
	head=create(n,head);
	deletelink(k,head);
	int ans=out(head);
	return 0;
}
//我要和谁链接，谁会保存我的链接——单向时，前一个 


