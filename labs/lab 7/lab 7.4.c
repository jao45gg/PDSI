#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Cadastro
{
char nome[50];
int idade;
char telefone[20];
} Cadastro;


int main()
{
char entrada[15], nome_arquivo[15], nome_procurado[50];
int i, t;
Cadastro cad[100];



FILE *arquivo;


for (int p = 0; p < 100; p++)
{
strcpy(cad[p].nome, "vazio");
}


fgets(nome_arquivo,15,stdin);
nome_arquivo[strlen(nome_arquivo)-1]='\0';


arquivo = fopen(nome_arquivo, "rb");
if (arquivo == NULL)
{
exit(1);
}


fread(cad, sizeof(Cadastro), 100, arquivo);

while (scanf("%s", entrada) != EOF)
{
if (strcmp(entrada, "Inserir") == 0)
{
i = 0;
while (strcmp(cad[i].nome, "vazio") != 0)
{
i++;
if (i == 100)
{
printf("Espaco insuficiente\n");
break;
}
}
if (i < 100)
{
scanf("%s", cad[i].nome);
scanf("%d", &cad[i].idade);
scanf("%s", cad[i].telefone);


printf("Registro %s %d %s inserido\n", cad[i].nome, cad[i].idade, cad[i].telefone);
}
}

if (strcmp(entrada, "Alterar") == 0)
{
i = 0;
scanf("%s", nome_procurado);


while (i < 100)
{
if (strcmp(cad[i].nome, nome_procurado) == 0)
{
scanf("%d", &cad[i].idade);
scanf("%s", cad[i].telefone);


printf("Registro %s %d %s alterado\n", cad[i].nome, cad[i].idade, cad[i].telefone);
break;
}
i++;
}
if (i == 100)
{
printf("Registro %s invalido\n", nome_procurado);
}
}


if (strcmp(entrada, "Excluir") == 0)
{
i = 0;
t = 0;
scanf("%s", nome_procurado);


while (i < 100)
{
if (strcmp(cad[i].nome, nome_procurado) == 0)
{
if (t == 0)
{
printf("Registro %s %d %s excluido\n", cad[i].nome, cad[i].idade, cad[i].telefone);
}
t = 1;
strcpy(cad[i].nome, "vazio");
}
i++;
}
if (i == 100 && t == 0)
{
printf("Registro %s invalido\n", nome_procurado);
}
}


if (strcmp(entrada, "Exibir") == 0)
{
i = 0;
scanf("%s", nome_procurado);



while (i < 100)
{
if (strcmp(cad[i].nome, nome_procurado) == 0)
{
printf("Registro %s %d %s exibido\n", cad[i].nome, cad[i].idade, cad[i].telefone);


break;
}
i++;
}
if (i == 100)
{
printf("Registro %s invalido\n", nome_procurado);
}
}
}
arquivo = fopen(nome_arquivo, "wb");
fwrite(&cad, sizeof(struct Cadastro), 100, arquivo);
fclose(arquivo);
return 0;
}