#include <stdio.h>
#include <string.h>

typedef struct {
    int ano;
} data_t;

int anobissexto (data_t a) {
    if( (a.ano%4) == 0){
        if( (a.ano%100) == 0){
            if( (a.ano % 400) == 0){
                return 1;
            } else return 0;
            return 1;
        } else return 1;
    } else return 0;
}

int main(void){
    data_t dataD;
    char buffer[20] = "inicio";
    
    while(strlen(buffer)>1){
        
        fgets(buffer, 20, stdin);
        sscanf(buffer, "%d", &dataD.ano);
        if(strlen(buffer)<=1){
            break;
        }
        printf("%d\n", anobissexto(dataD));
    }
}