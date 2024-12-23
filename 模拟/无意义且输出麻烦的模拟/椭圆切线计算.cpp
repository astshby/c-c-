#include<stdio.h> 
#include<math.h>  
int main() 
{ 
   int a,b; 
   double m,n; 
   scanf("%d %d\n%lf %lf",&a,&b,&m,&n); 
 double aaa=m*m/(a*1.0)+n*n/(b*1.0); 
   if(aaa!=1)  
    { 
      printf("Input error!\n");return 0; 
 } 
  else if(m!=0&&n!=0) 
    { 
      double ans1=-(b*1.0*(m)/(n*a)); 
        double ans2=b*1.0/n; 
     if(ans2>0)  printf("y=%.6lfx+%.6lf\n",ans1,ans2);
	 else  printf("y=%.6lfx%.6lf\n",ans1,ans2);
      return 0; 
  } 
  else if(m==0&&n!=0)  
   { 
      double nn=n*1.0; 
       printf("y=%.6lf\n",nn);return 0; 
   } 
  else if(m!=0&&n==0)  
   { 
      double mm=m*1.0; 
       printf("x=%.6lf\n",mm);return 0; 
   } 
  return 0; 
}  


