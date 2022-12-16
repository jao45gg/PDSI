#include <stdio.h>
#include <string.h>
 
typedef struct {
    char nome[52];
    int idade;
    float salario;
} dados;

typedef struct {
    char rua[52];
    int num;
    char estado[52];
} endereco;

int main (void)
{
  
  char entrada[52] ;
  int x = 0;
  
  fgets(entrada, 52, stdin);
  entrada[strlen(entrada)-1] = '\0';
    
  while(strlen(entrada) != 0){
    
    dados pessoa[5];
    endereco end[5];
    
    if( (!strcmp(entrada,"inserir")) && x < 5 ){
        
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        
        sscanf(entrada, "%s %d %f %s %d %s", pessoa[x].nome, &pessoa[x].idade, &pessoa[x].salario, 
        end[x].rua, &end[x].num, end[x].estado);
        printf("Registro %s %d %.2f %s %d %s inserido\n", pessoa[x].nome, pessoa[x].idade, 
        pessoa[x].salario, end[x].rua, end[x].num, end[x].estado);
        x++;
    }
    else if (!strcmp(entrada,"mostrar")) {
        
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        
        int i=0, teste = 1;
        while(i<5 && teste){
            if(!strcmp(entrada,pessoa[i].nome)){
                printf("Registro %s %d %.2f %s %d %s\n", pessoa[i].nome, pessoa[i].idade, 
                pessoa[i].salario, end[i].rua, end[i].num, end[i].estado);
                teste = 0;
            } 
            else if (i==4 && teste==1) printf("Registro ausente\n");
            i++;
        }
    } 
    else if ((!strcmp(entrada,"inserir")) && x >= 5) {
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        puts("Espaco insuficiente");
    }
    else if(!strcmp(entrada,"alterar")) {
         
         char auxiliar[52];
         fgets(entrada, 52, stdin);
         entrada[strlen(entrada)-1] = '\0';
         sscanf(entrada, "%s", auxiliar);
        
         int k=0, teste1 = 1;
         
         while(k<5 && teste1){
            if(!strcmp(auxiliar,pessoa[k].nome)){
                sscanf(entrada, "%s %d %f %s %d %s", pessoa[k].nome, &pessoa[k].idade, &pessoa[k].salario, 
                end[k].rua, &end[k].num, end[k].estado);
                printf("Registro %s %d %.2f %s %d %s alterado\n", pessoa[k].nome, pessoa[k].idade, 
                pessoa[k].salario, end[k].rua, end[k].num, end[k].estado);
                teste1 = 0;
            } 
            else if (k==4 && teste1==1) printf("Registro ausente para alteracao\n");
            k++;
         }  
         
    }
    
    fgets(entrada, 52, stdin);
    entrada[strlen(entrada)-1] = '\0';
    
  }
}
