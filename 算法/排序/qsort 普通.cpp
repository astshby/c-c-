#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	return (*(double*)a>*(double*)b)?1:-1;
	//ǿ������ת��Ϊ��ͬ��ʽ��a>b����һ������>�ڶ������֣�����1��ʾ��С��������
	//�����ԣ�double���У�дΪ *(int*)a-*(int*)b��������ͬ 
 } 
int main()
{
	//qsort(������Ĭ��0��ʼ�����������ͣ�sizeof(int)����cmp)
	//cmpд�������� 
	int n;
	double ans[105]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&ans[i]);
	qsort(ans+1,n,sizeof(double),cmp);
	//+1���Դ��±�Ϊ1��ʼ 
	for(int i=1;i<=n;i++) printf("%lf ",ans[i]);
	printf("\n");
	return 0;
}


