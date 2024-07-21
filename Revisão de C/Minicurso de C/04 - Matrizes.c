#include <stdio.h>
#include "matrizes.h"

int main()
{
    Matriz m1, m2;

    double elementosM1[MATRIZ_MAX][MATRIZ_MAX] = {{3, 5}, {1, 2}};
    double elementosM2[MATRIZ_MAX][MATRIZ_MAX] = {{2, -5}, {-1, 3}};
    
    m1 = matriz_nova(2, 2, elementosM1);
    m2 = matriz_nova(2, 2, elementosM2);

    printf("m1:\n");
    imprimir_matriz(m1);
    
    printf("\nm2:\n");
    imprimir_matriz(m2);

    printf("\nSoma m1 e m2:\n");
    imprimir_matriz(soma_matrizes(m1, m2));
    
    printf("\nMultiplicao m1 e m2:\n");
    imprimir_matriz(multiplicacao_matrizes(m1, m2));
    
    printf("\nMultiplicao de m1 por 2:\n");
    imprimir_matriz(multiplicacao_por_escalar_matrizes(m1, 2));

    return 0;
}
