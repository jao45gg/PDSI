#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    char estado[4];

} dados_p;

void relatorio_estoque(int qtnd_prod, dados_p p[], char *nome_arquivo_saida)
{

    char nome_saida[20];
    sscanf(nome_arquivo_saida, "%s", nome_saida);

    FILE *file = fopen(nome_saida, "w");

    int codaux = 0;
    char nomaux[50];
    int qtndaux = 0;
    float precoaux = 0.0;
    char estaux[4];

    for (int i = 0; i < qtnd_prod; i++)
    {
        
        for (int j = i+1; j < qtnd_prod; j++)
        {

            if (strcmp(p[i].nome, p[j].nome) > 0)
            {

                codaux = p[i].codigo;
                strcpy(nomaux, p[i].nome);
                qtndaux = p[i].quantidade;
                precoaux = p[i].preco;
                strcpy(estaux, p[i].estado);
                
                p[i].codigo = p[j].codigo;
                strcpy(p[i].nome, p[j].nome);
                p[i].quantidade = p[j].quantidade;
                p[i].preco = p[j].preco;
                strcpy(p[i].estado, p[j].estado);
                
                p[j].codigo = codaux;
                strcpy(p[j].nome, nomaux);
                p[j].quantidade = qtndaux;
                p[j].preco = precoaux;
                strcpy(p[j].estado, estaux);

            }
        
        }

    }

    
    for (int i = 0; i < qtnd_prod; i++)
    {

        if (i != 899)
        {

            fprintf(file, "%d\n%s\n%d\n%.2f\n%s\n",
            p[i].codigo,
            p[i].nome,
            p[i].quantidade,
            p[i].preco,
            p[i].estado);

        }
        else
        {

            fprintf(file, "%d\n%s\n%d\n%.2f\n%s",
            p[i].codigo,
            p[i].nome,
            p[i].quantidade,
            p[i].preco,
            p[i].estado);

        }

    }

    fclose(file);

}

int pesquisar_por_codigo(int qtnd_prod, dados_p p[], char *codigo_procurado)
{

    int codigoprocurado;
    sscanf(codigo_procurado, "%d", &codigoprocurado);

    for (int i = 0; i < qtnd_prod; i++)
    {

        if (p[i].codigo == codigoprocurado)
        {

            printf("%d\n%s\n%d\n%.2f\n%s", 
            p[i].codigo, 
            p[i].nome,
            p[i].quantidade, 
            p[i].preco, 
            p[i].estado);

            return EXIT_SUCCESS;

        }

    }
    return EXIT_FAILURE;
}

void menor_estoque(int qtnd_prod, dados_p p[])
{

    int quantidade_estoque = p[0].quantidade;
    int posicao_menor = 0;

    for (int i = 0; i < qtnd_prod; i++)
    {

        if (p[i].quantidade < quantidade_estoque)
        {

            quantidade_estoque = p[i].quantidade;
            posicao_menor = i;

        }
    }

    printf("%d\n%s\n%d\n%.2f\n%s", 
    p[posicao_menor].codigo, 
    p[posicao_menor].nome,
    p[posicao_menor].quantidade, 
    p[posicao_menor].preco, 
    p[posicao_menor].estado);

}

