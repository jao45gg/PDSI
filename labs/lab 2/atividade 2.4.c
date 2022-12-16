#include <stdio.h>

int main (void) {
    int X,contador=1,c2=0,c3=0,c5=0,cg=0;
    scanf("%d",&X);
    while(contador<=X) {
        if(contador%2==0){
            c2++;
        }
        if(contador%3==0){
            c3++;
        }
        if(contador%5==0){
            c5++;
        }
        if(contador%2==0 && contador%3==0 && contador%5==0){
            cg++;
        }
        contador++;
    }
    printf("Múltiplos de 2:%d\nMúltiplos de 3:%d\nMúltiplos de 5:%d\nMúltiplos de todos:%d\n",c2,c3,c5,cg);
}