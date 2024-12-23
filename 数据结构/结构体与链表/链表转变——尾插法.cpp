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
	
	//以上不是头插法，是尾插法，关键是p很早就赋值为hd，之后一点一点后移
	//更方便，但应注意使用时应该提前定义，防止被更新 
	return 0;
}


