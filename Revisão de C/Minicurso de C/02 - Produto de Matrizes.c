/*
Escreva um programa que lê duas matrizes n × n (n ≤ 10) e
calcula a multiplicação dessas matrizes.
*/

#include <stdio.h>

#define TAMANHO_MAXIMO 10

void produto_matrizes_quadradas(
    int matrizA[TAMANHO_MAXIMO][TAMANHO_MAXIMO], 
    int matrizB[TAMANHO_MAXIMO][TAMANHO_MAXIMO],
    int matrizC[TAMANHO_MAXIMO][TAMANHO_MAXIMO],
    int tamanho
)
{
    // Inicializar (zerar) a matrizC
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matrizC[i][j] = 0;
        }
    }
    
    // Calcular o produto
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            for (int k = 0; k < tamanho; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimir_matriz_quadrada(int matriz[TAMANHO_MAXIMO][TAMANHO_MAXIMO], int tamanho)
{
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ler_matriz_quadrada(int matriz[TAMANHO_MAXIMO][TAMANHO_MAXIMO], int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        printf("\nInsira a linha %d: ", i);
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main ()
{
    int matrizA[TAMANHO_MAXIMO][TAMANHO_MAXIMO], matrizB[TAMANHO_MAXIMO][TAMANHO_MAXIMO], matrizC[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

    int tamanho = 0;

    printf("Digite o tamanho da Matriz: ");
    scanf("%d", &tamanho);

    printf("\nDigite a matriz A:");
    ler_matriz_quadrada(matrizA, tamanho);

    printf("\nDigite a matriz B:");
    ler_matriz_quadrada(matrizB, tamanho);

    printf("\n=============");
    produto_matrizes_quadradas(matrizA, matrizB, matrizC, tamanho);
    imprimir_matriz_quadrada(matrizC, tamanho);

    return 0;
}