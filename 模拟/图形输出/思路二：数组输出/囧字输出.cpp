#include <stdio.h>  
#include <math.h>   
int JiongUpdate(char jiong[600][600],int n,int k){  
    if(k==-1){  
        return 0;  
    }  
    int x1=pow(2,n+1)-pow(2,k+1),x2=pow(2,n+1)+pow(2,k+1)-1,y1=pow(2,n+2)-pow(2,k+2),y2=pow(2,n+2)-1;
    for(int i=y1;i<=y2;i++){  
        for(int j=x1;j<=x2;j++){  
            if(j>x1 && j<x2 && i>(y1+y2)/2 && i<y2 ){  
                continue;  
               } 
            if((j==x1 || j==x2) && (i==y1 || i==y2)){  
                jiong[i][j]='+';  
            }else if(i==y1 || i==y2){  
                jiong[i][j]='-';  
            }else if(j==x1 || j==x2){  
                jiong[i][j]='|';  
            }else if(j>x1+1 && i>y1+1 && i+j==y1+pow(2,n+1)){  
                jiong[i][j]='/';  
            }else if(j<x2-1 && i>y1+1 && i-j==y1-pow(2,n+1)+1){  
                jiong[i][j]='\\';  //×ªÒå·ûºÅ 
            }  
        }  
    }  
    JiongUpdate(jiong,n,k-1);  
}  
int main(){  
    char jiong[600][600]={0},n;  
    scanf("%d",&n);  
    JiongUpdate(jiong,n,n);  
    for(int i=0;i<pow(2,n+2);i++){  
        for(int j=0;j<pow(2,n+2);j++){  
            if(jiong[i][j]!=0){  
            printf("%c",jiong[i][j]);  
            }else{  
                printf(" ");  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}  
