#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int no;
	struct node *link;
}Node;
//voidҪ��ָ���ָ��Ϳ��ǽ����
//���첢�������� 
Node* create(int n,Node *head)
{
	head=(Node*) malloc(sizeof(Node));
	head->link=NULL;
	for(int i=n;i>0;i--)
	{
		Node *p=(Node*) malloc(sizeof(Node));//��ԭ����������� 
		scanf("%d",&p->no);
		p->link=head->link;
		head->link=p;
	}
	return head;
} 
//������� 
//����˳���󳤶�
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
//���������ֵ
void insert(int n,int i,Node *head)
{
	Node *p=head->link;
	//������һ��ָ�룬ָ��ǰλ�ã�δ�����ڴ� �������Զ�Ӧ�ڴ� 
	//p->link��Ӧ��һλָ�루����--i��
	//p��Ӧ��һλָ�� 
	if(p==NULL)
	{
		Node *q=(Node*) malloc(sizeof(Node));
		scanf("%d",&q->no);
		q->link=head->link;
		head->link=q;
		return;
	}//���������,�б�ͷ���� 
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
		//���ߵȼۣ���p��NULL��n--ʱp==NULL��p->link������ 
		Node *q=(Node*) malloc(sizeof(Node));
		scanf("%d",&q->no);
		q->link=p->link;
		p->link=q;
		return;
	} 
}
//ɾ�������ֵ
void deletelink(int i,Node *head)
{
	Node *p=head->link;
	i--;
	while(--i) p=p->link;//pָ��i-1λָ�� 
	Node *pp=p->link;//ppָ��iλָ�룬pp->linkָ��i+1λָ��
	p->link=pp->link;
	if(pp==NULL) free(pp);//�˵���free������ 
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
//��Ҫ��˭���ӣ�˭�ᱣ���ҵ����ӡ�������ʱ��ǰһ�� 


