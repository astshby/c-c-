#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int shou,mo,flag;
int ans[10005];
//��¼ѭ������λ��ĩβ�Լ��Ƿ�ɳ��� 
void xunhuan(int n, int m)
{
	int beichu[10005]={n,0},yu[10005]={0};
	//beichu������һλ������Ӧ�ı�������yu�������� 
	//ʼ��������ȽϷ��� 
	for(int i=1;shou==0&&mo==0;i++)
	{
		if(i>10000) 
		{
			flag=2,mo=i;break;
			//100λ���Ҳ����������� 
		}
		 
		yu[i]=beichu[i-1]*10/m;
		beichu[i]=beichu[i-1]*10%m;
		
		if(beichu[i]==0) 
		{
			flag=1,shou=1,mo=i;
			break; 
		}
		//ע�⣺����������0������������0һ������
		 
		for(int j=0;j<i;j++)
		{
			if(beichu[j]==beichu[i])
			{
				flag=0,shou=j+1,mo=i;
				break;
			}
		}
		//˼·���ҵ���������ȣ���ѭ���� 
		//�ص㣺��������� 
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
	//��֤n<m 
	xunhuan(n,m);
	if(flag==1)
	{
		printf("����С��\n");
		printf("%d.",ans[0]);
		for(int i=1;i<=mo;i++) printf("%d",ans[i]);
		printf("\n");
	}
	else if(flag==0) 
	{
		printf("����ѭ��С��,ѭ���ڳ���Ϊ%d\n",mo-shou+1);
		printf("%d.",ans[0]);
		for(int i=1;i<shou;i++) printf("%d",ans[i]);
		printf("*");
		for(int i=shou;i<=mo;i++) printf("%d",ans[i]);
		printf("*\n");
	}
	else 
	{
		printf("10000λ�������޲�ѭ��\n");
		printf("%d.",ans[0]);
		for(int i=1;i<=mo;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}


