/*
Dado um número x queremos calcular y = √x
Método Babilônico (ou de Heron):

1. Seja Y1 uma estimativa para y = √x
    – Por exemplo, Y1 = x
    – Quanto melhor a estimativa, mais rápido o algoritmo

2. Faça Yn = 1/2 * [ Yn−1 + x / (Yn−1) ]

3. Se |Yn − Yn−1| for “grande”, volte para 2 -> use o ERRO = 1e-12

4. Devolva Yn
*/

#include <stdio.h>
#include <math.h>

#define ERRO 1e-12

double raiz_quadrada(double x) {
    double y = x, anterior;
    do {
        anterior = y;
        y = (y + x / y) / 2;
    } while (fabs(anterior - y) > ERRO);

    return y;
}


int main()
{
    double x, resultado;

    printf("Digite um valor para calcular a raiz quadrada: ");
    scanf("%lf", &x);

    resultado = raiz_quadrada(x);

    printf("\nResultado = %lf", resultado);
    
    return 0;
}