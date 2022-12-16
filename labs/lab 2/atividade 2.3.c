#include <stdio.h>

int main (void) {
    int contagem=233;
    do {
        printf("%d\n",contagem);
        contagem +=5;
    } while (contagem<300) ;
    do {
        printf("%d\n",contagem);
        contagem +=3;
    } while (contagem>=300 && contagem<=400) ;
    do {
        printf("%d\n",contagem);
        contagem +=5;
    } while (contagem>400 && contagem<=457);
}