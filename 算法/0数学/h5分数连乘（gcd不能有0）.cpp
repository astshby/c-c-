#include<stdio.h>
#include<math.h>
long long gcd(long long a,long long b)
{
	if(a<b)
	{
		long long c;
		c=a,a=b,b=c; 
	}
	if(a%b==0) return b;
	else gcd(b,a%b);
}
int main()
{
	int n;
	long long zi[25]={0},mu[25]={0};
	long long ans1=1,ans2=1;
	scanf("%d\n",&n);
	for(int i=1;i<=n-1;i++) scanf("%lld %lld\n",&zi[i],&mu[i]);  
    scanf("%lld %lld",&zi[n],&mu[n]); //???，dev的问题，gcc上写成一个都可以 
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			if(zi[i]!=1&&mu[j]!=1&&zi[i]!=0&&mu[j]!=0) 
			//gcd一定不能有0
			{
				unsigned long long yue=gcd(zi[i],mu[j]);
				zi[i]=zi[i]/yue,mu[j]=mu[j]/yue;
			}
		}
	}//每一个都约分一次防止超出限度，尽量不要用_int128 
	for(int i=1;i<=n;i++)
	{
		ans1*=zi[i];
		ans2*=mu[i];
	}
	if(ans2==1) printf("%lld\n",ans1);
	else if(ans1!=0&&ans2!=0)
	{
			long long yue=gcd(ans1,ans2);
			ans1=ans1/yue;
			ans2=ans2/yue;
			printf("%lld/%lld\n",ans1,ans2);	
	}
	else printf("0\n");
	return 0;
}


