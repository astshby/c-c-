#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
void fuzhi(char **s)
{
	*s=(char *)malloc(sizeof(char)*128);
	return;
}
int main()
{
	char *p=NULL;
	fuzhi(&p);//�޸�Ҫ���͵�ַ 
	strcpy(p,"I love *and&");
	printf("%s\n",p); 
	return 0;
}


