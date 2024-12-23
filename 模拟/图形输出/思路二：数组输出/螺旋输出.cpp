#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ans[100][100];
int main()
{
	int n; 
	scanf("%d",&n);
	int x=1,y=1;
	int dx=0,dy=1;
	//向右：y加1，向下：x加1
	//向左：y减1，向上：x减1
	//于是引用dx，dy，既可以表明现在所处的方向
	//也可以归一化代码对于x，y的加减 
	int cnt=1;
	for(int i=1;i<=n*n;i++)
	{
		ans[x][y]=cnt++;//先赋值，再对x,y加减，防止越界 
		x=x+dx;
		y=y+dy;
		if(dy==1&&(ans[x][y+1]!=0||y>=n))
		{
			dx=1,dy=0;
		}
		else if(dx==1&&(ans[x+1][y]!=0||x>=n))
		{
			dx=0,dy=-1;
		}
		else if(dy==-1&&(ans[x][y-1]!=0||y<=1))
		{
			dx=-1,dy=0;
		}
		else if(dx==-1&&(ans[x-1][y]!=0||x<=1))
		{
			dx=0,dy=1; 
		} 	
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%3d",ans[i][j]) ;
		}
		printf("\n");
	}
	
	return 0;
}


