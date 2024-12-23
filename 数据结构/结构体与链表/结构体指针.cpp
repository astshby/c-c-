#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct person
{
	int age;
	char name[18];
}pe;
void charu(pe* a)
{
	scanf("%d",&a->age);
	getchar();
	scanf("%s",&a->name);
	return;
}
void shuchu(pe a)
{
	printf("%d\n",a.age);
	printf("%s\n",a.name);
}
int main()
{
	pe a;
	charu(&a);
	shuchu(a);
	return 0;
}


