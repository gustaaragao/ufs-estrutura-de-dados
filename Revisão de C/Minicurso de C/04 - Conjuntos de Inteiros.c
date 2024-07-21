#include <stdio.h>
#include "conjunto.h"

int main()
{
    Conjunto a, b;

    printf("Conjunto A:\n");
    a = ler_conjunto();
    imprimir_conjunto(a);
    
    printf("Conjunto B:\n");
    b = ler_conjunto();
    imprimir_conjunto(b);

    printf("\nConjunto Uniao: ");
    imprimir_conjunto(conjunto_uniao(a, b));
    
    printf("\nConjunto Intersecao: ");
    imprimir_conjunto(conjunto_intersecao(a, b));
    
    printf("\nConjunto Diferenca: ");
    imprimir_conjunto(conjunto_diferenca(a, b));
    
    printf("\nRemovendo o valor 1 do Conjunto A: ");
    imprimir_conjunto(remover_elemento_conjunto(a, 1));

    return 0;
}
