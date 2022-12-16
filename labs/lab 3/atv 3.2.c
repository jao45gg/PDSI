#include <stdio.h>

int main (void) {
    int t;
    do {
        scanf("%d",&t);
        int fib[t+1];
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=t;i++) {
            fib[i]=fib[i-1]+fib[i-2];
        }
        if(t>=0 && t<=800) {
            printf("%d\n", fib[t]);
        }
    } while (t<=800 && t>=0);
}