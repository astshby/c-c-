#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	return (*(double*)a>*(double*)b)?1:-1;
	//强制类型转化为不同形式，a>b（第一个数字>第二个数字）返回1表示从小到大（升序）
	//还可以（double不行）写为 *(int*)a-*(int*)b，意义相同 
 } 
int main()
{
	//qsort(数组名默认0开始，个数，类型（sizeof(int)），cmp)
	//cmp写法：见上 
	int n;
	double ans[105]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&ans[i]);
	qsort(ans+1,n,sizeof(double),cmp);
	//+1可以从下标为1开始 
	for(int i=1;i<=n;i++) printf("%lf ",ans[i]);
	printf("\n");
	return 0;
}


