#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long ans; 
void hannuota(int n,char A,char B,char C)
//��A��C����תB 
{
	if(n==1) 
	{
		printf("move %d from %c to %c\n",n,A,C);
		ans++;
		return;
	}//n=1��ֱ����ʼ��Ŀ�� 
	else
	{
		//n>=2���Ȱ�n-1��A��B��תC����n��A�ƶ���C 
		//Ȼ��n-1��B��C��תA 
		hannuota(n-1,A,C,B);
		printf("move %d from %c to %c\n",n,A,C);
		ans++;
		hannuota(n-1,B,A,C);
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	hannuota(n,'a','b','c');
	printf("%d\n",ans);//2*n-1���� 
	return 0;
}


