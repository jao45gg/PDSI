#include <stdio.h>

int main (void) {
    int l,c,ma=0;
    scanf("%d\n %d",&l,&c);
    int m[l][c];
    for (int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for (int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]>=ma){
                ma=m[i][j];
            }
        }
    }
    printf("%d",ma);
}