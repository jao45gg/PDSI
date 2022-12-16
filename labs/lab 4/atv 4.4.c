#include <stdio.h>
#include <string.h>
int main (void) {
    char s[200];
    char s1[100];
    fgets(s, 200, stdin);
    fgets(s1, 100, stdin);
    int t = strlen(s);
    int t1 = strlen(s1);
    int i,j,v;
    for(i=0; i<=t && i!=t1; i++){
        printf("%d %d",j,i);
        for(j=0; j<t1 && i!=t1;j++){
            //printf("%d %d",j,i);
            if(s[j]==s1[i]){
              v=1;
              i++;
            } else {
              v=0;  
            }
        }
    }
    if(v){
        printf("É substring");
    } else {
        printf("Não é substring");
    }
    
}