#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
const int N=21;//һ��20�� 
int test(int a[N][N],int j,int k)
{
    int stack[N+1]={0};//ջ���洢�����ߵ�·�� 
    int visited[N+1]={0};//��ֹ��α��� 
    int top=1;//ջ�� 
    stack[top]=j;//��ʼ��ջ 
    visited[j]=1;//��ʼ�߹� 
    int now,i;//�洢��ջֵ 
    while (top>0){
        now=stack[top];
		top--;//�ȳ�ջ 
        for(i=1;i<N;i++) 
            if(a[now][i]==1&&visited[i]==0)
            {	//�����now�ϣ��ж��δ����ֵ������ջ�滻now 
				top++;
                stack[top]=i;
                visited[i]=1;
                if(i==k) return 1;      
            }
        //ջ����ֵ����ѭ�����ʣ�֪��ȫ����ջ�����м��ߵ�k 
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


