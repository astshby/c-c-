//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100],*p,*s,c;
	gets(a);
	p=s=a;
	while(*p!='\0') p++;
	p--;
	while(s<p)
	{
		c=*s;
		*s++=*p;
		*p--=c;

	}
	//或者用for循环 
	puts(a);
	//system("pause");
	return 0;
}

