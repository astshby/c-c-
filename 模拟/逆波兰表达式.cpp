#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct stake
{
	double shu[105];
	int gongji;
}cun;
//约为栈结构 
void input(char *k)
{
	int i=0;
	char ch; 
	while((ch=getchar())!='\n') *(k+(i++))=ch;
	*(k+i)='\0';
	return;
}
int turn(char *k,int *wei)
{
	int shu=0,i=0;
	char dang;
	while((dang=k[(*wei)+i])!=' ') shu=shu*10+dang-'0',i++;
	//从首位开始，每次ans先乘进制，在加下一个数（秦九韶算法） 
	(*wei)=(*wei)+i;
	return shu;
}

int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	char bo[105]={0};
	double ans=0;
	input(bo);
	int len=strlen(bo);
	cun.gongji=0;
	for(int i=0;i<len;i++)
	{
		if(bo[i]>='0'&&bo[i]<='9') 
		{
			int shu=turn(bo,&i);
			cun.shu[cun.gongji++]=shu;
		}
		else if(bo[i]=='+') 
		{
			cun.shu[cun.gongji-2]=cun.shu[cun.gongji-2]+cun.shu[cun.gongji-1];
			cun.shu[cun.gongji-1]=0;
			cun.gongji--;
		}
		else if(bo[i]=='-')
		{
			if(bo[i+1]>='0'&&bo[i+1]<='9')
			{
				i++;
				int shu=turn(bo,&i);
				cun.shu[cun.gongji++]=-1*shu;
			}
			//严谨判断 
			else
			{
				cun.shu[cun.gongji-2]=cun.shu[cun.gongji-2]-cun.shu[cun.gongji-1];
				cun.shu[cun.gongji-1]=0;
				cun.gongji--;
			}
			
		}
		else if(bo[i]=='*')
		{
			cun.shu[cun.gongji-2]=cun.shu[cun.gongji-2]*cun.shu[cun.gongji-1];
			cun.shu[cun.gongji-1]=0;
			cun.gongji--;
		}
		else if(bo[i]=='/')
		{
			cun.shu[cun.gongji-2]=cun.shu[cun.gongji-2]/cun.shu[cun.gongji-1];
			cun.shu[cun.gongji-1]=0;
			cun.gongji--;
		}
	}
	ans=cun.shu[cun.gongji-1];
	printf("%lf\n",ans);
	return 0;
}


