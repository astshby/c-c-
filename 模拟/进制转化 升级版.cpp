#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long pown(int shu,int mi)//pow����дΪpown�����Լ�д 
{
	long long ans=1;
	for(int i=mi;i>0;i--) ans=ans*shu;
	return ans;
} 
int len(char *ans) //�����볤�� 
{
	int k=0;
	while(ans[k]) k++;
	return k;
}
int zhuan(int n,char a[],int ans[])//�ַ�תΪ���� 
{
	int temp;
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9') ans[i]=a[i]-'0';
		else if(a[i]>='A'&&a[i]<='Z') ans[i]=a[i]-'A'+10;
		
		if(i==0) temp=ans[i];
		else
		{
			if(ans[i]>temp) temp=ans[i];
		}
	}
	return temp+1;
}
void fan(int a[],int n) //��ת���ڼ��� 
{
	for(int i=0;i<n/2;i++)//��ס���� 
	{
		int temp;
		temp=a[i],a[i]=a[n-(i+1)],a[n-(i+1)]=temp;
	}
	return;
}
void jinzhi(long long aans[],int min,int n,int shu[])//������� 
{
	for(int i=min;i<=36;i++)
	{
		long long ans=0; 
		for(int j=0;j<n;j++)
		{
			ans=ans+shu[j]*pown(i,j);
		}
		aans[i]=ans;
	}
}
int main()
{
	char a[100],b[100];
	int ashu[100]={0},bshu[100]={0};
	scanf("%s %s",a,b);
	int an=len(a);//xnΪ���ȣ�0��ʼ�� 
	int bn=len(b);
	int amin=zhuan(an,a,ashu);//maxΪ��С��λ,תΪ���� 
	int bmin=zhuan(bn,b,bshu);
	fan(ashu,an);//��ת 
	fan(bshu,bn);
	
	long long aans[40]={0},bans[40]={0};//�����amin��36�����н��Ƶ�ֵ 
	jinzhi(aans,amin,an,ashu);
	jinzhi(bans,bmin,bn,bshu);
	
	int boole=0;
	for(int i=amin;i<=36&&boole==0;i++)
	{
		for(int j=bmin;j<=36;j++)
		{
			if(aans[i]<bans[j]) break;
			
			if(aans[i]==bans[j]) 
			{
				printf("%s (base %d) = %s (base %d)\n",a,i,b,j);
				boole=1;
				break;
			}
		}
	}
	
	if(boole==0) printf("%s is not equal to %s in any base 2..36\n",a,b);
	return 0;
}


