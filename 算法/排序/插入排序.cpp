#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a[105]={0}; 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(i==1) a[i]=temp;
		else
		{
			if(temp>a[i-1]) a[i]=temp;
			else
			{
				int j=i-1;
				for(;j>=1&&temp<a[j];j--)
				{
					a[j+1]=a[j];
				}
				a[j+1]=temp;
			}
			
		} 	
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}


