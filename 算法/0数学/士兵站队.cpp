#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int abs(int a)
{
	return (a>0)?a:-a;
}
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	return; 
}
int ksort(int a[],int n)
{
	for(int i=1;i<=n;i++)
	{
		int temp=i;
		for(int j=i+1;j<=n;j++)
		{
			if(a[temp]>a[j]) temp=j;
		}
		swap(&a[i],&a[temp]);
	}
	return a[(n+1)/2];
}
int main()
{
	int n;
	int x[10005]={0},y[10005]={0},x0[10005]={0};
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	int shu0=ksort(x,n);
	int shu2=ksort(y,n);
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i]-i+1;
	}
	int shu1=ksort(x,n);
	for(int i=1;i<=n;i++)
	{
		ans+=abs(x[i]-shu1);
		ans+=abs(y[i]-shu2);
	}
	printf("%lld\n",ans);
	return 0;
}


