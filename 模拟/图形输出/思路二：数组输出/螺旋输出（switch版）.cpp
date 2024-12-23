#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[100][100];
int main()
{
	int n; 
	scanf("%d",&n);
	int x=1,y=0;
	//向右：y加1，向下：x加1
	//向左：y减1，向上：x减1
	int ans=1; 
	int cnt=1;
	for(int i=1;i<=n*n;i++)
	{
		switch(ans)
		{
			case 1:
				a[x][++y]=cnt++;
				if(a[x][y+1]!=0||y>=n) ans=2;
				break;
			case 2:
				a[++x][y]=cnt++;
				if(a[x+1][y]!=0||x>=n) ans=3;
				break;
			case 3:
				a[x][--y]=cnt++;
				if(a[x][y-1]!=0||y<=1) ans=4;
				break;
			case 4:
				a[--x][y]=cnt++;
				if(a[x-1][y]!=0||x<=1) ans=1;
				break;		
		}
			
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%3d",a[i][j]) ;
		}
		printf("\n");
	}
	
	return 0;
}


