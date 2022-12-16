#include <stdio.h>
#include <string.h>
int main (void) {
    char p[100];
    fgets(p, 100, stdin);
    int t = strlen(p);
    for(int j=2; j<=t; j++){
        printf("%c",p[t-j]);
    }
}