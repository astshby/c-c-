//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char a;
	cin>>n>>a;
	for(int i=(-n+1);i<=(n-1);i++)//初始化时使用负数时其可以套用一个公式 
	{
		for(int j=1;j<=2*n-1;j++)
		{
			int k=(i>0)?i:-i;
			if(j<=k||j>=2*n-k) printf("%c",a);
			else printf(" ");
		}
		printf("\n");
	 } 
	//system("pause");
	return 0;
}


