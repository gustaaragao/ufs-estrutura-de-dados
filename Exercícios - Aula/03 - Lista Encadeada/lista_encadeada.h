#include <stdint.h>

typedef struct Elemento {
    uint32_t valor;

    /* Recursividade Estrutural */
    struct Elemento* proximo;
} Elemento;

typedef struct ListaEncadeada {
    Elemento *inicio;
} ListaEncadeada;