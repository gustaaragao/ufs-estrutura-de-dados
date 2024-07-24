/*
Faça uma função que, dados m, n e k,  aloca e devolve uma matriz tridimensional m × n × k de doubles.
*/

#include <stdio.h>
#include <stdlib.h>

// Uma matriz 3x3 de doubles -> É um ponteiro que aponta para um vetor de ponteiros que apontam para vetores double[]

double ***alocar_matriz_tridimensional(int m, int n, int k)
{
    double ***matriz;

    matriz = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(double *));
        for (int j = 0; j < n; j++) {
            matriz[i][j] = malloc(k * sizeof(double));
        }
    }
    
    return matriz;
}

void liberar_matriz_tridimensional(double ***matriz, int m, int n, int k)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
}

void imprimir_matriz_tridimensional(double ***matriz, int m, int n, int k)
{
    for (int p = 0; p < m; p++) {
        for (int q = 0; q < n; q++) {
            printf("[");
            for (int r = 0; r < k; r++) {
                if (r == k - 1) {
                    printf("%.2lf", matriz[p][q][r]);
                } else {
                    printf("%.2lf, ", matriz[p][q][r]);
                }
            }
            printf("] ");
        }
        printf("\n");
    }
}

int main()
{
    int m = 2, n = 2, k = 2;
    double ***matriz = alocar_matriz_tridimensional(m, n, k);
    
    // Inicialização da matriz com valores específicos
    double valores[2][2][2] = {
        {
            {1.1, 1.2},
            {1.3, 1.4}
        },
        {
            {2.1, 2.2},
            {2.3, 2.4}
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                matriz[i][j][l] = valores[i][j][l];
            }
        }
    }

    imprimir_matriz_tridimensional(matriz, m, n, k);

    liberar_matriz_tridimensional(matriz, m, n, k);

    return 0;
}