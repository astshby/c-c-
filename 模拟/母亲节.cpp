#include <stdio.h>  
using namespace std;
int xingqi(int y,int m,int d)//���������գ��ж����ڣ�����ֵΪ0��6 
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
    printf("%d���ĸ�׽���5��%d�ա�\n",n,a);  
    return 0;  
}  

