#include <stdio.h>

int main (int argc, char **argv) {
    
   int cont = 0;
   char controle;
   FILE *arquivo = fopen(argv[1], "r");
   
   while ( (controle = fgetc(arquivo)) != EOF ){  
    
        if (controle == 'a')
        cont++;

   }
    printf("%d\n", cont);
    fclose(arquivo);
}