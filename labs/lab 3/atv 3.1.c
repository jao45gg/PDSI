#include <stdio.h>

int main (void) {
    int a,b;
    scanf("%d %d",&a,&b);
    int primo;
    for(int i=a; i<=b; i++) {
        primo = 1;
        if(i==1) {
            primo =0;
        }
        for (int j=2; j<i/2 && primo==1; j++) {
            if (i % j == 0) {
                primo =0;
            }
        } 
        if(primo && i!=4) {
            printf("%d\n", i);
        }
    }
}