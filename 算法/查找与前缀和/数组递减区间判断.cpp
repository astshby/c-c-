#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n;
	int ans[10005]={0};
	int tl,tr;//����tl��tr�洢ѭ��ʱ��λ�� 
	int cnt=1;//cnt��ʾ��ֵ����¼����֤����������ǰ�� 
	int l=1,r=1;//����l��r�洢ʵ�ʵ�λ�ã�
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ans[i]);
	for(int i=1;i<=n;i++)
	{
		tl=i,tr=i;
		while(tr<n)
		{
			if(ans[tr]>=ans[tr+1]) tr++;
			else break;
		}
		if((tr-tl+1)>cnt) 
		{
			cnt=tr-tl+1;
			l=tl,r=tr;
		}
		
		if(cnt>(n-i+1))  break;//��֦ 
		
	}
	printf("%d %d\n",l,r);
	
	return 0;
}


