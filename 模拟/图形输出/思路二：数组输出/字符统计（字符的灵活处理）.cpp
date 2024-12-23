#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cun[27][2];
char shuchu[1005][200];
//27表示字母，0是大写，1是小写 

void f1(int hang,int lie,int shu,int what)
{
	shuchu[hang][lie]=what-1+'A';
	for(int i=hang-1;i>=1;i--)
	{
		if(shu>0) shuchu[i][lie]='*',shu--;
		else shuchu[i][lie]=' ';
	}
	return;
}
void f2(int hang,int lie,int shu,int what)
{
	shuchu[hang][lie]=what-1+'a';
	for(int i=hang-1;i>=1;i--)
	{
		if(shu>0) shuchu[i][lie]='*',shu--;
		else shuchu[i][lie]=' ';
	}
	return;
}
void f3(int hang,int lie)
{
	for(int i=hang;i>=1;i--) shuchu[i][lie]=' ';
	return ;
}
int main()
{
/*freopen("C:\\Users\\LENOVO\\Desktop\\in.txt","r",stdin);
freopen("C:\\Users\\LENOVO\\Desktop\\out.txt","w",stdout);*/
	char a[1005];
	gets(a);
	int max=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='A'&&a[i]<='Z') 
		{
			cun[a[i]-'A'+1][0]++;
			if(max<cun[a[i]-'A'+1][0]) max=cun[a[i]-'A'+1][0];
		}
		else if(a[i]>='a'&&a[i]<='z') 
		{
			cun[a[i]-'a'+1][1]++;
			if(max<cun[a[i]-'a'+1][1]) max=cun[a[i]-'a'+1][1];
		}
	}
	
	int hang=max+1,lie=0;
	for(int i=1;i<=26;i++)
	{
		int flag=0; 
		if(cun[i][0]) flag=1,lie++,f1(hang,lie,cun[i][0],i);
		if(cun[i][1]) flag=1,lie++,f2(hang,lie,cun[i][1],i);
		
		if(flag==1) lie++,f3(hang,lie);
	}
	for(int i=1;i<=hang;i++)
	{
		for(int j=1;j<=lie;j++) printf("%c",shuchu[i][j]);
		printf("\n");
	}
	return 0;
}


