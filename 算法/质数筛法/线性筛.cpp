#include<bits/stdc++.h>
using namespace std;
int p[100000005];//��¼���� 
bool t[100000005];//������� 
int n,tot;
int main()
{
	for(int i=2;i<=100000000;i++)
	{	
		if(t[i]==0) p[++tot]=i;
		for(int j=1;p[j]*i<=100000000&&j<=tot;j++)
		{
			t[p[j]*i]=1;
			if(i%p[j]==0) break;//��ֹ�ظ�ɸ�� 
		}
	}
	while(cin>>n) cout<<p[n]<<endl;
	return 0;
}

