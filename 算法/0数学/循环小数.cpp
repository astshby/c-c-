#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int shou,mo,flag;
int ans[10005];
//记录循环的首位和末尾以及是否可除尽 
void xunhuan(int n, int m)
{
	int beichu[10005]={n,0},yu[10005]={0};
	//beichu保存下一位余数对应的被除数，yu保存余数 
	//始终用数组比较方便 
	for(int i=1;shou==0&&mo==0;i++)
	{
		if(i>10000) 
		{
			flag=2,mo=i;break;
			//100位还找不到，那算了 
		}
		 
		yu[i]=beichu[i-1]*10/m;
		beichu[i]=beichu[i-1]*10%m;
		
		if(beichu[i]==0) 
		{
			flag=1,shou=1,mo=i;
			break; 
		}
		//注意：余数可能是0，但被除数是0一定结束
		 
		for(int j=0;j<i;j++)
		{
			if(beichu[j]==beichu[i])
			{
				flag=0,shou=j+1,mo=i;
				break;
			}
		}
		//思路：找到被除数相等，就循环了 
		//重点：被除数相等 
	}
	
	for(int i=0;i<=mo;i++) ans[i]=yu[i];
	return;
}
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	int n,m;
	scanf("%d%d",&n,&m);
	//保证n<m 
	xunhuan(n,m);
	if(flag==1)
	{
		printf("有限小数\n");
		printf("%d.",ans[0]);
		for(int i=1;i<=mo;i++) printf("%d",ans[i]);
		printf("\n");
	}
	else if(flag==0) 
	{
		printf("无限循环小数,循环节长度为%d\n",mo-shou+1);
		printf("%d.",ans[0]);
		for(int i=1;i<shou;i++) printf("%d",ans[i]);
		printf("*");
		for(int i=shou;i<=mo;i++) printf("%d",ans[i]);
		printf("*\n");
	}
	else 
	{
		printf("10000位以内无限不循环\n");
		printf("%d.",ans[0]);
		for(int i=1;i<=mo;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}


