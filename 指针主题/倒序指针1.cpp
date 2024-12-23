#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char *a[100]={0};
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i]=(char*) malloc(128);
		scanf("%s",a[i]);//a代表指针数组的“不动指针” 
	}
	for(int i=n;i>=1;i--)
	{
		printf("%s ",a[i]); 
		free(a[i]);//注意释放 
	}
	printf("\n"); 
	
	
	return 0;
}


