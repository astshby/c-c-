#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a[3][4]={0};
	//&a:整个地址
	//a:首行地址,*a首行第一个元素的地址(约=a[0]),**a第0行第0个元素的值
	//a[0]：首行所有元素，很少直接用 
	//中括号有取值的意思 
	int (*p)[4]=a;//赋值第一行，p+1指向下一行 ,p==a
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) scanf("%d",*(a+i)+j);
	 }
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) printf("%d ",*(a[i]+j));
		//等价printf("%d ",*(*(a+i)+j))
		printf("\n");
	}
	//以上为数组指针
	printf("\n"); 
	//以下为指针数组
	int *pa[3]={a[0],a[1],a[2]};//pa==a 
	//int *pa[3]={*a,*(a+1),*(a+2)}等价 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) printf("%d ",pa[i][j]);
		printf("\n");
	}
	return 0;
}


