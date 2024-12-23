//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std; 
char *knit(char *s1,char *s2)
{
	char *s=s1;
	while(*s1!='\0') s1++;
	//while(*s2!='\0') *s1=*s2,s2++,s1++;//没有最后的'\0'
	while(*s1++=*s2++) ; //空函数一定要学会，此句表示赋值至'\0'出现为止 
	return s;//wrong:return s1,则返回值为s1经过多次运算指向的地址，非原地址 
}
int main()
{ 
	char a[50],b[50],*str;
	scanf("%s",a);
	scanf("%s",b);
	str=knit(a,b);
	puts(str);
	//system("pause");
	return 0;
}


