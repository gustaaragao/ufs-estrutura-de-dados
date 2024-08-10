#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementação da Lista Circular */

typedef struct Elemento {
    char *nome;
    struct Elemento *proximo;
} Elemento;

typedef struct ListaCircular {
    Elemento *final;
} ListaCircular;

/**
 * Inicializa uma lista circular vazia.
 * 
 * @return ListaCircular* Ponteiro para a nova lista circular.
 */
ListaCircular* inicializar_lista()
{
    ListaCircular *novaLista = malloc(sizeof(ListaCircular));

    if (novaLista == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA.\n");
        return NULL;
    }

    novaLista->final = NULL; // Define o final da lista como NULL, indicando que está vazia
    return novaLista;
}

/**
 * Adiciona um elemento a uma lista circular vazia.
 * 
 * @param lista Ponteiro para a lista circular.
 * @param nome Nome a ser adicionado ao novo elemento.
 * @return int 0 se o elemento foi adicionado com sucesso, 1 caso contrário.
 */
int adicionar_elemento_lista_vazia(ListaCircular *lista, char *nome)
{
    if (lista->final == NULL) {
        Elemento *novoElemento = malloc(sizeof(Elemento)); 
        
        if (novoElemento == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOVO ELEMENTO.\n");
            return 1;
        }

        novoElemento->nome = malloc((strlen(nome) + 1) * sizeof(char)); 
        
        if (novoElemento->nome == NULL) {
            printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOME DO NOVO ELEMENTO.\n");
            free(novoElemento);
            return 1;
        }

        strcpy(novoElemento->nome, nome);

        novoElemento->proximo = novoElemento;
        
        lista->final = novoElemento;
        
        return 0;
    } else {
        printf("[ERRO - INSERIR ELEMENTO LISTA VAZIA]: A LISTA EM QUESTAO NAO ESTA VAZIA.\n");
        return 1;
    }
}

int adicionar_elemento_no_final(ListaCircular* lista, char *nome)
{
    if (lista->final == NULL) {
        return adicionar_elemento_lista_vazia(lista, nome);
    }

    Elemento *novoElemento = malloc(sizeof(Elemento));
        
    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOVO ELEMENTO.\n");
        return 1;
    }

    novoElemento->nome = malloc((strlen(nome) + 1) * sizeof(char));

    if (novoElemento->nome == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOME DO NOVO ELEMENTO.\n");
        free(novoElemento);
        return 1;
    }

    strcpy(novoElemento->nome, nome);

    Elemento *primeiro = lista->final->proximo;

    novoElemento->proximo = primeiro;

    lista->final->proximo = novoElemento;

    lista->final = novoElemento;

    return 0;
}

int adicionar_elemento_no_inicio(ListaCircular* lista, char *nome)
{
    if (lista->final == NULL) {
        return adicionar_elemento_lista_vazia(lista, nome);
    }

    Elemento *novoElemento = malloc(sizeof(Elemento)); 
        
    if (novoElemento == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOVO ELEMENTO.\n");
        return 1;
    }

    novoElemento->nome = malloc((strlen(nome) + 1) * sizeof(char));

    if (novoElemento->nome == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOME DO NOVO ELEMENTO.\n");
        free(novoElemento);
        return 1;
    }

    strcpy(novoElemento->nome, nome);

    Elemento *primeiro = lista->final->proximo;

    novoElemento->proximo = primeiro;

    lista->final->proximo = novoElemento;

    return 0;
}

void remover_elemento_lista(ListaCircular *lista, char *nome)
{

}

void destruir_lista(ListaCircular *lista)
{

}

void exibir_lista(ListaCircular *lista)
{
    if (lista->final == NULL) {
        printf("Lista Circular Vazia.\n");
        return;
    }

    Elemento *atual = lista->final->proximo;

    do {
        printf("%s -> ", atual->nome);
        atual = atual->proximo;
    } while (atual != lista->final->proximo); 

    printf("(volta para o inicio)\n");
}

int main()
{
    ListaCircular *lista = inicializar_lista();

    adicionar_elemento_no_final(lista, "Gustavo");
    adicionar_elemento_no_final(lista, "Henrique");
    adicionar_elemento_no_final(lista, "Aragao");
    adicionar_elemento_no_final(lista, "Silva");

    exibir_lista(lista);

    return 0;
}
