#include <stdio.h>
#include <string.h>

int primos (unsigned long long int x){
    int aux = 0;
    for (int i = 2; i <= x; i++){
        if(x%i == 0 && i != x){
            aux = 0;
            return 0;
        } else aux = 1;
    } if (aux == 1) return 1;
}

int main(void)
{
    char entrada[999] = "inicio";
    unsigned long long int num = 0;
    int num1 = 0;
    while(strlen(entrada) != 0){
        fgets(entrada, 999, stdin);
        entrada[strlen(entrada)-1] = '\0';
        if(strlen(entrada) != 0){
            sscanf(entrada,"%d", &num1);
            if(num1 < 2){
            printf("%d\n", -1);
            } else {
                sscanf(entrada,"%llu", &num);
                printf("%d\n",primos(num));
            }
        }
    }
}