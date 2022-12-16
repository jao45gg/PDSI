#include <stdio.h>
#include <math.h>

int main (void) {
    double pi=0,precisao;
    int repeticao;
    scanf("%lf",&precisao);
    for (repeticao = 0; fabs(pi - M_PI) > precisao; repeticao++)
    {
        pi += pow(-1,repeticao) * 4.0/(2.0*repeticao+1);
    }
    printf("%d",repeticao);
}