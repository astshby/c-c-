#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int jie[6]={1,2,4,8,16,32};
char base64[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
void ejz(int *er,int str)
{
	for(int i=0;i<8;i++)
	{
		er[7-i]=str%2;
		str=str/2;
	}
	return ;
}
int f(int qi,int *k)
{
	int b=0;
	int ans=0;
	int bbb[6]={0};
	for(int i=qi;i<qi+6;i++) bbb[b++]=k[i];
	for(int i=0;i<6;i++)
	{
		ans=ans+bbb[5-i]*jie[i];
	}
	return ans;
}
int main()
{
	char a[105]={0};
	int cun[840]={0};
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		int er[8]={0};
		int k=(int)a[i];
		ejz(er,k);
		for(int j=0;j<8;j++) cun[i*8+j]=er[j];
	} 
	for(int i=0;i<len*8;i+=6)
	{
		int kks=0;
		kks=f(i,cun);
		printf("%c",base64[kks]);
	}
	if(len%3==1) printf("==\n");
	else if(len%3==2) printf("=\n");
	else printf("\n");
	
	return 0;
}


