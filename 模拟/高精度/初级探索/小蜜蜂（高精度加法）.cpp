#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int ans[105][105];
int len=1;
//高精度：ans[][],第一位记录差值，第二位记录数位
//每次加法就是将每一位先相加，在把每一位进位一次，记录数位 
void pa(int x)
{
	for(int i=1;i<=len;i++)
	{
		ans[x][i]=ans[x-1][i]+ans[x-2][i];
	} 
	for(int i=1;i<=len;i++)
	{
		if(ans[x][i]>9) 
		{
			ans[x][i+1]=ans[x][i+1]+ans[x][i]/10;
			ans[x][i]=ans[x][i]%10;
		}
	}
	if(ans[x][len+1]!=0) len++;
	return;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ans[0][1]=0;
	ans[1][1]=1;
	ans[2][1]=2;
	for(int i=3;i<=m-n;i++) pa(i);
	for(int i=len;i>=1;i--) printf("%d",ans[m-n][i]);
	printf("\n");
	return 0;
}


