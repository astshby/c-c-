#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int ans;
	char fd;
}k[100];
int cmp(const void* a,const void* b)
{
	return (((node*)a)->ans>((node*)b)->ans)?1:-1;
	//(node*)a���ټ�һ������((node*)a)��-> 
}
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&k[i].ans);
	qsort(k+1,n,sizeof(node),cmp);
	//+1���Դ��±�Ϊ1��ʼ 
	for(int i=1;i<=n;i++) printf("%d ",k[i].ans);
	return 0;
}


