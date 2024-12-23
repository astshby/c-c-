#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cycle1(char *k,int chu,int mo)
{
	if(chu==mo) return 1;
	else
	{
		if(k[chu]==k[mo]&&cycle1(k,chu+1,mo-1)==1) return 1 ;
		else return 0;
	}
}
int cycle2(char *k,int chu,int mo)
{
	if(chu+1==mo)
	{
		if(k[chu]==k[mo]) return 1;
		else return 0;
	 } 
	 else
	 {
	 	if(k[chu]==k[mo]&&cycle2(k,chu+1,mo-1)==1) return 1;
		else return 0;
	 }
}
int main()
{
	char a[105];
	gets(a);
	if(a[0]=='\0'||a[0]=='\n') 
	{
		printf("Yes\n");
		return 0;
	}
	int len=strlen(a);
	if(len%2==1)
	{
		if(cycle1(a,0,len-1)) printf("Yes\n");
		else printf("No\n");
	} 
	else
	{
		if(cycle2(a,0,len-1)) printf("Yes\n");
		else printf("No\n");
	}
	
	
	return 0;
}


