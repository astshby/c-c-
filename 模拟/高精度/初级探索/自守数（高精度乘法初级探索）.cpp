#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ans5[105]={0,5},ans6[105]={0,6};
int cun5[105]={0,2},cun6[105]={0,3};
void input5(int n)
{
	for(int i=n;i>=1;i--) printf("%d",ans5[i]);
	printf("\n");
	return;
}
void input6(int n)
{
	for(int i=n;i>=1;i--) printf("%d",ans6[i]);
	printf("\n");
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=100;i++)
	{
		int boolen=0;
		for(int j=1;j<=9;j++)
		{
			int zan=0;
			ans5[i]=j;
			for(int k=1;k<=i;k++) zan=zan+ans5[k]*ans5[i+1-k];
			zan=zan+cun5[i-1];
			if((zan%10)==j)
			{
				ans5[i]=j,cun5[i]=zan/10;
				boolen=1;
				break;
			} 
			else ans5[i]=0;
		}
		if(boolen==0) //ע�⣬ans==0ʱҲҪ�д洢��λ�� 
		{
			int kks=0;
			for(int k=1;k<=i;k++) kks=kks+ans5[k]*ans5[i+1-k];
			kks=kks+cun5[i-1];
			cun5[i]=kks/10;
		}
	}
//��ĩλ��=6�����ظ����� 
	for(int i=2;i<=100;i++)
	{
		int boolen=0;
		for(int j=1;j<=9;j++)
		{
			int zan=0;
			ans6[i]=j;
			for(int k=1;k<=i;k++) zan=zan+ans6[k]*ans6[i+1-k];
			zan=zan+cun6[i-1];
			if((zan%10)==j)
			{
				ans6[i]=j,cun6[i]=zan/10;
				boolen=1;
				break;
			} 
			else ans6[i]=0;
		}
		if(boolen==0) 
		{
			int kks=0;
			for(int k=1;k<=i;k++) kks=kks+ans6[k]*ans6[i+1-k];
			kks=kks+cun6[i-1];
			cun6[i]=kks/10;
		}
	}
	
	if(n==1) printf("1\n5\n6\n");
	else
	{
		int boolen=1;
		if(ans5[n]==0&&ans6[n]==0) printf("\n");
		else if(ans5[n]==0&&ans6[n]!=0) input6(n);
		else if(ans5[n]!=0&&ans6[n]==0) input5(n);
		else if(ans5[n]<=ans6[n])
		{
			input5(n);
			input6(n);
		}
		else if(ans5[n]>ans6[n])
		{
			input6(n);
			input5(n);
		}
		
	 } 
	 
	 //˼·��ĩλ��ˣ��洢ÿ�γ˳��Ľ�λ����Ȼ����бȽϣ���0������
	 //���������ۣ�nλ���Ӻ�=10��n�η�+1�������n=1���������������� 
	return 0;
}


