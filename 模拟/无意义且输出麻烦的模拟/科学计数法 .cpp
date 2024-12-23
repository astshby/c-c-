#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void input(char *k)
{
	char nb;
	int i=0;
	while((nb=getchar())!='\n') k[i++]=nb;
	k[i]='\0';
	return;
}
void qianyi(char *k)
{
	int lenk=strlen(k);
	int i;
	for(i=1;i<lenk;i++) k[i-1]=k[i];
	k[i-1]='\0';
	return;
	
}
int shuzi(char *k,int wei)
{
	int quan=1,fanhui=0;
	int changdu=strlen(k);
	for(int i=changdu-1;i>=wei;i--)
	{
		if(k[i]==' ') continue;
		else
		{
			fanhui=fanhui+quan*(k[i]-'0');
			quan=quan*10;
		}
	}
	return fanhui;
}
void output(char *k,int shu,int position)
{
	int Q0=0;
	while(k[Q0]=='0') Q0++;
	//小心前导0 
	
	if(position==0) printf("0");
	int len=strlen(k);
	for(int i=Q0;i<=position;i++) printf("%c",k[i]);
	int yu=len-(position+1);
	if(yu>=8) for(int i=position+1;i<=position+8;i++) printf("%c",k[i]);
	else 
	{
		for(int i=position+1;i<len;i++) printf("%c",k[i]);
		for(int i=1;i<=(8-yu);i++) printf("0");
	}
	printf("\n");
	return ;
}
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	char a[105]={0},zi[105]={0};
	int popoint,ifpoint=0;
	input(a);
	int lena=strlen(a);
	int kks=0;
	int shuchufu=0;
	if(a[0]=='-') 
	{
		shuchufu=1;
		qianyi(a);
	}
	else shuchufu=0;
	
	if(a[0]=='0') qianyi(a);
	for(int i=0;i<lena;i++)
	{
		if(a[i]=='.') popoint=i,ifpoint=1;
		
		if(a[i]>='0'&&a[i]<='9'||a[i]=='.') zi[i]=a[i];
		else  
		{
			zi[i]='\0';
			kks=i;
			break;
		}
	}
	
	if(ifpoint==0) 
	{
		int sbsb=strlen(zi);
		zi[sbsb]='.';
		popoint=sbsb;
		zi[sbsb+1]='\0';
	}
	
	int iffu=0;
	for(int i=kks;i<=lena;i++)
	{
		if(a[i]=='-'||(a[i]>='0'&&a[i]<='9')) 
		{
			if(a[i]=='-')
			{
				iffu=1,kks=i+1;break;
			} 
			else
			{
				kks=i;
				break;
			}	
		}	
	}
	int shu=shuzi(a,kks);
	
	if(iffu==0&&shu!=0)
	{
		int lenzi=strlen(zi);
		int yu=lenzi-(popoint+1);
		if(yu>=shu) 
		{
			while(shu--)
			{
				char k=zi[popoint];
				zi[popoint]=zi[popoint+1],zi[popoint+1]=k;
				popoint++;
			}
		}
		else
		{
			int wei0=shu-yu;
			while(yu--)
			{
				char k=zi[popoint];
				zi[popoint]=zi[popoint+1],zi[popoint+1]=k;
				popoint++;
			}
			while(wei0--)
			{
				zi[popoint]='0',popoint++;
			}
			zi[popoint]='.';
			zi[popoint+1]='\0';
		}	
		
	}
	else if(iffu==1&&shu!=0)
	{
		int lenzi=strlen(zi);
		int yu=popoint;
		if(yu>=shu)
		{
			while(shu--)
			{
				char k=zi[popoint];
				zi[popoint]=zi[popoint-1],zi[popoint-1]=k;
				popoint--;
			}
		}
		else
		{
			int wei0=shu-yu;
			while(yu--)
			{
				char k=zi[popoint];
				zi[popoint]=zi[popoint-1],zi[popoint-1]=k;
				popoint--;
			}
			for(int i=lenzi;i>0;i--) zi[i+wei0]=zi[i];
			for(int i=1;i<=wei0;i++) zi[i]='0';
		}
	}
	
	if(shuchufu==1) printf("-");
	output(zi,shu,popoint);
	
	return 0;
}


