#include <stdio.h>
int main (void) {
    int t,t1;
    scanf("%d",&t);
    int v[t];
    for (int i=0;i<t;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&t1);
    int v1[t1];
    for (int i=0;i<t1;i++){
        scanf("%d",&v1[i]);
    }
    for (int i=0;i<t;i++){
        for(int j=0;j<t1;j++) {
            if(v[i]==v1[j]) {
                printf("%d\n",v1[j]);
            }
        }
    }
}