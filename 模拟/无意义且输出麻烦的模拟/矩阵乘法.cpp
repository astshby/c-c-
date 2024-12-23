#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct matrix
{
	int hang,lie;
	long long ma[105][105];
}a,b,ans;
void input(struct matrix *p)
{
	scanf("%d%d",&p->hang,&p->lie);
	for(int i=1;i<=p->hang;i++)
	{
		for(int j=1;j<=p->lie;j++) scanf("%lld",&p->ma[i][j]);
	}
	
}
void output(struct matrix p)
{
	printf("answer is:\n");
	printf("%d %d\n",p.hang,p.lie);
	for(int i=1;i<=p.hang;i++)
	{
		for(int j=1;j<=p.lie;j++) printf("%lld ",p.ma[i][j]);
		printf("\n");
	}
	
}
void mul(struct matrix a,struct matrix b,struct matrix *p)
{
	struct matrix kks;
	if(a.lie!=b.hang)
	{
		printf("No meaning\n");
		return;
	}
	else
	{
		int ci=a.lie;
		p->hang=a.hang,p->lie=b.lie;
		for(int i=1;i<=p->hang;i++)
		{
			for(int j=1;j<=p->lie;j++)
			{
				for(int k=1;k<=ci;k++) p->ma[i][j]+=a.ma[i][k]*b.ma[k][j];
			}
		}
	}
	return ; 
}
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	input(&a);
	input(&b);
	mul(a,b,&ans);
	output(ans);
	return 0;
}


