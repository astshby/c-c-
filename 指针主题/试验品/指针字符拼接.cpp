//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std; 
char *knit(char *s1,char *s2)
{
	char *s=s1;
	while(*s1!='\0') s1++;
	//while(*s2!='\0') *s1=*s2,s2++,s1++;//û������'\0'
	while(*s1++=*s2++) ; //�պ���һ��Ҫѧ�ᣬ�˾��ʾ��ֵ��'\0'����Ϊֹ 
	return s;//wrong:return s1,�򷵻�ֵΪs1�����������ָ��ĵ�ַ����ԭ��ַ 
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


