#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
const int N=21;//一共20层 
int test(int a[N][N],int j,int k)
{
    int stack[N+1]={0};//栈，存储可能走的路径 
    int visited[N+1]={0};//防止多次遍历 
    int top=1;//栈顶 
    stack[top]=j;//初始进栈 
    visited[j]=1;//初始走过 
    int now,i;//存储出栈值 
    while (top>0){
        now=stack[top];
		top--;//先出栈 
        for(i=1;i<N;i++) 
            if(a[now][i]==1&&visited[i]==0)
            {	//如果在now上，有多个未访问值，均入栈替换now 
				top++;
                stack[top]=i;
                visited[i]=1;
                if(i==k) return 1;      
            }
        //栈内有值，就循环访问，知道全部出栈或者中间走到k 
    }
    return 0;
}

int main()
{
	int n,m;
	int a[N][N]={0};
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		a[i][j]=a[j][i]=1;
	}	
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int j,k;
		scanf("%d%d",&j,&k);
		if(test(a,j,k)) printf("%d-%d,yes\n",j,k);
		else printf("%d-%d,no\n",j,k);
	}
	return 0;
}


