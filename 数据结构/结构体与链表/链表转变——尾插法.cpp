#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int no;
	struct Node *link;
}node;
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	int n;
	scanf("%d",&n);
	node* hd=NULL;
	node *p=(node*)malloc(sizeof(node));
	p->link=NULL;
	hd=p;
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		p->link=(node*)malloc(sizeof(node));
		p->link->no=m;
		p->link->link=NULL;
		p=p->link;	
	}
	
	node *k=hd->link;
	for(int i=1;i<=n;i++)
	{	
		printf("%d ",k->no);
		k=k->link;
	}
	
	//���ϲ���ͷ�巨����β�巨���ؼ���p����͸�ֵΪhd��֮��һ��һ�����
	//�����㣬��Ӧע��ʹ��ʱӦ����ǰ���壬��ֹ������ 
	return 0;
}


