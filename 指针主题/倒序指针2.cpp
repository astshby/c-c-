#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void re(char* begin,char* end)//��ת���� 
{
	int cishu=(end-begin+1)/2;//��while���� 
	for(int i=0;i<cishu;i++) 
	{
		char p=*begin;
		*begin=*end;
		*end=p;
		begin++,end--;
	}
}
int main()
{
	char *str=(char*)malloc(128);
	int i=0;
	char ch;
	while((ch=getchar())!='\n') str[i++]=ch;//str������ϣ����¿�����Ϊ����
	*(str+i)='\0';//����str[i]='\0'��һ��Ҫ�� 
	re(str,str+i-1);
	char *begin=str,*end=str;
	while (*end!='\0')
	{
		if(*end==' ') 
		{
			re(begin,end-1);
			end++;
			begin=end;
		}
		else end++;
	}
	printf("%s",str);
	free(str); 
	return 0;
}


