#include <stdio.h>
#include <string.h>
int main (void) {
    char s[200];
    char s1[100];
    fgets(s, 200, stdin);
    int t = strlen(s);
    fgets(s1, 100, stdin);
    int t1 = strlen(s1);
    s1[t1-1] = '\0';
    for(int i=0; i<t1; i++){
        s[(t+i)-1] = s1[i];
    }
    puts(s);
}