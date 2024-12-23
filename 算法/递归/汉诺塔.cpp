#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long ans; 
void hannuota(int n,char A,char B,char C)
//从A到C，中转B 
{
	if(n==1) 
	{
		printf("move %d from %c to %c\n",n,A,C);
		ans++;
		return;
	}//n=1，直接起始到目标 
	else
	{
		//n>=2，先把n-1从A到B中转C，将n从A移动到C 
		//然后将n-1从B到C中转A 
		hannuota(n-1,A,C,B);
		printf("move %d from %c to %c\n",n,A,C);
		ans++;
		hannuota(n-1,B,A,C);
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	hannuota(n,'a','b','c');
	printf("%d\n",ans);//2*n-1次数 
	return 0;
}


