#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	//&a表示整个数组的地址
	//a表示数组名字以及首位元素的的地址
	//*(a+i)表示数组第i位元素的值
	//中括号有取值的意思  
	int a[10];
	for(int i=1;i<=5;i++) scanf("%d",a+i);
	for(int i=1;i<=5;i++) printf("%d",*(a+i));
	return 0;
}


