#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	//&a��ʾ��������ĵ�ַ
	//a��ʾ���������Լ���λԪ�صĵĵ�ַ
	//*(a+i)��ʾ�����iλԪ�ص�ֵ
	//��������ȡֵ����˼  
	int a[10];
	for(int i=1;i<=5;i++) scanf("%d",a+i);
	for(int i=1;i<=5;i++) printf("%d",*(a+i));
	return 0;
}


