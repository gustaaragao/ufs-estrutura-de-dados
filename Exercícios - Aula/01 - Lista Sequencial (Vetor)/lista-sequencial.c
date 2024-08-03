#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ListaSequencial {
    int32_t *dados;
    uint32_t numeroElementos;
    uint32_t tamanhoDisponivel;
} ListaSequencial;

/**
 * Cria uma nova lista sequencial vazia com um tamanho especificado.
 *
 * @param tamanho O tamanho inicial disponível para a lista.
 * @return Um ponteiro para a nova lista sequencial.
 */
ListaSequencial* criar_lista_sequencial(uint32_t tamanho)
{
    ListaSequencial *novaLista = (ListaSequencial*) malloc(sizeof(ListaSequencial));

    if (novaLista == NULL) {
        printf("[ERRO - ALOCACAO MEMORIA] - NAO FOI POSSIVEL CRIAR A NOVA LISTA.\n");
        exit(1);
    }

    novaLista->tamanhoDisponivel = tamanho;
    novaLista->numeroElementos = 0;
    novaLista->dados = (int32_t*) malloc(tamanho * sizeof(int32_t));

    if (novaLista->dados == NULL) {
        printf("[ERRO - ALOCACAO MEMORIA] - NAO FOI POSSIVEL CRIAR A NOVA LISTA.\n");
        exit(1);
    }

    return novaLista;
}

/**
 * Adiciona um elemento ao final da lista não ordenada.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elemento O elemento a ser adicionado.
 * @return 0 em caso de sucesso, 1 se a lista estiver cheia.
 */
int adicionar_elemento(ListaSequencial *lista, int32_t elemento)
{
    if (lista->numeroElementos == lista->tamanhoDisponivel) {
        printf("[ERRO - ACESSO INDEVIDO] - HOUVE ACESSO DE UM INDICE NAO ALOCADO PARA A LISTA.\n");
        return 1;
    }

    lista->dados[lista->numeroElementos] = elemento;
    lista->numeroElementos++;

    return 0;
}

/**
 * Pesquisa sequencialmente por um elemento na lista.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elementoAlvo O elemento a ser procurado.
 * @return O índice do elemento encontrado ou -1 se não encontrado.
 */
int pesquisa_lista(ListaSequencial *lista, int32_t elementoAlvo)
{
    for (int i = 0; i < lista->numeroElementos; i++) {
        if (lista->dados[i] == elementoAlvo) {
            return i;
        }
    }

    return -1;
}

/**
 * Remove um elemento de uma lista não ordenada, trocando-o pelo último elemento.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elemento O elemento a ser removido.
 */
void remover_elemento_lista_nao_ordenada(ListaSequencial *lista, int32_t elemento)
{
    int indice = pesquisa_lista(lista, elemento);

    if (indice == -1) {
        return;
    }

    lista->dados[indice] = lista->dados[lista->numeroElementos - 1];
    lista->numeroElementos--;
}

/**
 * Ordena a lista sequencial usando o algoritmo de seleção.
 *
 * @param lista Ponteiro para a lista sequencial.
 */
void ordenar_lista(ListaSequencial *lista)
{
    if (lista->numeroElementos == 0 || lista->numeroElementos == 1) {
        return;
    }

    for (int i = 0; i < lista->numeroElementos; i++) {
        int32_t menorIndice = i;
        for (int j = i + 1; j < lista->numeroElementos; j++) {
            if (lista->dados[j] < lista->dados[menorIndice]) {
                menorIndice = j;
            }
        }
        int32_t temp = lista->dados[i];
        lista->dados[i] = lista->dados[menorIndice];
        lista->dados[menorIndice] = temp; 
    }
}

/**
 * Adiciona um elemento à lista, mantendo a ordem.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elemento O elemento a ser adicionado.
 * @return 0 em caso de sucesso, 1 se a lista estiver cheia.
 */
