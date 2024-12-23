#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int p=*a;
	*a=*b;
	*b=p;
}
int less(int x,int y)
{
	return (x>y)?1:0;
}
int greater(int x,int y)
{
	return (x<y)?1:0;
}
void sort(int *a,int n,int (*p)(int,int)) 
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(p(a[j],a[j+1])) swap(&a[j],&a[j+1]);
		}
	}
	return;
}
int main()
{
	int a[105];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a,n,less);//输入less，从小到大，输入greater，从大到小 
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	
	return 0;
}


