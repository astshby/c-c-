#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int ans[105][105];
int len=1;
//�߾��ȣ�ans[][],��һλ��¼��ֵ���ڶ�λ��¼��λ
//ÿ�μӷ����ǽ�ÿһλ����ӣ��ڰ�ÿһλ��λһ�Σ���¼��λ 
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


