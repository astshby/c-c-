#include <stdio.h>  
using namespace std;
int xingqi(int y,int m,int d)//给定年月日，判断星期，返回值为0到6 
{    
    int w;  
    if(m<=2) y=y-1,m=m+12;  
    w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;    
    return w; 
}
int main()  
{  
    int n,a; 
    scanf("%d",&n); 
	int sta=xingqi(n,4,30); 
	a=14-sta;  
    printf("%d年的母亲节是5月%d日。\n",n,a);  
    return 0;  
}  

