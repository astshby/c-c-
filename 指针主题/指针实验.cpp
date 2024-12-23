#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
//	char *a;
//	scanf("%s",a);
//	printf("%s\n",a);  
//	
//	char *b;
//	cin>>b;
//	printf("%s\n",b);
//	
//	char c;
//	gets(c);
//	printf("%s\n",c);   都没有申明空指针 
	
	char *d= (char*)malloc(32) ;
	//scanf("%s",d);
	//printf("%s\n",d); //无法读入空格 
	
	//gets(d);
	//printf("%s\n",d);//gcc下可能无法运行 
	int i=0; 
	char kk;
	while((kk=getchar())!='\n') *(d+(i++))=kk;
	//正确用法，但注意加'\0'结束
	*(d+i)='\0';
	printf("%s\n",d);  
	
	char *p="assholepint";
	//char b[89]=p; 反向不可 
	char *begin=p; 
	while(*p!='\0') printf("%c",*p++);
	printf("\n");
	for(int i=0;i<11;i++) printf("%c",begin[i]);
	//不能改写p，但可以输出
	//数组不能使用"a++"，指针可以，且指针可以"a++" 
//	for(int i=0;i<11;i++) begin[i]='0';
//	for(int i=0;i<11;i++) printf("%c",begin[i]);
// 不能赋值，已经指向一个只读字符串 
	
	
	return 0;
}


