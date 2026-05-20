#include <stdio.h>
void lerMatriz(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("Elemento [%d][%d]: ",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
    }
}
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j;
    printf("\nMatriz: \n");
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}
int somatorio(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j, soma=0;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            soma+=matriz[i][j];
        }
    }
    return soma;
}
int produtorio(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j, produto=1;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            produto*=matriz[i][j];
        }
    }
    return produto;
}
void diagonalPrincipal(int linhas, int colunas, int matriz[linhas][colunas]){
    int i;
    if(linhas!=colunas){
        printf("\nA matriz nao e quadrada!\n");
        return;
    }
    printf("\nDiagonal principal: ");
    for(i=0;i<linhas;i++){
        printf("%d",matriz[i][i]);
    }
    printf("\n");
}
int maiorElemento(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j, maior=matriz[0][0];
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            if(matriz[i][j]>maior){
                maior=matriz[i][j];
            }
        }
    }
    return maior;
}
int menorElemento(int linhas, int colunas, int matriz[linhas][colunas]){
    int i, j, menor=matriz[0][0];
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            if(matriz[i][j]<menor){
                menor=matriz[i][j];
            }
        }
    }
    return menor;
}
void buscarElemento(int linhas, int colunas, int matriz[linhas][colunas], int valor){
    int i, j, encontrado=0;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            if(matriz[i][j]==valor){
                printf("\nElemento encontrado na posiçao [%d][%d]\n",i,j);
                encontrado++;
            }
        }
    }
    if(!encontrado){
        printf("\nElemento nao encontrado!\n");
    }
}
int main(){
    int linhas, colunas;
    int opcao;
    int valorBusca;
    printf("Digite o numero de linhas: ");
    scanf("%d",&linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d",&colunas);
    int matriz[linhas][colunas];
    lerMatriz(linhas, colunas, matriz);
    do{
        printf("\n===========MENU===========");
        printf("1-Imprimir matriz\n");
        printf("2-Somatorio dos elementos\n");
        printf("3-Produtorio dos elementos\n");
        printf("4-Mostrar diagonal principal\n");
        printf("5-Maior elemento\n");
        printf("6-Menor elemento\n");
        printf("7-Buscar elemento\n");
        printf("0-Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
            imprimirMatriz(linhas, colunas, matriz);
            break;
            case 2:
            printf("\nSomatorio = %d\n",somatorio(linhas, colunas, matriz));
            break;
            case 3:
            printf("\nProdutorio = %d\n",produtorio(linhas, colunas, matriz));
            break;
            case 4:
            diagonalPrincipal(linhas, colunas, matriz);
            break;
            case 5:
            printf("\nMaior elemento = %d",maiorElemento(linhas, colunas, matriz));
            break;
            case 6:
            printf("\nMenor elemento = %d",menorElemento(linhas, colunas, matriz));
            break;
            case 7:
            printf("\nDigite o elemento para buscar: ");
            scanf("%d",&valorBusca);
            buscarElemento(linhas, colunas, matriz, valorBusca);
            break;
            case 0:
            printf("\nPrograma encerrado!\n");
            break;
            default:
            printf("\nOpçao invalida!\n");
        }
    }
    while(opcao !=0);
    return 0;
}
