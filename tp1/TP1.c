#include <stdio.h>

int main(void)
{
    int qtnd_jogos;
    
    scanf("%d", &qtnd_jogos);
    
    for(int i=0; i < qtnd_jogos; i++){
        
        int tamanho_tabuleiro,num_jogadas,perdeu=0,linha,coluna,contador_x=0;
        int indice_inicial_linhas,indice_final_linhas,indice_inicial_colunas,indice_final_colunas;
        
        scanf("%d", &tamanho_tabuleiro);
        char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
        for(int j=0; j < tamanho_tabuleiro; j++){
            for(int k=0; k < tamanho_tabuleiro; k++){
                scanf(" %c", &tabuleiro[j][k]);
            }
        }
        
        
        scanf("%d", &num_jogadas);
        for(int t=0; t < num_jogadas; t++){
            
            scanf("%d %d", &linha, &coluna);
            if(tabuleiro[linha][coluna] == 'b')
                perdeu = 1;
                
            if(!perdeu){
                indice_inicial_linhas = linha-1 > 0 ? linha-1 : 0 ;
                indice_final_linhas = linha+1 == tamanho_tabuleiro ? linha : linha+1 ;
                indice_inicial_colunas = coluna-1 > 0 ? coluna-1 : 0 ;
                indice_final_colunas = coluna+1 == tamanho_tabuleiro ? coluna : coluna+1 ;
                
                int adjascentes_combomba = 0;
                tabuleiro[linha][coluna] = 'a';
            
                for(int l = indice_inicial_linhas; l <= indice_final_linhas; l++){
                    for(int m = indice_inicial_colunas; m <= indice_final_colunas; m++){
                        if(tabuleiro[l][m] == 'b')
                            adjascentes_combomba = 1;
                    }
                }
                
                if(!adjascentes_combomba){
                    for(int l = indice_inicial_linhas; l <= indice_final_linhas; l++){
                        for(int m = indice_inicial_colunas; m <= indice_final_colunas; m++){
                            tabuleiro[l][m] = 'a'; // a significa posicao aberta
                        }
                    }
                }
            }
        }
        
        
        if(perdeu){
            printf("PERDEU\n");
        } 
        else {
            for(int p=0; p < tamanho_tabuleiro && contador_x == 0; p++) {
                for(int v=0; v<tamanho_tabuleiro && contador_x == 0; v++) {
                    if(tabuleiro[p][v] == 'x' && contador_x == 0)
                        contador_x++; 
                }  
            }
            if(contador_x == 0){
                printf("GANHOU\n");
            } else printf("FALTOU TERMINAR\n");
        }
    }
}