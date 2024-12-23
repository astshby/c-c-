#include<bits/stdc++.h>
using namespace std;
bool a[10000005];
int t[10000005];
int n,tot=0;
int main()
{
	for(int i=2;i<=10000000;i++)
	{
		if(a[i]==0) 
		{
			t[++tot]=i;	
		}
		for(int j=i+i;j<=10000000;j=j+i) a[j]=1;
	}
	while(cin>>n) cout<<t[n]<<endl;

	return 0;
}

