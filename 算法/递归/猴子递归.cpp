#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n;
int monkey(int i)
{
	if(i==n) return 1;
	else return 2*(monkey(i+1)+i);
} 
int main()
{
	scanf("%d",&n);
	int ans=monkey(1);
	if(n==1) printf("The monkey got %d peach in the first day.\n",ans);
	else printf("The monkey got %d peaches in the first day.\n",ans);
	return 0;
}


