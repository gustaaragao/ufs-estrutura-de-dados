    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    // #include "lista_encadeada.h"

    /*
    Perguntas pertinentes:
    - Pq usar Alocação Dinâmica de Memória?
        -> Alocacao do Elemento e Alocacao da Lista
    */

    typedef struct Elemento {
        uint32_t valor;

        /* Recursividade Estrutural */
        struct Elemento* proximo;
    } Elemento;

    typedef struct ListaEncadeada {
        Elemento *inicio;
    } ListaEncadeada;

    ListaEncadeada* inicializar_lista()
    {
        ListaEncadeada *novaLista = malloc(sizeof(ListaEncadeada));

        if (novaLista == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA.\n");
            exit(1);
        }

        novaLista->inicio = NULL;

        return novaLista;
    }

    void adicionar_elemento_final(ListaEncadeada *lista, uint32_t novoValor)
    {
        Elemento *novoElemento = malloc(sizeof(Elemento));

        if (novoElemento == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
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
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
            exit(1);
        }

        novoElemento->valor = novoValor, novoElemento->proximo = lista->inicio;

        lista->inicio = novoElemento;
    }

    void remover_elemento_fim(ListaEncadeada *lista)
    {
        if (lista->inicio != NULL) {
            /* A lista não é vazia */
            Elemento *elemento = lista->inicio;
            Elemento *elementoAnterior = NULL;

            /* Buscar a cabeça da lista */
            while (elemento->proximo != NULL) {
                elementoAnterior = elemento;
                elemento = elemento->proximo;
            }

            if (elementoAnterior == NULL) {
                /* A lista só havia um elemento */
                lista->inicio = NULL;
            } else {
                /* A lista tem mais de um elemento */
                elementoAnterior->proximo = NULL;
            }

            /* Liberando espaço de memória */
            free(elemento);
        }
    }

    void remover_elemento_inicio(ListaEncadeada *lista)
    {
        Elemento *primeiroElemento = lista->inicio;

        lista->inicio = primeiroElemento->proximo;

        free(primeiroElemento);
    }

    int pesquisar_valor(ListaEncadeada *lista, uint32_t valor)
    {
        int indice = 0;

        Elemento *elemento = lista->inicio;

        if (elemento != NULL) {
            /* A lista não é vazia. */
            if (elemento->valor == valor) {
                /* O primeiro elemento é o que estamos buscando */
                return indice;
            }

            while (elemento->proximo != NULL) {
                indice++;
                elemento = elemento->proximo;
                if (elemento->valor == valor) {
                    return indice;
                }
            }

            return -1;

        } else {
            /* A lista é vazia. */
            return -1;
        }
    }

    uint32_t tamanho_lista(ListaEncadeada *lista)
    {
        int tamanho = 0;

        Elemento *elemento = lista->inicio;

        while (elemento != NULL) {
            tamanho++;
            elemento = elemento->proximo;
        }

        return tamanho;
    }

    void adicionar_elemento_por_indice(ListaEncadeada *lista, uint32_t valor, uint32_t indice)
    {
        int tamanho = tamanho_lista(lista);

        if (indice >= tamanho) {
            printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.");
            exit(1);
        }

        Elemento *novoElemento = malloc(sizeof(Elemento));
        if (novoElemento == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
            exit(1);
        }
        /* Atribuindo o valor ao novoElemento */
        novoElemento->valor = valor;

        /* Decidindo onde posicionar o novoElemento */
        if (indice == 0) {
            novoElemento->proximo = lista->inicio;
            lista->inicio = novoElemento;
        } else {
            Elemento *elemento = lista->inicio;
            Elemento *elementoAnterior = NULL;
            
            while (indice > 0) {
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

        if (indice >= tamanho) {
            printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
            exit(1);
        }

        if (indice == 0) {
            Elemento *primeiroElemento = lista->inicio;

            lista->inicio = primeiroElemento->proximo;
        
            free(primeiroElemento);
        } else {
            Elemento *elemento = lista->inicio;
            Elemento *elementoAnterior = NULL;

            while (indice > 0) {
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

        if (indice >= tamanho) {
            printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
            exit(1);
        }

        Elemento *elemento = lista->inicio;

        while (indice > 0) {
            elemento = elemento->proximo;
            indice--;
        }

        elemento->valor = valor;
    }

    void ordenar_lista(ListaEncadeada *lista)
    {
           
    }

    void inserir_lista_ordenada(ListaEncadeada *lista, uint32_t valor)
    {

    }

    void destruir_lista(ListaEncadeada *lista)
    {
        Elemento *elemento = lista->inicio;

        while (elemento != NULL) {
            Elemento *proximoElemento = elemento->proximo;
            free(elemento);
            elemento = proximoElemento;
        }

        free(lista);
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
        ListaEncadeada *lista = inicializar_lista();
        
        adicionar_elemento_final(lista, 1);
        adicionar_elemento_final(lista, 2);
        adicionar_elemento_final(lista, 3);
        adicionar_elemento_final(lista, 4);
        adicionar_elemento_final(lista, 5);

        imprimir_lista(lista);

        adicionar_elemento_inicio(lista, 42);

        imprimir_lista(lista);

        remover_elemento_fim(lista);

        imprimir_lista(lista);

        remover_elemento_inicio(lista);

        imprimir_lista(lista);

        printf("Buscando o valor [1]: %d", pesquisar_valor(lista, 1));
        printf("\nBuscando o valor [2]: %d", pesquisar_valor(lista, 2));
        printf("\nBuscando o valor [42]: %d", pesquisar_valor(lista, 42));

        printf("\nTamanho da Lista: %d", tamanho_lista(lista));

        printf("\nAdicionando Elemento [42] na posição 2: ");
        adicionar_elemento_por_indice(lista, 42, 2);
        imprimir_lista(lista);

        printf("\nAdicionando Elemento na posição 2: ");
        remover_elemento_por_indice(lista, 2);
        imprimir_lista(lista);

        printf("\nAtualizando o valor na posição 1: ");
        atualizar_valor(lista, 42, 1);
        imprimir_lista(lista);

        return 0;
    }