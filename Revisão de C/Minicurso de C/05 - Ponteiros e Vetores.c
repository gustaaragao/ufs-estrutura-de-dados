#include <stdio.h>
#include <stdlib.h>

/* Escreve uma funcao que imprima um vetor (estático ou dinâmico) -> isso não importa, já que o vetor é um ponteiro */
void imprimir_vetor(double *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        printf("%lf ", vetor[i]);
    }
    printf("\n");
}

/* Escreva uma função que dado um int n, aloca um vetor de double com n posições zerado. */
double * aloca_e_zera(int n)
{
    double *v = malloc(n * sizeof(double));

    if (v == NULL) {
        printf("[ERRO] - Alocacao Dinamica nao foi possivel");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        v[i] = 0.0;
    }

    return v;
}

int main()
{
    double vetorEstatico[3] = {2, 4.2, 27};

    double *vetorDinamico = aloca_e_zera(2);

    imprimir_vetor(vetorEstatico, 3);
    imprimir_vetor(vetorDinamico, 2);

    free(vetorDinamico);

    return 0;
}
