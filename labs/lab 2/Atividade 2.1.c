#include <stdio.h>

 int main (void) {
     int n,x0,x1,c=2,xn;
     scanf("%d%d%d",&n,&x0,&x1);
     printf("X0: %d\nX1: %d\n",x0,x1);
     while(c<=n){
         xn=4*x1-2*x0;
         printf("X%d: %d\n",c,xn);
         x0=x1;
         x1=xn;
         c++;
     }
 }