#include <stdio.h>
 
int main() 
{
    int n=0;
    int i=0,j=0;//����int��д�� 
    while(~scanf("%d",&n))
    {
           	//��ӡ������
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
	
	    //��ӡ������
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

