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
//	printf("%s\n",c);   ��û��������ָ�� 
	
	char *d= (char*)malloc(32) ;
	//scanf("%s",d);
	//printf("%s\n",d); //�޷�����ո� 
	
	//gets(d);
	//printf("%s\n",d);//gcc�¿����޷����� 
	int i=0; 
	char kk;
	while((kk=getchar())!='\n') *(d+(i++))=kk;
	//��ȷ�÷�����ע���'\0'����
	*(d+i)='\0';
	printf("%s\n",d);  
	
	char *p="assholepint";
	//char b[89]=p; ���򲻿� 
	char *begin=p; 
	while(*p!='\0') printf("%c",*p++);
	printf("\n");
	for(int i=0;i<11;i++) printf("%c",begin[i]);
	//���ܸ�дp�����������
	//���鲻��ʹ��"a++"��ָ����ԣ���ָ�����"a++" 
//	for(int i=0;i<11;i++) begin[i]='0';
//	for(int i=0;i<11;i++) printf("%c",begin[i]);
// ���ܸ�ֵ���Ѿ�ָ��һ��ֻ���ַ��� 
	
	
	return 0;
}