int adicionar_elemento_lista_ordenada(ListaSequencial *lista, int32_t elemento)
{
    if (lista->numeroElementos == lista->tamanhoDisponivel) {
        printf("[ERRO] - Espaco alocado insuficiente para adicao de um novo elemento.\n");
        return 1;
    }

    for (int i = 0; i < lista->numeroElementos; i++) {
        if (lista->dados[i] > elemento) {
            int32_t alvoMover = lista->dados[i];
            for (int j = i + 1; j <  lista->numeroElementos + 1; j++) {
                int32_t temp = lista->dados[j]; 
                lista->dados[j] = alvoMover;
                alvoMover = temp;
            }
            lista->dados[i] = elemento;
            lista->numeroElementos++;

            return 0;
        }
    }

    lista->dados[lista->numeroElementos] = elemento;
    lista->numeroElementos++;

    return 0;
}

/**
 * Realiza uma busca binária por um elemento em uma lista ordenada.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elemento O elemento a ser procurado.
 * @return O índice do elemento encontrado ou -1 se não encontrado.
 */
int pesquisa_binaria(ListaSequencial *lista, int32_t elemento) {
    if (lista->numeroElementos == 0) {
        return -1;
    }
    
    int inicio = 0;
    int fim = lista->numeroElementos - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (elemento == lista->dados[meio]) {
            return meio;
        } else if (elemento < lista->dados[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

/**
 * Remove um elemento de uma lista ordenada, mantendo a ordem.
 *
 * @param lista Ponteiro para a lista sequencial.
 * @param elemento O elemento a ser removido.
 */
void remover_elemento_lista_ordenada(ListaSequencial *lista, int32_t elemento) {
    int indice = pesquisa_binaria(lista, elemento);

    if (indice == -1) {
        return;
    }

    for (int i = indice; i < lista->numeroElementos - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->numeroElementos--;
}

/**
 * Imprime os elementos da lista no formato [e1, e2, e3, ...].
 *
 * @param lista Ponteiro para a lista sequencial.
 */
void imprimir_lista(ListaSequencial *lista)
{
    printf("[");
    for (int i = 0; i < lista->numeroElementos; i++) {
        if (i == lista->numeroElementos - 1) {
            printf("%d", lista->dados[i]);
        } else {
            printf("%d, ", lista->dados[i]);
        }
    }
    printf("]\n");
}

/**
 * Destrói a lista sequencial e libera a memória alocada.
 *
 * @param lista Ponteiro para a lista sequencial a ser destruída.
 */
void destruir_lista(ListaSequencial *lista)
{
    if (lista != NULL) {
        free(lista->dados);
        lista->dados = NULL;

        free(lista);
        lista = NULL;
    }
}

int main() {
    ListaSequencial *lista = criar_lista_sequencial(10);
    int opcao, elemento;

    do {
        printf("\nLista atual: ");
        imprimir_lista(lista);

        printf("\nMenu de Operacoes:\n");
        printf("1. Adicionar Elemento\n");
        printf("2. Remover Elemento (Nao Ordenada)\n");
        printf("3. Ordenar Lista\n");
        printf("4. Adicionar Elemento (Ordenada)\n");
        printf("5. Remover Elemento (Ordenada)\n");
        printf("6. Pesquisar Elemento\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser adicionado: ");
                scanf("%d", &elemento);
                adicionar_elemento(lista, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                remover_elemento_lista_nao_ordenada(lista, elemento);
                break;
            case 3:
                ordenar_lista(lista);
                printf("Lista ordenada.\n");
                break;
            case 4:
                printf("Digite o elemento a ser adicionado (ordem): ");
                scanf("%d", &elemento);
                adicionar_elemento_lista_ordenada(lista, elemento);
                break;
            case 5:
                printf("Digite o elemento a ser removido (ordem): ");
                scanf("%d", &elemento);
                remover_elemento_lista_ordenada(lista, elemento);
                break;
            case 6:
                printf("Digite o elemento a ser pesquisado: ");
                scanf("%d", &elemento);
                int indice = pesquisa_binaria(lista, elemento);
                if (indice != -1) {
                    printf("Elemento encontrado na posicao %d.\n", indice);
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;
            case 7:
                destruir_lista(lista);
                printf("Saindo e destruindo a lista...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 7);

    return 0;
}