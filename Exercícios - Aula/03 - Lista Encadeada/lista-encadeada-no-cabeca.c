#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Elemento {
    uint32_t valor;
    struct Elemento *proximo;
} Elemento;

typedef struct ListaEncadeada {
    Elemento *inicio;
    Elemento *fim;
    uint32_t tamanho;
} ListaEncadeada;

/**
 * Inicializa uma lista encadeada vazia.
 * 
 * @return ListaEncadeada* Ponteiro para a nova lista encadeada.
 */
ListaEncadeada* inicializar_lista() {
    ListaEncadeada *novaLista = malloc(sizeof(ListaEncadeada));

    if (novaLista == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA.\n");
        return NULL;
    }

    novaLista->inicio = NULL;
    novaLista->fim = NULL;
    novaLista->tamanho = 0;

    return novaLista;
}

/**
 * Destrói a lista encadeada e libera a memória alocada.
 * 
 * @param lista Ponteiro para a lista a ser destruída.
 */
void destruir_lista(ListaEncadeada *lista) {
    Elemento *elemento = lista->inicio;

    while (elemento != NULL) {
        Elemento *proximoElemento = elemento->proximo;
        free(elemento);
        elemento = proximoElemento;
    }

    free(lista);
}

/**
 * Adiciona um elemento ao final da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param novoValor Valor a ser adicionado.
 * @return int Retorna 0 se bem-sucedido, 1 se houve erro de alocação.
 */
int adicionar_elemento_final(ListaEncadeada *lista, uint32_t novoValor) {
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        return 1;
    }

    novoElemento->valor = novoValor;
    novoElemento->proximo = NULL;

    if (lista->fim == NULL) {
        // A lista está vazia
        lista->inicio = novoElemento;
        lista->fim = novoElemento;
    } else {
        // Adiciona no final
        lista->fim->proximo = novoElemento;
        lista->fim = novoElemento;
    }

    lista->tamanho++;
    return 0;
}

/**
 * Adiciona um elemento ao início da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param novoValor Valor a ser adicionado.
 * @return int Retorna 0 se bem-sucedido, 1 se houve erro de alocação.
 */
int adicionar_elemento_inicio(ListaEncadeada *lista, uint32_t novoValor) {
    Elemento *novoElemento = malloc(sizeof(Elemento));

    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        return 1;
    }

    novoElemento->valor = novoValor;
    novoElemento->proximo = lista->inicio;
    lista->inicio = novoElemento;

    if (lista->fim == NULL) {
        // A lista estava vazia
        lista->fim = novoElemento;
    }

    lista->tamanho++;
    return 0;
}

/**
 * Adiciona um elemento na lista de forma ordenada (em ordem crescente).
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param valor Valor a ser inserido.
 * @return int 0 em caso de sucesso, 1 em caso de erro (como alocação de memória).
 */
int adicionar_elemento_lista_ordenada(ListaEncadeada *lista, uint32_t valor) {
    Elemento *novoElemento = malloc(sizeof(Elemento));
    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
        return 1;
    }

    novoElemento->valor = valor;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL || lista->inicio->valor >= valor) {
        novoElemento->proximo = lista->inicio;
        lista->inicio = novoElemento;
        if (lista->fim == NULL) {
            lista->fim = novoElemento;
        }
    } else {
        Elemento *atual = lista->inicio;
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }
        novoElemento->proximo = atual->proximo;
        atual->proximo = novoElemento;
        if (novoElemento->proximo == NULL) {
            lista->fim = novoElemento;
        }
    }

    lista->tamanho++;
    return 0;
}

/**
 * Remove o último elemento da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @return int Retorna 0 se bem-sucedido, 1 se a lista está vazia.
 */
int remover_elemento_fim(ListaEncadeada *lista) {
    if (lista->inicio == NULL) {
        printf("[ERRO] - LISTA VAZIA.\n");
        return 1;
    }

    Elemento *elemento = lista->inicio;
    Elemento *elementoAnterior = NULL;

    while (elemento->proximo != NULL) {
        elementoAnterior = elemento;
        elemento = elemento->proximo;
    }

    if (elementoAnterior == NULL) {
        // Só havia um elemento
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        elementoAnterior->proximo = NULL;
        lista->fim = elementoAnterior;
    }

    free(elemento);
    lista->tamanho--;
    return 0;
}

