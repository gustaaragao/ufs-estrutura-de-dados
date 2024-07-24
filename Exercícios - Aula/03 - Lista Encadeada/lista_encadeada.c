#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lista_encadeada.h"
/*
Perguntas pertinentes:
- Pq usar Alocação Dinâmica de Memória?
    -> Alocacao do Elemento e Alocacao da Lista
*/

ListaEncadeada* inicializar_lista()
{
    ListaEncadeada *novaLista = malloc(sizeof(ListaEncadeada));

    if (novaLista == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA");
        exit(1);
    }

    novaLista->inicio = NULL;

    return novaLista;
}

void adicionar_elemento_final(ListaEncadeada *lista, uint32_t novoValor)
{
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO");
        exit(1);
    }

    novoElemento->valor = novoValor, novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        /* A Lista não foi inicializada */
        lista->inicio = novoElemento;
    } else {
        /* Lista inicializada -> Precisamos buscar a cabeça da lista. */
        Elemento *elemento = lista->inicio;

        while (elemento->proximo != NULL) {
            elemento = elemento->proximo;
        }

        elemento->proximo = novoElemento;
    }
}

void adicionar_elemento_inicio(ListaEncadeada *lista, uint32_t novoValor)
{
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO");
        exit(1);
    }

    novoElemento->valor = novoValor, novoElemento->proximo = lista->inicio;

    lista->inicio = novoElemento;
}

void remover_elemento_fim(ListaEncadeada *lista)
{

}

void remover_elemento_inicio(ListaEncadeada *lista)
{
    
}

void destruir_lista(ListaEncadeada *lista)
{

}

int pesquisar_valor(ListaEncadeada *lista, uint32_t valor)
{

}

void adicionar_elemento_por_indice(ListaEncadeada *lista, uint32_t index)
{

}

void remover_elemento_por_indice(ListaEncadeada *lista, uint32_t index)
{
    
}

uint32_t tamanhoLista(ListaEncadeada *lista, uint32_t index)
{

}

void ordenar_lista(ListaEncadeada *lista)
{

}

void inserir_lista_ordenada(ListaEncadeada *lista, uint32_t valor)
{

}

void imprimir_lista(ListaEncadeada *lista)
{
    Elemento *elemento = lista->inicio;

    printf("[");
    while (elemento != NULL) {
        if (elemento->proximo) {
            printf("%d, ", elemento->valor);
        } else {
            printf("%d", elemento->valor);
        }
        elemento = elemento->proximo;
    }
    printf("]\n");
}

int main()
{
    ListaEncadeada *novaLista = inicializar_lista();
    
    adicionar_elemento_final(novaLista, 1);
    adicionar_elemento_final(novaLista, 2);
    adicionar_elemento_final(novaLista, 3);

    imprimir_lista(novaLista);

    adicionar_elemento_inicio(novaLista, 42);

    imprimir_lista(novaLista);
    
    return 0;
}