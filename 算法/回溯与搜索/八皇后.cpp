#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int ans;
int hang[55],lie[55],youdj[55],zuodj[55];
//��ʾ���Ʒ�Χ
//i��ʾ�У�j��ʾ�� 
//��Խ������мӺ�Ϊ��ֵ���ҶԽ������в�ֵΪ��ֵ����Ϊ�˱��ⳬֵ�����������n 
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
			//���ڱ����ڣ����ı����� 
		}
	}
}
//дд˼·�����ȴӵ�һ�п�ʼ����һ��ÿһ��λ�ö����ã���n��������־ռ������жԽ� 
//��Ǻ������һ�У�ÿһ��λ���ж����ޱ�ǣ�û�еĻ��ͱ��Ͻ�����һ�� 
//ֱ��������������趨ֵn��ans++��������һ�� 
//����һ���ٶԽ���ǰ������λ�õ���һ������λ�ñ�ǣ����Ҳ��Ϸ���
//���磺 
//n=5���ȱ꣨1,1�����ٱ꣨2,3����3,5������4,2������5,4����֮�󷵻���i=2��j=4��ִ�� 
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


