#include <stdio.h>
#include <string.h>

unsigned long long int Soma_Primos (int y){
    unsigned long long int total = 0;
    total += y;
    return total;
}


unsigned long long int Primos (unsigned long long int x){
    unsigned long long int resultado = 0;
    int c = 0;
    for (int i = 2; c < x; i++){
        int aux = 0;
        int aux1 = 1;
        if( i % 2 != 0  || i == 2 ){
            for (int j = 2; j <= i; j++){
                if(i%j == 0 && j != i){
                    aux = 0;
                    aux1 = 0;
                }
                else if(aux1) aux = 1;
            }
            if (aux && aux1) {
                c++;
                resultado += Soma_Primos(i);
            }    
        }
    } return resultado;
}

int main(void)
{
    char entrada[999] = "inicio";
    unsigned long long int num = 0;
    while(strlen(entrada) != 0){
        fgets(entrada, 999, stdin);
        entrada[strlen(entrada)-1] = '\0';
        if(strlen(entrada) != 0){
            sscanf(entrada,"%llu", &num);
            printf("%llu\n",Primos(num));
        }
    }
}