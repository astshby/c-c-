#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[105][15];
	int n;
	char *p[105];
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		scanf("%s",a+i);
		p[i]=(char*) malloc(sizeof(char*)*15);
		p[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		int temp=i;
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(p[j],p[temp])>0) temp=j;
		}
		char *kks=p[temp];
		p[temp]=p[i];
		p[i]=kks;
	}
	for(int i=0;i<n;i++) printf("%s\n",p[i]);
	return 0;
}


