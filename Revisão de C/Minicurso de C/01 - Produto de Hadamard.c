/*
O Produto de Hadamard de dois vetores u e v é o produto ponto-a-ponto de u e v, isto é, o vetor (u1v1, u2v2, . . . , unvn).
*/


#include <stdio.h>

#define TAMANHO_MAX 100

void ler_vetor(int vetor[TAMANHO_MAX], int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++) {
        scanf("%d", &vetor[i]);
    }
}

void imprimir_vetor(int vetor[TAMANHO_MAX], int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++) {
        printf(" %d", vetor[i]);
    }
}

int somatorio_vetor(int vetor[TAMANHO_MAX], int tamanhoVetor)
{
    int soma = 0;
    for (int i = 0; i < tamanhoVetor; i++) {
        soma += vetor[i];
    }

    return soma;
}

void produto_de_hadamard(int vetorA[TAMANHO_MAX], int vetorB[TAMANHO_MAX], int vetorHadamard[TAMANHO_MAX], int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++) {
        vetorHadamard[i] = vetorA[i] * vetorB[i];
    }
}

int main() {
    int vetorA[TAMANHO_MAX], vetorB[TAMANHO_MAX], vetorHadamard[TAMANHO_MAX];

    int tamanhoVetor = 0;
    printf("Digite o tamanho do Vetor: ");
    scanf("%d", &tamanhoVetor);

    printf("\nInsira o vetor A: ");
    ler_vetor(vetorA, tamanhoVetor);

    printf("\nInsira o vetor B: ");
    ler_vetor(vetorB, tamanhoVetor);

    produto_de_hadamard(vetorA, vetorB, vetorHadamard, tamanhoVetor);

    printf("\nVetor de Hadamard:");
    imprimir_vetor(vetorHadamard, tamanhoVetor);

    int produtoEscalar = somatorio_vetor(vetorHadamard, tamanhoVetor);

    printf("\nProduto Escalar: %d", produtoEscalar);

    return 0;
}