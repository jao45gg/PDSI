#include <stdio.h>
#include <string.h>
int main (void) {
    char s[100];
    char c1,c2;
    fgets(s, 100, stdin);
    scanf("%c",&c1);
    setbuf(stdin, NULL);
    scanf("%c",&c2);
    for(int i=0; i<=strlen(s); i++){
        if(s[i]==c1){
            s[i] = c2;
            i=10000;
        }
    }
    s[strlen(s)-1] = '\0';
    puts(s);
}