#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d/%d",&a,&b);
	printf("0.");
	int c=a%b;
	for(int i=1;i<=200;i++)
	{
		int ans=c*10/b;
		printf("%d",ans);
		if((c*10%b)!=0)
		{
			c=c*10%b;
		}
		else break;
		
	} 
	printf("\n");
	return 0;
}


