#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Elemento
{
    uint32_t valor;

    /* Recursividade Estrutural */
    struct Elemento *proximo;
} Elemento;

typedef struct ListaEncadeada
{
    Elemento *inicio;
} ListaEncadeada;

ListaEncadeada *inicializar_lista()
{
    ListaEncadeada *novaLista = malloc(sizeof(ListaEncadeada));

    if (novaLista == NULL)
    {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA.\n");
        exit(1);
    }

    novaLista->inicio = NULL;

    return novaLista;
}

void destruir_lista(ListaEncadeada *lista)
{
    Elemento *elemento = lista->inicio;

    while (elemento != NULL)
    {
        Elemento *proximoElemento = elemento->proximo;
        free(elemento);
        elemento = proximoElemento;
    }
}

void adicionar_elemento_final(ListaEncadeada *lista, uint32_t novoValor)
{
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL)
    {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        exit(1);
    }

    novoElemento->valor = novoValor, novoElemento->proximo = NULL;

    if (lista->inicio == NULL)
    {
        /* A Lista está vazia */
        lista->inicio = novoElemento;
    }
    else
    {
        /* Lista inicializada -> Precisamos buscar a cabeça da lista. */
        Elemento *elemento = lista->inicio;

        while (elemento->proximo != NULL)
        {
            elemento = elemento->proximo;
        }

        elemento->proximo = novoElemento;
    }
}

void adicionar_elemento_inicio(ListaEncadeada *lista, uint32_t novoValor)
{
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL)
    {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        exit(1);
    }

    novoElemento->valor = novoValor, novoElemento->proximo = lista->inicio;

    lista->inicio = novoElemento;
}

void remover_elemento_fim(ListaEncadeada *lista)
{
    if (lista->inicio != NULL)
    {
        /* A lista não é vazia */
        Elemento *elemento = lista->inicio;
        Elemento *elementoAnterior = NULL;

        /* Buscar a cabeça da lista */
        while (elemento->proximo != NULL)
        {
            elementoAnterior = elemento;
            elemento = elemento->proximo;
        }

        if (elementoAnterior == NULL)
        {
            /* A lista só havia um elemento */
            lista->inicio = NULL;
        }
        else
        {
            /* A lista tem mais de um elemento */
            elementoAnterior->proximo = NULL;
        }

        /* Liberando espaço de memória */
        free(elemento);
    }
}

void remover_elemento_inicio(ListaEncadeada *lista)
{
    if (lista->inicio == NULL) {
        printf("[ERRO] - LISTA VAZIA.\n");
        exit(1);
    }

    Elemento *primeiroElemento = lista->inicio;

    lista->inicio = primeiroElemento->proximo;

    free(primeiroElemento);
}

int pesquisar_valor(ListaEncadeada *lista, uint32_t valor)
{
    int indice = 0;

    Elemento *elemento = lista->inicio;

    while (elemento != NULL) {
        if (elemento->valor == valor) {
            return indice;
        }
        elemento = elemento->proximo;
        indice++;
    }

    return -1;
}

uint32_t tamanho_lista(ListaEncadeada *lista)
{
    uint32_t tamanho = 0;

    Elemento *elemento = lista->inicio;

    while (elemento != NULL)
    {
        tamanho++;
        elemento = elemento->proximo;
    }

    return tamanho;
}

void adicionar_elemento_por_indice(ListaEncadeada *lista, uint32_t valor, uint32_t indice)
{
    int tamanho = tamanho_lista(lista);

    if (indice > tamanho)
    {
        printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.");
        exit(1);
    }

    Elemento *novoElemento = malloc(sizeof(Elemento));
    if (novoElemento == NULL)
    {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        exit(1);
    }
    /* Atribuindo o valor ao novoElemento */
    novoElemento->valor = valor;

    /* Decidindo onde posicionar o novoElemento */
    if (indice == 0)
    {
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    }
    else
    {
        Elemento *elemento = lista->inicio;
        Elemento *elementoAnterior = NULL;

        while (indice > 0)
        {
            elementoAnterior = elemento;
            elemento = elemento->proximo;
            indice--;
        }

        novoElemento->proximo = elemento;
        elementoAnterior->proximo = novoElemento;
    }
}

