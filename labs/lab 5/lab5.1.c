#include <stdio.h>
#include <string.h>
 
typedef struct {
    char nome[52];
    int idade;
    float salario;
} dados;

int main (void)
{
  
  char entrada[52] ;
  int x = 0;
  
  fgets(entrada, 52, stdin);
  entrada[strlen(entrada)-1] = '\0';
    
  while(strlen(entrada) != 0){
    
    dados pessoa[4];
    
    if( (!strcmp(entrada,"inserir")) && x < 4 ){
        
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        
        sscanf(entrada, "%s %d %f", pessoa[x].nome, &pessoa[x].idade, &pessoa[x].salario);
        printf("Registro %s %d %.2f inserido\n", pessoa[x].nome, pessoa[x].idade, pessoa[x].salario);
        x++;
    }
    else if (!strcmp(entrada,"mostrar")) {
        
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        
        int i=0,teste = 1;
        while(i<4 && teste){
            if(!strcmp(entrada,pessoa[i].nome)){
                printf("Registro %s %d %.2f\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
                teste = 0;
            } 
            else if (i==3 && teste==1) printf("Registro ausente\n");
            i++;
        }
    } 
    else if ((!strcmp(entrada,"inserir")) && x >= 4) {
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        puts("Espaco insuficiente");
    }
    
    fgets(entrada, 52, stdin);
    entrada[strlen(entrada)-1] = '\0';
    
  }
}

