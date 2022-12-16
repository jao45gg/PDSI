#include <stdio.h>
#include <string.h>

int main (void) {

   int cont = 0;
   char controle, nome[99];
   long int matriz [5][5], matriz1 [5][5];
   
   fgets(nome, 99, stdin);
   nome[strlen(nome)-1] = '\0';
  
  FILE *arquivo = fopen(nome, "rb");
   
  while (cont != 10){  
    
        for (int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                    fscanf(arquivo, "%ld", &matriz[i][j]);
            }
            cont++;
        }
        for (int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                fscanf(arquivo, "%ld", &matriz1[x][y]);
            }
            cont++;
        }
  }
  fclose(arquivo);
  for (int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            printf(" %ld", matriz[a][b]+matriz1[a][b]);
        }
        printf("\n");
    }
}