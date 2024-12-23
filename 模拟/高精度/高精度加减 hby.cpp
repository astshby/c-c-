#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct shu
{
	char zi[505]={0};
	int shu[505]={0};
	int len;
}a,b,ans;
void fanzhuan(char *x,int *xn,int len)
{
	for(int i=0;i<len;i++) 
	{
		xn[len-i-1]=x[i]-'0';
	}
	return;
}
int max(int a,int b)
{
	return ((a>b)?a:b);
}
char chuli(char *ru)
{
	char fu;
	for(int i=0;i<strlen(ru);i++)
	{
		if(ru[i]>='0'&&ru[i]<='9') 
		{
			a.len++;
			a.zi[i]=ru[i];
		}
		else 
		{
			fu=ru[i];
			break;
		}
	}
	fanzhuan(a.zi,a.shu,a.len);
	for(int i=a.len+1;i<strlen(ru);i++)
	{
			b.zi[i-(a.len+1)]=ru[i];
			b.len++;
	}
	fanzhuan(b.zi,b.shu,b.len);
	return fu;
}
void freen(char *ru)
{
	for(int i=0;i<a.len;i++)
	{
		a.shu[i]=0;
		a.zi[i]='\0';
	}
	a.len=0;
	for(int i=0;i<b.len;i++)
	{
		b.shu[i]=0;
		b.zi[i]='\0';
	}
	b.len=0;
	for(int i=0;i<ans.len;i++)
	{
		ans.shu[i]=0;
		ans.zi[i]='\0';
	}
	ans.len=0;
	for(int i=0;i<strlen(ru);i++) ru[i]='\0';
	return;
}
int bijiao(int *ashu,int *bshu,int alen,int blen)
{
	int bbb=0;
	if(alen>blen) bbb=1;
	else if(alen<blen) bbb=-1;
	else
	{
		for(int i=alen-1;i>=0;i--)
		{
			if(ashu[i]>bshu[i]) 
			{
				bbb=1;
				break;
			}
			else if(ashu[i]<bshu[i]) 
			{
				bbb=-1;
				break;
			}
		}
	}
	return bbb;
}

void add(int *a,int *b,int *len,int *kks)
{
	for(int i=0;i<*len;i++)
	{
		kks[i]=a[i]+b[i];
	}
	for(int i=0;i<*len;i++)
	{
		if(kks[i]>9) kks[i+1]+=kks[i]/10;
		kks[i]=kks[i]%10;
	}
	if(kks[(*len)]!=0) (*len)++;
	return ;
}
void sub(int *a,int *b,int *len,int *kks)
{
	for(int i=0;i<*len;i++)
	{
		kks[i]=a[i]-b[i];
	}
	for(int i=0;i<*len-1;i++)
	{
		if(kks[i]<0) 
		{
			kks[i]=10+kks[i];
			kks[i+1]--;
		}
	}
	for(int i=*len-1;i>=0;i--)
	{
		if(kks[i]==0) (*len)--;
		else break;
	}
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		char ru[1010]={0};
		scanf("%s",ru);
		getchar();
		char fuhao=chuli(ru);
		if(fuhao=='+')
		{
			ans.len=max(a.len,b.len);
			add(a.shu,b.shu,&ans.len,ans.shu);
			for(int i=ans.len-1;i>=0;i--) printf("%d",ans.shu[i]);
			printf("\n");
			freen(ru);
		}
		else if(fuhao=='-')
		{
			int bo=bijiao(a.shu,b.shu,a.len,b.len);
			if(bo==0)
			{
				printf("%d\n",bo);
				freen(ru);
			}
			else if(bo>0)
			{
				ans.len=max(a.len,b.len);
				sub(a.shu,b.shu,&ans.len,ans.shu);
				for(int i=ans.len-1;i>=0;i--) printf("%d",ans.shu[i]);
				printf("\n");
				freen(ru);
			}
			else if(bo<0)
			{
				ans.len=max(a.len,b.len);
				sub(b.shu,a.shu,&ans.len,ans.shu);
				for(int i=ans.len-1;i>=0;i--) 
				{
					if(i==ans.len-1) printf("-");
					printf("%d",ans.shu[i]);
				}
				printf("\n");
				freen(ru);
			}
		}
	} 
	return 0;
}


