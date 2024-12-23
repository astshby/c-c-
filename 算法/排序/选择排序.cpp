#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> 
void swap(int *a,int *b) 
{ 
 int p=*a; 
  *a=*b; 
 *b=p; 
} 
int main() 
{ 
   	int a[105]; 
    int n; 
 	scanf("%d",&n); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
    for(int i=1;i<=n-1;i++) 
 	{ 
    	int temp=i; 
        for(int j=i+1;j<=n;j++) 
    	{ 
          if(a[temp]>a[j])  temp=j; 
    	} 
      	swap(&a[i],&a[temp]);    
   	}  
 	for(int i=1;i<=n;i++) 
	 {
	 	if(i!=n) printf("%d ",a[i]);
	 	else printf("%d\n",a[i]);
	 } 
   	return 0; 
}  

