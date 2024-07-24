#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

Matriz matriz_nova(int linhas, int colunas , double elementos[][MATRIZ_MAX])
{
    Matriz m;
    m.nLinhas = linhas, m.nColunas = colunas;

    for (int i = 0; i < m.nLinhas; i++) {
        for (int j = 0; j < m.nColunas; j++) {
            m.elementos[i][j] = elementos[i][j];
        }
    }

    return m;
}

void imprimir_matriz(Matriz m)
{
    for (int i = 0; i < m.nLinhas; i++) {
        for (int j = 0; j < m.nColunas; j++) {
            printf("%.2lf ", m.elementos[i][j]);
        }
        printf("\n");
    }
}

Matriz soma_matrizes(Matriz m1, Matriz m2)
{
    if (m1.nLinhas == m2.nLinhas && m1.nColunas == m2.nColunas) {
        Matriz soma;
        soma.nLinhas = m1.nLinhas, soma.nColunas = m1.nColunas;

        for (int i = 0; i < soma.nLinhas; i++) {
            for (int j = 0; j < soma.nColunas; j++) {
                soma.elementos[i][j] = m1.elementos[i][j] + m2.elementos[i][j];
            }
        }

        return soma;
    
    } else {
        printf("\n[ERRO] - Soma de Matrizes Invalidas (Ordem de m1 e m2 são diferentes).");
        exit(1);
    }
}

Matriz multiplicacao_matrizes(Matriz m1, Matriz m2)
{
    if (m1.nColunas == m2.nLinhas) {
        Matriz multiplicao;
        multiplicao.nLinhas = m1.nLinhas, multiplicao.nColunas = m2.nColunas;

        for (int i = 0; i < m1.nLinhas; i++) {
            for (int j = 0; j < m2.nColunas; j++) {
                multiplicao.elementos[i][j] = 0;

                for (int k = 0; k < m1.nColunas; k ++) {
                    multiplicao.elementos[i][j] += m1.elementos[i][k] * m2.elementos[k][j];  
                }
            }
        }

        return multiplicao;

    } else {
        printf("\n[ERRO] - Multiplicao de Matrizes Invalidas (Numero de Colunas de m1 != Numero de Linhas de m2).");
        exit(1);
    }
}

Matriz multiplicacao_por_escalar_matrizes(Matriz m, double escalar)
{
    Matriz multiplicaoEscalar = m;

    for (int i = 0; i < multiplicaoEscalar.nLinhas; i++) {
        for (int j = 0; j < multiplicaoEscalar.nColunas; j++) {
            multiplicaoEscalar.elementos[i][j] *= escalar;
        }
    }

    return multiplicaoEscalar;
}