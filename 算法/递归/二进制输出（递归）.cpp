#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cunchun[40]={0};
int abs(int n)
{
	if(n>=0) return n;
	else return -n;
}
void yuanma(int a,int i)
{
	cunchun[i]=a%2;
	if(a!=1) i++,yuanma(a/2,i);
	else return;
}
void fanma()
{
		for(int i=1;i<=31;i++)
	{
		if(cunchun[i]==0) cunchun[i]=1;
		else cunchun[i]=0;
	}
}
void buma(int i)
{
	if(cunchun[i]==0) 
	{
		cunchun[i]=1;
		return;
	}
	else if(cunchun[i]==1) cunchun[i]=0,i++,buma(i);
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		printf("%d\n",n);
		return 0;
	} 
	else if(n==-2147483648)
	{
		printf("0\n");
	}//int -2的15次方到2的15次方-1，计算机内部与我们实际计算不同 
	else if(n<0) cunchun[32]=1;
	else cunchun[32]=0;
	
	yuanma(abs(n),1);
	if(n<0)
	{
		fanma();
		buma(1);
	}
	int ans=0;
	for(int i=1;i<=32;i++) if(cunchun[i]==1) ans++;
	printf("%d\n",ans);
	
	return 0;
}


