#include<stdio.h>
int main()
{
	int y,m,d; 
scanf("%d %d %d",&y,&m,&d);

	int yuefen=0,riqi=0;
	if((y%4==0&&y%100!=0)||(y%400==0)) 
	{
		if(m>12||m<=0) yuefen=1;
		if(d>31||d<=0) riqi=1;
		if(m==2&&d>29) riqi=1;
		else if((m==1||m==3||m==7||m==5||m==8||m==10||m==12)&&d>31) riqi=1;
		else if((m==4||m==6||m==9||m==11)&&d>30) riqi=1;
	}
	else
	{
		if(m>12||m<=0) yuefen=1;
		if(d>31||d<=0) riqi=1;
		if(m==2&&d>28) riqi=1;
		else if((m==1||m==3||m==7||m==5||m==8||m==10||m==12)&&d>31) riqi=1;
		else if((m==4||m==6||m==9||m==11)&&d>30) riqi=1;
	}
	if(riqi==0&&yuefen==0){
		int w;  
    if(m<=2) y=y-1,m=m+12;  
    w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7; 
	printf("%d\n",w);
	} 
	else if(riqi!=0&&yuefen==0) printf("day is wrong.\n");
	else if(riqi==0&&yuefen!=0) printf("month is wrong.\n");
	else if(riqi!=0&&yuefen!=0) printf("month and day are wrong.\n");

	return 0;
}


