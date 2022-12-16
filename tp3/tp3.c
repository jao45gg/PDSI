#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

char **cria_tabuleiro(int a);

void preencher_tabuleiro(char **a, int b);

void libera_memoria(char **a);

void cria_vetor_resultados();

// void realocacao(int b, int c);

void capturas(char **a, int b, int c, int d, int e, int f);

int **resultados;      // global para não dar problema na hora da realocação e da recursividade
int cont_pecas = 0, aux = 1, cont_capturas = 0; // global pra poder usar dentro da funcao recursiva e como debug

int main()
{

    char entrada[3];
    int tamanho;

    fgets(entrada, 3, stdin);
    sscanf(entrada, "%d", &tamanho);

    char **tabuleiro = cria_tabuleiro(tamanho);
    if (tabuleiro == NULL)
        return EXIT_FAILURE;

    preencher_tabuleiro(tabuleiro, tamanho);

    cria_vetor_resultados();
    if (resultados == NULL)
        return EXIT_FAILURE;

    capturas(tabuleiro, tamanho, 0, 0, 1, 0);

    while (DEBUG && aux)
    {

        printf("%d\n\n", cont_pecas);
        aux = 0;
    }
    aux = 1;

    int aux_local = 0;
    for (int i = 0; i < cont_pecas; i++)
    {

        if (resultados[i][2] > i)
            aux_local = i;
    }

    if (cont_pecas)
        printf("%d %d %d\n", resultados[aux_local][0],
               resultados[aux_local][1], resultados[aux_local][2]);

    for (int i = 0; i < cont_pecas; i++)
    {

        printf("%d %d %d\n", resultados[i][0], resultados[i][1],
               resultados[i][2]);
    }

    libera_memoria(tabuleiro);

    return EXIT_SUCCESS;
}

char **cria_tabuleiro(int tamanho)
{

    char **tabuleiro = (char **)malloc(tamanho);
    if (tabuleiro == NULL)
        return NULL;

    tabuleiro[0] = (char *)malloc(tamanho * tamanho);
    if (tabuleiro[0] == NULL)
        return NULL;

    for (int i = 1; i < tamanho; i++)
    {

        tabuleiro[i] = tabuleiro[0] + i * tamanho;
    }

    return tabuleiro;
}

void preencher_tabuleiro(char **tabuleiro, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {

        fgets(tabuleiro[i], tamanho+2, stdin);
    }

    while (DEBUG && aux)
    {

        printf("  ");

        for (int i = 0; i < tamanho; i++)
        {

            printf("%d ", i);
        }

        printf("\n");

        for (int i = 0; i < tamanho; i++)
        {

            printf("%d", i);
            for (int j = 0; j < tamanho; j++)
            {

                if (tabuleiro[i][j] == ' ')
                    printf(" -");
                else
                    printf("%2c", tabuleiro[i][j]);
            }
            printf("\n");
        }
        aux = 0;
        printf("\n");
    }
    aux = 1;
}

void cria_vetor_resultados()
{

    int linhas = 10, colunas = 3;

    resultados = (int **)malloc(linhas * sizeof(int *));

    resultados[0] = (int *)malloc(linhas * colunas * sizeof(int));

    for (int i = 1; i < linhas; i++)
    {

        resultados[i] = resultados[0] + i * colunas;
    }
}

// void realocacao(int linhas, int colunas)
// {

//     resultados = (int **)realloc(resultados, linhas * sizeof(int *))

//     resultados[0] = (int *)realloc(resultados[0], linhas * colunas * sizeof(int));
// }

void capturas(char **tabuleiro, int tamanho, int y, int x, int teste_peca_ja_registrada, int auxi)
{

    for (y = 0; y < tamanho; y++)
    {

        for (x = 0; x < tamanho; x++)
        {
    
            if ((y + 1 < tamanho) && (y + 2 < tamanho) 
            && (x + 1 < tamanho) && (x + 2 < tamanho) 
            && (tabuleiro[y][x] == 'b') 
            && (tabuleiro[y + 1][x + 1] == 'p') 
            && (tabuleiro[y + 2][x + 2] == ' '))
            {

                tabuleiro[y + 1][x + 1] = ' ';
                tabuleiro[y + 2][x + 2] = 'b';
                tabuleiro[y][x] = ' ';

                capturas(tabuleiro, tamanho, y + 2, x + 2, 0, 1);

                tabuleiro[y + 1][x + 1] = 'p';
                tabuleiro[y + 2][x + 2] = ' ';
                tabuleiro[y][x] = 'b';

                if (teste_peca_ja_registrada)
                {

                    resultados[cont_pecas][0] = y;
                    resultados[cont_pecas][1] = x;
                    resultados[cont_pecas][2] = cont_capturas+1;
                    cont_pecas++;
                    cont_capturas++;
                }
                else if (auxi)
                {

                    resultados[cont_pecas][2] = cont_capturas+1;
                    cont_capturas++;
                }
            }

            if ( (y + 1 < tamanho) && (y + 2 < tamanho) 
            && (x - 2 >= 0) && (x - 1 >= 0)
            && (x - 1 < tamanho) && (x - 2 < tamanho) 
            && (tabuleiro[y][x] == 'b')
            && (tabuleiro[y + 1][x - 1] == 'p') 
            && (tabuleiro[y + 2][x - 2] == ' '))
            {

                tabuleiro[y + 1][x - 1] = ' ';
                tabuleiro[y + 2][x - 2] = 'b';
                tabuleiro[y][x] = ' ';

                capturas(tabuleiro, tamanho, y + 2, x - 2, 0, 1);

                tabuleiro[y + 1][x - 1] = 'p';
                tabuleiro[y + 2][x - 2] = ' ';
                tabuleiro[y][x] = 'b';

                if (teste_peca_ja_registrada)
                {
                    resultados[cont_pecas][0] = y;
                    resultados[cont_pecas][1] = x;
                    resultados[cont_pecas][2] = cont_capturas+1;
                    cont_pecas++;
                    cont_capturas++;
                }
                else if (auxi)
                {
                    resultados[cont_pecas][2] = cont_capturas+1;
                    cont_capturas++;
                }
            }
        }
    }
}

void libera_memoria(char **tabuleiro)
{

    free(resultados[0]);
    free(resultados);
    free(tabuleiro[0]);
    free(tabuleiro);
}