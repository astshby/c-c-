#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//��Ŀ��1*1,2*2��3*n��ש 
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	int n;
	scanf("%d",&n);
	long long kks[105]={0};
	kks[1]=1,kks[2]=3,kks[3]=5;
	for(int i=4;i<=n;i++)
	{
		if(i%2==1) kks[i]=kks[i-1]*2+1;
		else kks[i]=kks[i-1]*2-1;
	}
	printf("����%lld�ַ�����\n",kks[n]);
	return 0;
}


