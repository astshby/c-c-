//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100],*p=a,*str=a;
	gets(a);
	while(*p!='\0') p++;
	cout<<p-str;
	
	//system("pause");
	return 0;
}


