#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{

    char nome[100];
    char local[100];
    Data data;
} Evento;

void cadastrar_eventos(Evento agenda[], int n)
{

    for (int i = 0; i < n; i++)
    {
        char entrada[500];
        fgets(entrada, 500, stdin);
        entrada[strlen(entrada) - 1] = '\0';
        sscanf(entrada, "%s %s %d %d %d",
               agenda[i].nome,
               agenda[i].local,
               &agenda[i].data.dia,
               &agenda[i].data.mes,
               &agenda[i].data.ano);
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n)
{
    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        if (d.dia == agenda[i].data.dia &&
            d.mes == agenda[i].data.mes &&
            d.ano == agenda[i].data.ano)
        {

            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            aux = 1;
        }
    }
    if (!aux)
        printf("Nenhum evento encontrado!");
}

int main()
{

    int n = 0;

    char entrada[500];
    fgets(entrada, 500, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    sscanf(entrada, "%d", &n);

    Evento agenda[n];
    cadastrar_eventos(agenda, n);

    Data d;
    fgets(entrada, 500, stdin);
    entrada[strlen(entrada) - 1] = '\0';
    sscanf(entrada, "%d %d %d", &d.dia, &d.mes, &d.ano);

    imprimir_eventos(agenda, d, n);

    return EXIT_SUCCESS;
}