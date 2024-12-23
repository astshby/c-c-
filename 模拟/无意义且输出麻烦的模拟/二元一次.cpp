#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a==0)
	{
		if(b==0) printf("Input error!\n");
		else
		{
			double ans=-c*1.0/b;
			printf("x=%.6lf\n",ans);
		}
	}
	else
	{
		double delta=b*b-4.0*a*c;
		if(delta>0)
		{
			double x1=(-b*1.0+sqrt(delta))/(2.0*a);
			double x2=(-b*1.0-sqrt(delta))/(2.0*a);
			printf("x1=%.6lf\nx2=%.6lf\n",x1,x2);
		}
		else if(delta==0)
		{
			double x=-b/(2.0*a);
			printf("x1=x2=%.6lf\n",x);
		}
		else 
		{
			delta=sqrt(-delta)/(2.0*a);
			double aa=-b/(2.0*a);
			if(aa!=0) printf("x1=%.6lf+%.6lfi\n",aa,delta),printf("x2=%.6lf-%.6lfi\n",aa,delta);
			else printf("x1=%.6lfi\n",delta),printf("x2=-%.6lfi\n",delta);
		}
	}
	
	return 0;
}


