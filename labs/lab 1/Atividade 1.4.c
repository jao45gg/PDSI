#include <stdio.h>
int main(void)
{
    int valor, nota1, nota2, nota3, nota4, nota5, nota6, nota7;
    scanf("%d", &valor);
    nota1 = valor / 100;
    valor = valor - nota1 * 100;
    nota2 = valor / 50;
    valor = valor - nota2 * 50;
    nota3 = valor / 20;
    valor = valor - nota3 * 20;
    nota4 = valor / 10;
    valor = valor - nota4 * 10;
    nota5 = valor / 5;
    valor = valor - nota5 * 5;
    nota6 = valor / 2;
    valor = valor - nota6 * 2;
    nota7 = valor / 1;
    printf("100:%d\n"
           "50:%d\n"
           "20:%d\n"
           "10:%d\n"
           "5:%d\n"
           "2:%d\n"
           "1:%d\n",
           nota1, nota2, nota3, nota4, nota5, nota6, nota7);
}