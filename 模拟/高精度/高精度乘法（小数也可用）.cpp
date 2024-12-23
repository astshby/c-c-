#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct big
{
	char zi[505];
	int shu[505];
	int lenzi,lenshu;
	int ifless0,ifpoint;
	int shupoint;//记录point的位置与数量 
}a,b,ans;
//除去前导0 
void Q0(struct big *k)
{
	int qian0=0; 
	if(k->zi[0]!='-')
	{
		for(int i=0;;i++)
		{
			if(k->zi[i]=='0') qian0++;
			else break; 
		}
		if(qian0==k->lenzi||k->zi[qian0]=='.') qian0--;
		if(qian0!=0)
		{
			for(int i=0;i<k->lenzi-qian0;i++) k->zi[i]=k->zi[i+qian0];
			for(int i=k->lenzi-qian0;i<k->lenzi;i++) k->zi[i]='0';
			k->lenzi=k->lenzi-qian0;	
		}
	}
	else if(k->zi[0]=='-')
	{
		for(int i=1;;i++)
		{
			if(k->zi[i]=='0') qian0++;
			else break;
		}
		if(qian0==k->lenzi-1||k->zi[qian0+1]=='.') qian0--;
		if(qian0!=0)
		{
			for(int i=1;i<k->lenzi-qian0+1;i++) k->zi[i]=k->zi[i+qian0];
			for(int i=k->lenzi-qian0+1;i<k->lenzi;i++) k->zi[i]='0';
			k->lenzi=k->lenzi-qian0;	
		}
	}
	k->zi[k->lenzi]='\0';
	return ;
}
//为小数除去后尾0 
void R0shu(struct big *k)
{
	int hou0=0; 
	for(int i=0;;i++)
	{
		if(k->shu[i]==0) hou0++;
		else break; 
	}
	if(hou0>k->shupoint) hou0=k->shupoint;
	if(hou0!=0)
	{
		for(int i=0;i<k->lenshu;i++) k->shu[i]=k->shu[i+hou0];
		k->lenshu=k->lenshu-hou0;
		k->shupoint=k->shupoint-hou0;
		if(k->shupoint==0) k->ifpoint=0;
	}
}
void R0zi(struct big *k)
{
	int hou0=0; 
	for(int i=0;;i++)
	{
		if(k->zi[i]=='0') hou0++;
		else break; 
	}
	if(hou0!=0)
	{
		for(int i=0;i<k->lenzi;i++) k->zi[i]=k->zi[i+hou0];
		k->lenzi=k->lenzi-hou0;
		k->shupoint=k->shupoint-hou0;
	}
	k->zi[k->lenzi]='\0';
} 
void readp(struct big *k)
{
	scanf("%s",k->zi);
	k->lenzi=strlen(k->zi);
	Q0(k);
	int positionpoint;
	for(int i=0;i<k->lenzi;i++)
	{
		if(k->zi[0]=='-') k->ifless0=1;
		else k->ifless0=0;
		
		if(k->zi[i]=='.') 
		{
			k->ifpoint=1;
			positionpoint=i;	
		}	
	}
	if(k->ifpoint) k->shupoint=k->lenzi-(1+positionpoint);
	else k->shupoint=k->ifpoint=0; 
	
	if(k->ifpoint==1)
	{
		k->lenshu=0;
		for(int i=k->lenzi-1;i>=1;i--)
		{
			if(i!=positionpoint) k->shu[k->lenshu++]=k->zi[i]-'0';
		}
		if(k->zi[0]!='-') k->shu[k->lenshu++]=k->zi[0]-'0';
		R0shu(k);//为小数除后尾0 
	}
	else
	{
		k->lenshu=0;
		for(int i=k->lenzi-1;i>=1;i--) k->shu[k->lenshu++]=k->zi[i]-'0';
		if(k->zi[0]!='-') k->shu[k->lenshu++]=k->zi[0]-'0';
	}
	return;
}
void mul(struct big *aans,struct big aa,struct big ab)
{
	aans->lenshu=aa.lenshu+ab.lenshu-1;
	aans->shupoint=aa.shupoint+ab.shupoint;
	if(aans->shupoint) aans->ifpoint=1;
	else aans->ifpoint=0;
	
	if((aa.ifless0==1&&ab.ifless0==0)||(aa.ifless0==0&&ab.ifless0==1)) aans->ifless0=1;
	else aa.ifless0=0;
	
	for(int i=0;i<aa.lenshu;i++)
	{
		for(int j=0;j<ab.lenshu;j++)
		{
			aans->shu[i+j]+=aa.shu[i]*ab.shu[j];
		}
	}
	for(int i=0;i<aans->lenshu;i++)
	{
		if(aans->shu[i]>9)
		{
			aans->shu[i+1]+=aans->shu[i]/10;
			aans->shu[i]=aans->shu[i]%10;
		} 
	}
	if(aans->shu[aans->lenshu]!=0) aans->lenshu++;
	return ;
}

void last(struct big *k)
{
	if(k->shupoint!=0)
	{
		for(int i=0;i<k->lenshu+1;i++) 
		{
			if(i<k->shupoint) k->zi[i]=k->shu[i]+'0';
			else if(i==k->shupoint) k->zi[i]='.';
			else k->zi[i]=k->shu[i-1]+'0';
		}
		k->lenzi=k->lenshu+1;
		R0zi(k);//为小数除后尾0
	}
	else 
	{
		for(int i=0;i<k->lenshu;i++) 
		{
			k->zi[i]=k->shu[i]+'0',k->lenzi++;
		}
	}
	if(k->shupoint==0) k->ifpoint=0;
	else k->ifpoint=1;
	
	if(k->ifless0==1) k->zi[k->lenzi++]='-';
	return ;
}
//换位置，再除去前导0和后面的‘.’ 
void swap0(struct big *k)
{
	for(int i=0;i<k->lenzi/2;i++)
	{
		char temp=k->zi[i];
		k->zi[i]=k->zi[k->lenzi-i-1];
		k->zi[k->lenzi-i-1]=temp;
	}
	Q0(k);
	if(k->ifpoint==0&&k->zi[k->lenzi-1]=='.') 
	{
		k->zi[k->lenzi-1]='\0';
		k->lenzi--;
	}
}
void f0(struct big *k)
{
	char bi[3]="-0";
	if(strcmp(k->zi,bi)==0) k->zi[0]='0',k->zi[1]='\0';
}
int main()
{
	readp(&a);
	readp(&b);
	mul(&ans,a,b);
	last(&ans);
	swap0(&ans);
	f0(&ans); 
	printf("%s\n",ans.zi);
	return 0;
}


