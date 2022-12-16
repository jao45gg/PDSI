#include <stdio.h>
#include <string.h>

typedef struct {
    int dia,mes,ano;
} data_t;

int calculomes (data_t b, int m[12]){
    int num = 0;
    for (int i = 0; i < b.mes-1; i++){
        num += m[i];
    }
    return num;
}

int anobissexto (data_t a) {
    if( (a.ano % 4) == 0){
        if( (a.ano % 100) == 0){
            if( (a.ano % 400) == 0){
                return 366;
            } else return 365;
        } else return 366;
    } else return 365;
}

 long int data2dias (data_t d) {
    
    long int total = 0;
    total += (d.ano * 365.25);
    
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x = anobissexto(d);
    if (x==366) 
    meses[1] = 29;
    int y = calculomes(d,meses);
    int aux = 0;
    switch (d.mes){
        case 1:
        total -= (x - (y + d.dia)); 
        break;
        case 2:
        total -= (x - (y + d.dia));
        break;
        case 3:
        total -= (x - (y + d.dia));
        break;
        case 4:
        total -= (x - (y + d.dia));
        break;
        case 5:
        total -= (x - (y + d.dia));
        break;
        case 6:
        total -= (x - (y + d.dia));
        break;
        case 7:
        total -= (x - (y + d.dia));
        break;
        case 8:
        total -= (x - (y + d.dia));
        break;
        case 9:
        total -= (x - (y + d.dia));
        break;
        case 10:
        total -= (x - (y + d.dia));
        break;
        case 11:
        total -= (x - (y + d.dia));
        break;
        case 12:
        total -= (x - (y + d.dia));
        break;
    }
    return total;
}

int main(void){
    
    data_t dataR = {17, 9, 2020};
    data_t dataD;
    char buffer[20] = "inicio";
    
    while(strlen(buffer)>1){
        
        fgets(buffer, 20, stdin);
        sscanf(buffer, "%d %d %d", &dataD.dia, &dataD.mes, &dataD.ano);
        if(strlen(buffer)<=1){
            break;
        }
        printf("%ld\n", (data2dias(dataR) - data2dias(dataD))+1);
    }
}