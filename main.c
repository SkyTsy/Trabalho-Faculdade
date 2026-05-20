
#include <stdio.h>
#include <string.h>
#define TAM 5

float calcularDesconto(float preco, float desconto){
    float valorFinal;
    valorFinal=preco-(preco*desconto/100);
    return valorFinal;
}
int main(){
    char produtos[TAM][50];
    float precos[TAM];
    float descontos[TAM];
    float valorFinal[TAM];
    int i=0;
    char continuar='S';
    printf("==================================================\n");
    printf("--------------SISTEMA DE DECONTO--------------\n");
    printf("==================================================\n\n");
    while((continuar=='S'||continuar=='s')&&i<TAM){
        printf("Produto %d\n",i+1);
        printf("Nome do produto: ");
        scanf("%[^\n]",produtos[i]);
        printf("Preço do produto: ");
        scanf("%f",&precos[i]);
        printf("Percential de desconto: ");
        scanf("%f",&descontos[i]);
        valorFinal[i]=calcularDesconto(precos[i],descontos[i]);
        i++;
        printf("\nDeseja cadastrar outro produto? (S/N): ");
        scanf("%c",&continuar);
        printf("\n");
    }
    printf("\n===================RELATORIO FINAL====================");
    printf("--------------------------------------------------------\n");
    printf("|%-15s|%-10s|%-10s|%-10s|\n","Produto","Preço","Desconto","Valor Final");
    printf("--------------------------------------------------------\n");
    int j=0;
    while(j<i){
        printf("|%-15s|%-10.2f|%-9.2f|%-10.2f|\n",produtos[j],precos[j],descontos[j],valorFinal[j]);
        j++;
    }
printf("---------------------------------------------------------\n");
    return 0;
}