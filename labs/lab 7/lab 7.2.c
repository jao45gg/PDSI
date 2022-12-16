#include <stdio.h>
#include <string.h>

int main (void) {
    
   int cont = 0;
   char controle, nome[99];
   
   fgets(nome, 99, stdin);
   nome[strlen(nome)-1] = '\0';
  
  FILE *arquivo = fopen(nome, "rb");
   
  while ( (controle = fgetc(arquivo)) != EOF ){  
    
        if (controle == 'a')
        cont++;

  }
    
    printf("%d\n", cont);
    fclose(arquivo);
    
}