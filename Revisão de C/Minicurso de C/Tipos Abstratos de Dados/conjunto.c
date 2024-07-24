#include <stdio.h>
#include "conjunto.h"

/* Cria um conjunto vazio (tamanho = 0) */
Conjunto conjunto_vazio() 
{
    Conjunto c;
    
    c.tamanho = 0;
    
    return c;
}


/* Retorna 1 caso a elemento pertença ao conjunto. E, caso contrário, retorna 0. */
int conjunto_contem(Conjunto a, int elemento)
{
 
    for (int i = 0; i < a.tamanho; i++) {
        if (a.elementos[i] == elemento)
            return 1;
    }
 
    return 0;
}


/* Adiciona um elemento ao conjunto atualizando o tamanho do conjunto (Obs.: Em conjuntos, não há repetição de elementos) */
Conjunto adicionar_elemento_conjunto(Conjunto a, int elemento)
{
    Conjunto c = a;
    
    if (!conjunto_contem(c, elemento)) {
        c.elementos[c.tamanho] = elemento;
        c.tamanho++;
    }
    
    return c;
}

/* Faz a leitura de um Conjunto */
Conjunto ler_conjunto() 
{
    Conjunto c = conjunto_vazio();
    int n, x;
  
    printf("Entre com o tamanho do conjunto: ");
    scanf("%d", &n);
    
    printf("Entre com os elementos do conjunto: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        c = adicionar_elemento_conjunto(c, x);
    }

    return c;
}

/* Imprime o Conjunto */
void imprimir_conjunto(Conjunto a)
{
    printf("{");
    for (int i = 0; i < a.tamanho; i++) {
        printf("%d", a.elementos[i]);
        if (i < a.tamanho - 1) {
            printf(", ");
        }
    }    
    printf("}\n");
}

/* Calcula o conjunto Uniao AuB (Obs.: Não há repetição de elementos) */
Conjunto conjunto_uniao(Conjunto a, Conjunto b) {
    Conjunto c = a;
    
    for (int i = 0; i < b.tamanho; i++) {
        c = adicionar_elemento_conjunto(c, b.elementos[i]);
    }
    
    return c;
}

/* Conjunto Interseção entre A e B (elementos comuns entre A e B) */
Conjunto conjunto_intersecao(Conjunto a, Conjunto b)
{
    Conjunto c = conjunto_vazio();

    for (int i = 0; i < a.tamanho; i++) {
        if (conjunto_contem(b, a.elementos[i])) {
            c = adicionar_elemento_conjunto(c, a.elementos[i]);
        }
    }

    return c;
}

/* Conjunto Diferença A - B (elementos de A que não percente a B) */
Conjunto conjunto_diferenca(Conjunto a, Conjunto b)
{
    Conjunto c = conjunto_vazio();

    for (int i = 0; i < a.tamanho; i++) {
        if (!conjunto_contem(b, a.elementos[i])) {
            c = adicionar_elemento_conjunto(c, a.elementos[i]);
        }
    }
    
    return c;
}

Conjunto remover_elemento_conjunto(Conjunto a, int elemento)
{
    Conjunto c = a;
    // 1, 2, 3, 4 -> 1, "2", 3, 4 -> 1, 3, 4, 4
    for (int i  = 0; i < c.tamanho; i++) {
        if (c.elementos[i] == elemento) {
            for (int j = i; j < c.tamanho - 1; j++) {
                c.elementos[j] = c.elementos[j + 1];
            }
            
            c.tamanho--;
            
            break;
        }
    }

    return c;
}