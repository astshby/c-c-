#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n;
	int ans[10005]={0};
	int tl,tr;//利用tl，tr存储循环时的位置 
	int cnt=1;//cnt表示数值，记录并保证区间最大最靠近前面 
	int l=1,r=1;//利用l，r存储实际的位置，
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
		
		if(cnt>(n-i+1))  break;//减枝 
		
	}
	printf("%d %d\n",l,r);
	
	return 0;
}


