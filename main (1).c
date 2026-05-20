#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

float calcularIMC(float peso, float altura){
    return peso/(altura*altura);
}
void classificarIMC(float imc, char classificacao[]){
    if(imc<18.5){
        strcpy(classificacao,"Abaixo do peso");
    }
    else if(imc<25){
        strcpy(classificacao,"Peso normal");
    }
    else if(imc<30){
        strcpy(classificacao,"Sobrepeso");
    }
    else if(imc<35){
        strcpy(classificacao,"ObesidadeI");
    }
    else if(imc<40){
        strcpy(classificacao,"ObsedidadeII");
    }
    else{
        strcpy(classificacao,"ObsedidadeIII");
    }
}
int main(){
    char nomes[MAX][100];
    int idades[MAX];
    float pesos[MAX];
    float alturas[MAX];
    float imcs[MAX];
    char classificacoes[MAX][50];
    int i=0;
    char continuar ='S';
    printf("=========================================\n");
    printf("-----------------CALCULADORA DE IMC-----------------");
    printf("=========================================\n\n");
    while ((continuar=='S'||continuar=='s')&&i<MAX){
        printf("Paciente %d\n", i+1);
        printf("Digite o nome: ");
        scanf("%[^\n]",nomes[i]);
        printf("Digite a idade: ");
        scanf("%d",&idades[i]);
        printf("Digite o peso (kg): ");
        scanf("%f",&pesos[i]);
        printf("Digite a altura (m): ");
        scanf("%f",&alturas[i]);
        if (alturas[i]<=0){
            printf("Altura invalida!\n");
        }
        else{
            imcs[i]=calcularIMC(pesos[i], alturas[i]);
            classificarIMC(imcs[i], classificacoes[i]);
            i++;
            
        }
   printf("\nDeseja cadastrar outro paciente? (S/N): ");
   scanf("%c",&continuar);
   printf("\n");
    }
   printf("\n===============RELATORIO FINAL===============\n");
   printf("-----------------------------------------------\n");
   printf("|%-20s|%-5s|%-8s|%-20s|\n","Nome","Idade","IMC","Classificacao");
   printf("-----------------------------------------------\n");
   int j=0;
   while (j<i){
       printf("|%-20s|%-5d|%-8.2f|%-20s|\n",nomes[j],idades[j],imcs[j],classificacoes[j]);
       j++;
   }
   printf("------------------------------------------------\n");
   printf("\nPrograma encerrado!\n");
   return 0;
}