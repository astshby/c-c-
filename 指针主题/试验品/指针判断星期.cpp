//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
char *week[]={"monday","tuesday","wednesday","thursday","friday","saterday","sunday",NULL};
void letlit(char* s)
{
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
		i++;
	}	
}
int look(char* s)
{
	int a;
	char *p;
	for(a=0;week[a]!=NULL;a++) //NULL是空指针，还是指针变量
	{
		int i;
		p=week[a];
		for(i=0;p[i]==s[i]&&s[i]!='\0'&&p[i]!='\0';i++) ;//虽然是空函数，但要学会使用指针加减 
		if(p[i]=='\0') return(a+1);
		//another:for(i=0;*p==s[i]&&s[i]!=0&&*p!=0;i++,p++) ;
		//        if(*p=='\0') return(a+1);
		//wrong:for(i=0;p[i]==s[i]&&s[i]!=0&&p[i]!=0;i++,p++) ;
		//		if(*p=='\0') return(a+1);
		//原因 
	} 
	return (-1);
}
int main()
{
	char str[20];
	gets(str);
	letlit(str);
	int ans=look(str);
	printf("%d\n",ans);
	//system("pause");
	return 0;
}


