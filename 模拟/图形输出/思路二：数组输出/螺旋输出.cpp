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
	//���ң�y��1�����£�x��1
	//����y��1�����ϣ�x��1
	//��������dx��dy���ȿ��Ա������������ķ���
	//Ҳ���Թ�һ���������x��y�ļӼ� 
	int cnt=1;
	for(int i=1;i<=n*n;i++)
	{
		ans[x][y]=cnt++;//�ȸ�ֵ���ٶ�x,y�Ӽ�����ֹԽ�� 
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


