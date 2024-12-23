#include<bits/stdc++.h>
using namespace std;
struct big_n
{
	int v[1005];
	int len;
};
big_n x,y,ans;

void R0(big_n &ans)
{
	while (ans.len>1 && ans.v[ans.len-1]==0) ans.len--;
	return;
}

void read(big_n &t)
{	
	string s;
	cin>>s;
	t.len=s.size();
	for (int i=0;i<t.len;i++)
		t.v[t.len-i-1]=s[i]-'0';
	R0(t);
	return;
}

void out(big_n t)
{
	for (int i=t.len-1;i>=0;i--) cout<<t.v[i];
	cout<<endl;
	return;
}

void jia(big_n x,big_n y,big_n &ans)
{
	ans.len=max(x.len,y.len);
	for (int i=0;i<ans.len;i++) ans.v[i]=x.v[i]+y.v[i];
	for (int i=0;i<ans.len;i++)
	if (ans.v[i]>=10)
	{
		ans.v[i+1]+=ans.v[i]/10;
		ans.v[i]=ans.v[i]%10;
	}
	if (ans.v[ans.len]!=0) ans.len++;
	
	R0(ans);	
	return;
}
void cheng(big_n x,big_n y,big_n &ans)
{
	ans.len=x.len+y.len-1;
	for (int i=0;i<x.len;i++)
	for (int j=0;j<y.len;j++)
		ans.v[i+j]+=x.v[i]*y.v[j];
	
	for (int i=0;i<ans.len;i++)
	if (ans.v[i]>=10)
	{
		ans.v[i+1]=ans.v[i+1]+ans.v[i]/10;
		ans.v[i]=ans.v[i]%10;
	}
	if (ans.v[ans.len]!=0) ans.len++;
	
	R0(ans);
	return;
}
void jian(big_n x,big_n y,big_n &ans)//±£Ö¤a>b 
{
	ans.len=max(x.len,y.len);
	for(int i=0;i<ans.len;i++)
	{
		ans.v[i]=x.v[i]-y.v[i];
	}
	for(int i=0;i<ans.len;i++)
	{
		if(ans.v[i]<0) 
		{
			ans.v[i]=10+ans.v[i];
			ans.v[i+1]--;
		}
	}
	
	R0(ans);
	return;
}
int main()
{
	read(x); 
	read(y);
	jian(x,y,ans);
	out(ans);
}