/**
 * Remove o primeiro elemento da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @return int Retorna 0 se bem-sucedido, 1 se a lista está vazia.
 */
int remover_elemento_inicio(ListaEncadeada *lista) {
    if (lista->inicio == NULL) {
        printf("[ERRO] - LISTA VAZIA.\n");
        return 1;
    }

    Elemento *primeiroElemento = lista->inicio;
    lista->inicio = primeiroElemento->proximo;

    if (lista->inicio == NULL) {
        // A lista ficou vazia
        lista->fim = NULL;
    }

    free(primeiroElemento);
    lista->tamanho--;
    return 0;
}

/**
 * Pesquisa um valor na lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param valor Valor a ser pesquisado.
 * @return int Índice do valor encontrado ou -1 se não encontrado.
 */
int pesquisar_valor(ListaEncadeada *lista, uint32_t valor) {
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

/**
 * Retorna o tamanho da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @return uint32_t Tamanho da lista.
 */
uint32_t tamanho_lista(ListaEncadeada *lista) {
    return lista->tamanho;
}

/**
 * Adiciona um elemento em um índice específico da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param valor Valor a ser adicionado.
 * @param indice Índice onde o elemento será inserido.
 * @return int Retorna 0 se bem-sucedido, 1 se o índice está fora dos limites.
 */
int adicionar_elemento_por_indice(ListaEncadeada *lista, uint32_t valor, uint32_t indice) {
    if (indice > lista->tamanho) {
        // O índice está fora dos limites
        return 1;
    }

    if (indice == lista->tamanho) {
        // Adiciona no final
        return adicionar_elemento_final(lista, valor);
    } else if (indice == 0) {
        // Adiciona no início
        return adicionar_elemento_inicio(lista, valor);
    } else {
        // Adiciona no meio
        Elemento *novoElemento = malloc(sizeof(Elemento));
        if (novoElemento == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA NOVO ELEMENTO.\n");
            return 1;
        }
        novoElemento->valor = valor;

        Elemento *elemento = lista->inicio;
        Elemento *elementoAnterior = NULL;

        while (indice > 0) {
            elementoAnterior = elemento;
            elemento = elemento->proximo;
            indice--;
        }

        novoElemento->proximo = elemento;
        elementoAnterior->proximo = novoElemento;

        lista->tamanho++;
        return 0;
    }
}

/**
 * Remove um elemento de um índice específico da lista.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param indice Índice do elemento a ser removido.
 * @return int Retorna 0 se bem-sucedido, 1 se o índice está fora dos limites.
 */
int remover_elemento_por_indice(ListaEncadeada *lista, uint32_t indice) {
    if (indice >= lista->tamanho) {
        printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
        return 1;
    }

    if (indice == 0) {
        // Remove o primeiro elemento
        return remover_elemento_inicio(lista);
    } else {
        Elemento *elemento = lista->inicio;
        Elemento *elementoAnterior = NULL;

        while (indice > 0) {
            elementoAnterior = elemento;
            elemento = elemento->proximo;
            indice--;
        }

        elementoAnterior->proximo = elemento->proximo;
        if (elemento->proximo == NULL) {
            // Atualiza o fim da lista se necessário
            lista->fim = elementoAnterior;
        }

        free(elemento);
        lista->tamanho--;
        return 0;
    }
}

/**
 * Atualiza o valor de um elemento em um índice específico.
 * 
 * @param lista Ponteiro para a lista encadeada.
 * @param valor Novo valor a ser atribuído.
 * @param indice Índice do elemento a ser atualizado.
 * @return int Retorna 0 se bem-sucedido, 1 se o índice está fora dos limites.
 */
int atualizar_valor(ListaEncadeada *lista, uint32_t valor, uint32_t indice) {
    if (indice >= lista->tamanho) {
        printf("[ERRO] - INDICE FORA DA FAIXA DA LISTA.\n");
        return 1;
    }

    Elemento *elemento = lista->inicio;

    while (indice > 0) {
        elemento = elemento->proximo;
        indice--;
    }

    elemento->valor = valor;
    return 0;
}

/**
 * Ordena a lista encadeada em ordem crescente usando o algoritmo Insertion Sort.
 * 
 * @param lista Ponteiro para a lista encadeada.
 */
void ordenar_lista(ListaEncadeada *lista) {
    ListaEncadeada *listaOrdenada = inicializar_lista();

    if (listaOrdenada == NULL) {
        printf("[ERRO] - FALHA AO CRIAR LISTA AUXILIAR PARA ORDENACAO.\n");
        return;
    }

    Elemento *elementoAtual = lista->inicio;

    while (elementoAtual != NULL) {
        adicionar_elemento_lista_ordenada(listaOrdenada, elementoAtual->valor);
        elementoAtual = elementoAtual->proximo;
    }

    destruir_lista(lista);
    lista->inicio = listaOrdenada->inicio;
    lista->fim = listaOrdenada->fim;
    lista->tamanho = listaOrdenada->tamanho;
    free(listaOrdenada);
}

/**
 * Imprime os elementos da lista encadeada.
 * 
 * @param lista Ponteiro para a lista encadeada.
 */
void imprimir_lista(ListaEncadeada *lista) {
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

int main() {
    ListaEncadeada *lista = inicializar_lista();
    if (lista == NULL) {
        return 1;
    }

    int opcao;
    uint32_t valor, indice;

    do {
        printf("\n===== MENU =====\n");
        imprimir_lista(lista);
        printf("1. Adicionar elemento no final\n");
        printf("2. Adicionar elemento no inicio\n");
        printf("3. Adicionar elemento de forma ordenada\n");
        printf("4. Adicionar elemento por indice\n");
        printf("5. Remover elemento do fim\n");
        printf("6. Remover elemento do inicio\n");
        printf("7. Remover elemento por indice\n");
        printf("8. Pesquisar valor\n");
        printf("9. Tamanho da lista\n");
        printf("10. Atualizar valor por indice\n");
        printf("11. Ordenar lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser adicionado no final: ");
                scanf("%u", &valor);
                adicionar_elemento_final(lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser adicionado no inicio: ");
                scanf("%u", &valor);
                adicionar_elemento_inicio(lista, valor);
                break;
            case 3:
                printf("Digite o valor a ser adicionado de forma ordenada: ");
                scanf("%u", &valor);
                adicionar_elemento_lista_ordenada(lista, valor);
                break;
            case 4:
                printf("Digite o valor a ser adicionado: ");
                scanf("%u", &valor);
                printf("Digite o indice onde o valor deve ser inserido: ");
                scanf("%u", &indice);
                adicionar_elemento_por_indice(lista, valor, indice);
                break;
            case 5:
                remover_elemento_fim(lista);
                break;
            case 6:
                remover_elemento_inicio(lista);
                break;
            case 7:
                printf("Digite o indice do elemento a ser removido: ");
                scanf("%u", &indice);
                remover_elemento_por_indice(lista, indice);
                break;
            case 8:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%u", &valor);
                indice = pesquisar_valor(lista, valor);
                if (indice != -1) {
                    printf("Valor encontrado no indice %d\n", indice);
                } else {
                    printf("Valor nao encontrado\n");
                }
                break;
            case 9:
                printf("Tamanho da lista: %u\n", tamanho_lista(lista));
                break;
            case 10:
                printf("Digite o novo valor: ");
                scanf("%u", &valor);
                printf("Digite o indice do valor a ser atualizado: ");
                scanf("%u", &indice);
                atualizar_valor(lista, valor, indice);
                break;
            case 11:
                ordenar_lista(lista);
                break;
            case 0:
                destruir_lista(lista);
                printf("Lista destruida. Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
