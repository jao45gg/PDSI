#include <stdio.h>

int main (void) {
    int x,r=0;
    scanf("%d",&x);
    for(int i=1;i<=x;i++) {
        r+=i;
    }
    printf("%d",r);
}