#include <stdio.h>
 
int main() 
{
    int n=0;
    int i=0,j=0;//����int��д�� 
    char c,c1,c2; 
    while(~scanf("%d %c",&n,&c))
    {
		c1=c2=c;
        for(int j=1;j<4*n-4;j++)//��ȥc2�����õȺ� 
        {
        	c2++;
        	if(c2>'Z') c2='A';
		}
		   	//��ӡ������
	    for(i=1;i<n;i++)
	    {
		    for(j=1; j<=n-i; j++)
		    {
		    	printf(" ");
		    }
		    for(j=1; j<=2*i-1; j++)
		    {
		    	if(j==1) 
				{
					printf("%c",c1++);
					if(c1>'Z') c1='A';
				}
				else if(j==2*i-1)
				{
					printf("%c",c2--);
					if(c2<'A') c2='Z';
				}
		    	else printf(" ");
		    	
		    }
		 printf("\n");
	   }
	
	    //��ӡ������
	    for(i=n; i>=1; i--)
	    {
		    for(j=1; j<=n-i; j++)
		    {
		    	printf(" ");
		    }
		    for(j=1; j<=2*i-1; j++)
		    {
			    if(j==1) 
				{
					printf("%c",c1++);
					if(c1>'Z') c1='A';
				}
				else if(j==2*i-1)
				{
					printf("%c",c2--);
					if(c2<'A') c2='Z';
				}
			    else printf(" ");
		    }
		    printf("\n");
	    }
 
            
    }
    return 0;
}

