#include <stdio.h>

int main (void) {
    int l,c;
    scanf("%d%d",&l,&c);
    int m[l][c];
    for (int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for (int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            int inv=-m[i][j];
            printf("%d ",inv);
        }
        printf("\n");
    }    
}