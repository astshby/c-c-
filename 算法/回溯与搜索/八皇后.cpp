#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int ans;
int hang[55],lie[55],youdj[55],zuodj[55];
//表示控制范围
//i表示行，j表示列 
//左对角线行列加和为定值，右对角线行列差值为定值，右为了避免超值，所有坐标加n 
void dfs(int i,int n)
{
	if(i>n)
	{
		ans++;
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(lie[j]==0&&zuodj[i+j]==0&&youdj[i-j+n]==0)
		{
			hang[i]=1,lie[j]=1,zuodj[i+j]=1,youdj[i-j+n]=1;
			dfs(i+1,n);
			lie[j]=0,zuodj[i+j]=0,youdj[i-j+n]=0;
			//还在本行内，不改变行数 
		}
	}
}
//写写思路：首先从第一行开始，第一行每一个位置都放置（共n个），标志占领的行列对角 
//标记后进入下一行，每一个位置判断有无标记，没有的话就标上进入下一行 
//直到最后行数大于设定值n，ans++，返回上一个 
//而上一个再对进入前的所在位置的下一个可行位置标记，并且不断返回
//例如： 
//n=5，先标（1,1），再标（2,3）（3,5），（4,2），（5,4），之后返回至i=2，j=4再执行 
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	int n;
	scanf("%d",&n);
	dfs(1,n);
	printf("%d\n",ans);
	return 0;
}


