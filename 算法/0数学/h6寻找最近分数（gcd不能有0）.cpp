#include<stdio.h>  
#include<math.h>  
long double bijiao(long long j,long long i,long long a,long long b)  
{  
    long long fenmu=i*b,fenzi=(j*b-i*a)>=0?(j*b-i*a):(-(j*b-i*a));  
    long double ans=fenzi*1.0/fenmu;  
    return ans;  
}  //防止直接减法的误差而通分 
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
    long long a,b,n;  
    long long ans1,ans2;  
    scanf("%lld %lld %lld",&a,&b,&n);  
    if(b<=n)   
    {  
        if(a!=0)  
        {  
            long long yue=gcd(a,b);  
            ans1=a/yue,ans2=b/yue;  
            printf("%lld/%lld\n",a,b);  
        }  
        else printf("%lld/1\n",a);  
          
    }  
    else  
    {  
        long double k,cun=bijiao(a,n,a,b);  
        ans1=a,ans2=n;  
        for(int i=n;i>=1;i--)  
        {  
            long long kks=a*1.0*i/b; //取整后的kks/i一定是以i为分母最靠近且小于a/b的的数 
            long double k1=bijiao(a*1.0*i/b,i,a,b);  
            long double k2=bijiao((a*1.0*i/b+1),i,a,b);  
            if(k1<=k2)   
            {  
                k=k1;  
                if(k<=cun) cun=k,ans1=a*1.0*i/b,ans2=i;  
            }  
            else   
            {  
                k=k2;  
                if(k<=cun) cun=k,ans1=a*1.0*i/b+1,ans2=i;  
            }  //忘写cun=k，程序错误 
        }     
        if(ans1!=0)  //gcd不能有0 
        {  
            long long yue=gcd(ans1,ans2);  
            ans1=ans1/yue,ans2=ans2/yue;  
            printf("%d/%d\n",ans1,ans2);  
        }  
        else printf("%d/1\n",ans1);  
          
    }  
      
    return 0;  
}  
