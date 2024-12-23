//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n;
	char ch,ch1,ch2;
	scanf("%d %c",&n,&ch);
	ch1=ch2=ch;
	for(j=1;j<=4*n-5;j++)
	{
		ch2++;
		if(ch2>'Z') ch2='A';
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++) printf(" ");
		for(j=1;j<=2*i-1;j++)
		{
			if(j==1||i==n) 
			{
				printf("%c",ch1++);	
				if(ch1>'Z') ch1='A'; 
			}
			else if(j==2*i-1) 
			{
				printf("%c",ch2--);
				if(ch2<'A') ch2='Z'; 
			}
			else printf(" ");
			
			//三角形终止到输入最后一个即可 
		}
		printf("\n"); 
	}
	//system("pause");
	return 0;
}


