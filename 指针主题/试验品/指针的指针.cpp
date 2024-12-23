//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char *pc[]={"hby","ghz","chy","yqx","tmd","szh","zxy"};
	
	char *p1;
	int i1;
	for(i1=0;i1<7;i1++)
	{
		p1=pc[i1];//wrong:p=&(pc+i);pc本来就是一个地址 
		printf("%s\n",p1);
	}
	printf("\n");
	
	char **p2;
	int i2;
	for(i2=0;i2<7;i2++)
	{
		p2=pc+i2;//wrong:p2=&(pc+i2);pc本来就是一个地址 
		printf("%s\n",*p2);//用p2一定要解地址 
	} 
	//system("pause");
	return 0;
}