void produtos_por_estado(int qtnd_prod, dados_p p[], char *estado_p)
{

    char estado[4];
    sscanf(estado_p, "%s", estado);

    dados_p p1[qtnd_prod];
    int ind_aux = 0;

    for (int i = 0; i < qtnd_prod; i++)
    {
        
        if (strcmp(estado, p[i].estado) == 0)
        {

            p1[ind_aux].codigo = p[i].codigo;
            strcpy(p1[ind_aux].nome, p[i].nome);
            p1[ind_aux].quantidade = p[i].quantidade;
            p1[ind_aux].preco = p[i].preco;
            strcpy(p1[ind_aux].estado, p[i].estado);
            ind_aux++;

        }
        
    }
    
    int codaux = 0;
    char nomaux[50];
    int qtndaux = 0;
    float precoaux = 0.0;
    char estaux[4];

    for (int i = 0; i < ind_aux; i++)
    {
        
        for (int j = i+1; j < ind_aux; j++)
        {

            if (strcmp(p1[i].nome, p1[j].nome) > 0)
            {

                codaux = p1[i].codigo;
                strcpy(nomaux, p1[i].nome);
                qtndaux = p1[i].quantidade;
                precoaux = p1[i].preco;
                strcpy(estaux, p1[i].estado);
                
                p1[i].codigo = p1[j].codigo;
                strcpy(p1[i].nome, p1[j].nome);
                p1[i].quantidade = p1[j].quantidade;
                p1[i].preco = p1[j].preco;
                strcpy(p1[i].estado, p1[j].estado);
                
                p1[j].codigo = codaux;
                strcpy(p1[j].nome, nomaux);
                p1[j].quantidade = qtndaux;
                p1[j].preco = precoaux;
                strcpy(p1[j].estado, estaux);

            }
        
        }

    }

    for (int i = 0; i < ind_aux; i++)
    {
        
       if (i != ind_aux)
        {

            printf("%d\n%s\n%d\n%.2f\n%s\n",
            p1[i].codigo,
            p1[i].nome,
            p1[i].quantidade,
            p1[i].preco,
            p1[i].estado);

        }
        else if (i+1 == ind_aux)
        {

            printf("%d\n%s\n%d\n%.2f\n%s",
            p1[i].codigo,
            p1[i].nome,
            p1[i].quantidade,
            p1[i].preco,
            p1[i].estado);

        }

    }
    
    
}

void menor_estoque_estado(int qtnd_prod, dados_p p[], char *estado_p)
{

    char estado[4];
    sscanf(estado_p, "%s", estado);

    for (int i = 0; i < qtnd_prod; i++)
    {
        if ((strcmp(estado, p[i].estado)) != 0)
        {
            p[i].quantidade = 999999;
        }
    }

    int quantidade_estoque = p[0].quantidade;
    int posicao_menor = 0;
    for (int i = 0; i < qtnd_prod; i++)
    {
        if (p[i].quantidade < quantidade_estoque)
        {
            quantidade_estoque = p[i].quantidade;
            posicao_menor = i;
        }
    }
    printf("%d\n%s\n%d\n%.2f\n%s", 
    p[posicao_menor].codigo, 
    p[posicao_menor].nome,
    p[posicao_menor].quantidade, 
    p[posicao_menor].preco, 
    p[posicao_menor].estado);
}

void total_itens(int qtnd_prod, dados_p p[])
{

    long int total_itens = 0;
    for (int i = 0; i < qtnd_prod; i++)
    {
        total_itens += p[i].quantidade;
    }
    printf("%ld\n", total_itens);
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Erro, nome do arquivo ausente\n");
        return EXIT_FAILURE;
    }
    
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura: ");
        return EXIT_FAILURE;
    }
   
    int quantidade_produtos = 0;
    fscanf(arquivo, "%d", &quantidade_produtos);
    if (quantidade_produtos > 1000 || quantidade_produtos < 1)
    {
        printf("Erro na quantidade de produtos !");
        return EXIT_FAILURE;
    }

    dados_p produto[quantidade_produtos];
    for (long int i = 0; i < quantidade_produtos; i++)
    {
        fscanf(arquivo, "%d %50[^\n] %d %f %4[^\n]", 
        &produto[i].codigo,
        produto[i].nome,
        &produto[i].quantidade, 
        &produto[i].preco,
        produto[i].estado);
    }
    fclose(arquivo);

    int parametro2;
    sscanf(argv[2], "%d", &parametro2);
    switch (parametro2)
    {
    case 1:
        relatorio_estoque(quantidade_produtos, produto, argv[3]);
        break;
    case 2:
        pesquisar_por_codigo(quantidade_produtos, produto, argv[3]);
        break;
    case 3:
        menor_estoque(quantidade_produtos, produto);
        break;
    case 4:
        produtos_por_estado(quantidade_produtos, produto, argv[3]);
        break;
    case 5:
        menor_estoque_estado(quantidade_produtos, produto, argv[3]);
        break;
    case 6:
        total_itens(quantidade_produtos, produto);
        break;
    default:
        printf("Erro no segundo parametro\n");
        return EXIT_FAILURE;
    }
}