void remover_elemento_por_indice(ListaEncadeada *lista, uint32_t indice)
{
    int tamanho = tamanho_lista(lista);

    if (indice >= tamanho)
    {
        printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
        exit(1);
    }

    if (indice == 0)
    {
        Elemento *primeiroElemento = lista->inicio;

        lista->inicio = primeiroElemento->proximo;

        free(primeiroElemento);
    }
    else
    {
        Elemento *elemento = lista->inicio;
        Elemento *elementoAnterior = NULL;

        while (indice > 0)
        {
            elementoAnterior = elemento;
            elemento = elemento->proximo;
            indice--;
        }

        elementoAnterior->proximo = elemento->proximo;
        free(elemento);
    }
}

void atualizar_valor(ListaEncadeada *lista, uint32_t valor, uint32_t indice)
{
    int tamanho = tamanho_lista(lista);

    if (indice >= tamanho)
    {
        printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
        exit(1);
    }

    Elemento *elemento = lista->inicio;

    while (indice > 0)
    {
        elemento = elemento->proximo;
        indice--;
    }

    elemento->valor = valor;
}

/* Insercao Ordenada -> Inserir um novo elemento a uma lista ordenada. */
void adicionar_elemento_lista_ordenada(ListaEncadeada *lista, uint32_t novoValor)
{
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL)
    {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        exit(1);
    }

    novoElemento->valor = novoValor, novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        /* A Lista está vazia */
        lista->inicio = novoElemento;
    } else if (lista->inicio->valor >= novoValor) {
        /* Inserir no Inicio da Lista */
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
    } else {
        Elemento *elementoAtual = lista->inicio;

        while (elementoAtual->proximo != NULL && elementoAtual->proximo->valor < novoValor) {
            elementoAtual = elementoAtual->proximo;
        }

        novoElemento->proximo = elementoAtual->proximo;
        elementoAtual->proximo = novoElemento;
    }
}

/* Insertion Sort */
void ordenar_lista(ListaEncadeada *lista)
{
    ListaEncadeada *listaOrdenada = inicializar_lista();

    Elemento *elementoAtual = lista->inicio;

    while (elementoAtual != NULL) {
        adicionar_elemento_lista_ordenada(listaOrdenada, elementoAtual->valor);
        elementoAtual = elementoAtual->proximo;
    }

    destruir_lista(lista);

    lista->inicio = listaOrdenada->inicio;

    free(listaOrdenada); /* listaOrdenada é uma estrutura auxiliar -> liberar memória (deveria acabar após execucao da função)*/
}

void imprimir_lista(ListaEncadeada *lista)
{
    Elemento *elemento = lista->inicio;

    printf("[");
    while (elemento != NULL)
    {
        if (elemento->proximo)
        {
            printf("%d, ", elemento->valor);
        }
        else
        {
            printf("%d", elemento->valor);
        }
        elemento = elemento->proximo;
    }
    printf("]\n");
}

int main()
{
    ListaEncadeada *lista = inicializar_lista();

    printf("Adicionando elementos ao final da lista:\n");
    adicionar_elemento_final(lista, 42);
    adicionar_elemento_final(lista, 3);
    adicionar_elemento_final(lista, 5);
    adicionar_elemento_final(lista, 1);
    imprimir_lista(lista);

    printf("\nAdicionando elemento ao inicio da lista:\n");
    adicionar_elemento_inicio(lista, 7);
    imprimir_lista(lista);

    printf("\nRemovendo elemento do fim da lista:\n");
    remover_elemento_fim(lista);
    imprimir_lista(lista);

    printf("\nRemovendo elemento do inicio da lista:\n");
    remover_elemento_inicio(lista);
    imprimir_lista(lista);

    printf("\nPesquisando valor na lista:\n");
    printf("indice do valor 3: %d\n", pesquisar_valor(lista, 3));
    printf("indice do valor 10: %d\n", pesquisar_valor(lista, 10));

    printf("\nTamanho da lista: %d\n", tamanho_lista(lista));

    printf("\nAdicionando elemento por indice (indice 1, valor 99):\n");
    adicionar_elemento_por_indice(lista, 99, 1);
    imprimir_lista(lista);

    printf("\nRemovendo elemento por indice (indice 1):\n");
    remover_elemento_por_indice(lista, 1);
    imprimir_lista(lista);

    printf("\nAtualizando valor no indice 1 para 55:\n");
    atualizar_valor(lista, 55, 1);
    imprimir_lista(lista);

    printf("\nOrdenando lista:\n");
    ordenar_lista(lista);
    imprimir_lista(lista);

    printf("\nAdicionando elemento em lista ordenada:\n");
    adicionar_elemento_lista_ordenada(lista, 27);
    imprimir_lista(lista);


    destruir_lista(lista);
    return 0;
}