#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a[3][4]={0};
	//&a:������ַ
	//a:���е�ַ,*a���е�һ��Ԫ�صĵ�ַ(Լ=a[0]),**a��0�е�0��Ԫ�ص�ֵ
	//a[0]����������Ԫ�أ�����ֱ���� 
	//��������ȡֵ����˼ 
	int (*p)[4]=a;//��ֵ��һ�У�p+1ָ����һ�� ,p==a
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) scanf("%d",*(a+i)+j);
	 }
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) printf("%d ",*(a[i]+j));
		//�ȼ�printf("%d ",*(*(a+i)+j))
		printf("\n");
	}
	//����Ϊ����ָ��
	printf("\n"); 
	//����Ϊָ������
	int *pa[3]={a[0],a[1],a[2]};//pa==a 
	//int *pa[3]={*a,*(a+1),*(a+2)}�ȼ� 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++) printf("%d ",pa[i][j]);
		printf("\n");
	}
	return 0;
}


