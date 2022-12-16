#include <stdio.h>
int main (void) {
    int v[10];
    for (int i=0;i<10;i++){
        scanf("%d\n",&v[i]);
    }
    for (int i=0;i<10;i++){
        printf("%d\n", v[9-i]);
    }
}