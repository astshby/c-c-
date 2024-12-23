#include <stdio.h>
 
int main() 
{
    int n=0;
    int i=0,j=0;//减少int书写量 
    while(~scanf("%d",&n))
    {
           	//打印上三角
	    for(i=1;i<n;i++)
	    {
		    for(j=1; j<=n-i; j++)
		    {
		    	printf(" ");
		    }
		    for(j=1; j<=2*i-1; j++)
		    {
		    	if(j==1||j==2*i-1) printf("*");
		    	else printf(" ");
		    	
		    }
		 printf("\n");
	   }
	
	    //打印倒三角
	    for(i; i>=1; i--)
	    {
		    for(j=1; j<=n-i; j++)
		    {
		    	printf(" ");
		    }
		    for(j=1; j<=2*i-1; j++)
		    {
			    if(j==1||j==2*i-1) printf("*");
			    else printf(" ");
		    }
		    printf("\n");
	    }
 
            
    }
    return 0;
}

