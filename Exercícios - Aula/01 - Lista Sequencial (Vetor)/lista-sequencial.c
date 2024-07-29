#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ListaSequencial {
    int32_t *dados;
    uint32_t numeroElementos;
    uint32_t tamanhoDisponivel;
} ListaSequencial;

/* Essa função aloca um espaço de memória (= numeroElementos) necessário para armazenar int32. Retorna uma lista vazia (tamanho = 0) */
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

    return novaLista;
}

void adicionar_elemento(ListaSequencial *lista, int32_t elemento)
{
    /* Verificar o acesso de memória */
    if (lista->numeroElementos + 1 == lista->tamanhoDisponivel) {
        printf("[ERRO - ACESSO INDEVIDO] - HOUVE ACESSO DE UM INDICE NAO ALOCADO PARA A LISTA.\n");
        exit(1);
    }

    lista->dados[lista->numeroElementos] = elemento;
    lista->numeroElementos++;
}

/* Busca em lista não ordenada */
int pesquisa_lista(ListaSequencial *lista, int32_t elementoAlvo)
{
    for (int i = 0; i < lista->numeroElementos; i++) {
        if (lista->dados[i] == elementoAlvo) {
            return i;
        }
    }

    return -1;
}

void remover_elemento(ListaSequencial *lista, int32_t elemento)
{
    int indice = pesquisa_lista(lista, elemento);

    if (indice == -1) {
        return;
    }

    /* Trocando o último valor da lista pelo alvo */
    lista->dados[indice] = lista->dados[lista->numeroElementos - 1];
    lista->numeroElementos--;

}

void ordenar_lista(ListaSequencial *lista)
{

}

int pesquisa_binaria_lista(ListaSequencial *lista, int32_t elemento)
{

}

void remover_elemento_por_indice(ListaSequencial *lista, uint32_t indice)
{

}

void remover_elemento_por_indice_lista_ordenada(ListaSequencial *lista, uint32_t indice)
{

}

void inserir_elemento_por_indice(ListaSequencial *lista, int32_t valor, uint32_t indice)
{

}

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

int main()
{
    ListaSequencial *lista = criar_lista_sequencial(10);

    imprimir_lista(lista);

    adicionar_elemento(lista, 42);
    adicionar_elemento(lista, 27);
    adicionar_elemento(lista, 5);

    imprimir_lista(lista);

    printf("%d", pesquisa_lista(lista, 27));
    printf("\n%d", pesquisa_lista(lista, 0));

    return 0;
}
