#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void re(char* begin,char* end)//反转函数 
{
	int cishu=(end-begin+1)/2;//用while更好 
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
	while((ch=getchar())!='\n') str[i++]=ch;//str申请完毕，以下可以视为数组
	*(str+i)='\0';//或者str[i]='\0'，一定要加 
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


