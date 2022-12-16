#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[52];
    char marca[52];
    float preco;
} produtos;

typedef struct{
    int quantidade;
    float soma_precos;
    char nome_marca[52];
} marcas;

int main(void)
{
    
    int cont = 0;
    produtos p[8];
    char entrada[52];
    marcas m[8];
    char aux2[8];
    
    for(int l = 0; l < 9; l++){
        m[l].soma_precos = 0.0;
        m[l].quantidade = 0;
        p[l].preco = 0.0;  
    }
    
    for(int i = 0; i < 8; i++){
        
        int aux = 0, aux1 = 1;
        
        fgets(entrada, 52, stdin);
        entrada[strlen(entrada)-1] = '\0';
        sscanf(entrada, "%s %s %f", p[i].nome, p[i].marca, &p[i].preco);
        
        sscanf(p[0].marca, "%s", m[0].nome_marca);
        for(int k = i; k >= 0; k--) {
            if(k!=0 && aux1 && i >= 1 && !(strcmp(p[i].marca, p[i-k].marca))){
                m[i-k].quantidade += 1;
                printf("qtnd:%d\n",m[i-k].quantidade);
                m[i-k].soma_precos += p[i].preco;
                printf("qtnd1:%f\n",m[i-k].soma_precos);
                aux1 = 0;
            } 
            else aux = 1;
        }
        if(aux && aux1){
            sscanf(p[i].marca, "%s", m[i].nome_marca);
            m[i].quantidade += 1;
            printf("qtnd2:%d\n",m[i].quantidade);
            m[i].soma_precos = p[i].preco;
            printf("qtnd3:%f\n",m[i].soma_precos);
            aux2[cont] = i;
            cont++;
        }
    }
    for(int j = 0; j < cont; j++){
        printf("%s %d\n", m[aux2[j]].nome_marca, m[aux2[j]].quantidade);
    }
    
    float media = 0;
    float soma = 0;
    for(int i = 0; i < 8; i++){
       soma += p[i].preco;
       media = soma / 8;
       if (i==7)
       printf("media total %.2f\n", media);
    }
    for(int j = 0; j < cont; j++){
        printf("media %s %.2f\n", m[aux2[j]].nome_marca, (m[aux2[j]].soma_precos/m[aux2[j]].quantidade));
    }
}