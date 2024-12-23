#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	scanf("%d*%d %d",&a,&b,&c);
	double ans=a*b*c*60.0*30*24/(8*1024);
	int anss=(int)ans;
	printf("%d\n",anss);
}


