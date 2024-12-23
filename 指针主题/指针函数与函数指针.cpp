#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef int(*kks)(int,int) ;
void ff()
{
	printf("jjjjj");
}
int add(int x,int y)
{
	return x+y;
}
int main()
{
	void (*p)();//void *p() ²»¿ÉÐÐ 
	p=ff; 
	p();
	
	kks r=add;
	printf("\n%d",r(1,2));
	return 0;
}


