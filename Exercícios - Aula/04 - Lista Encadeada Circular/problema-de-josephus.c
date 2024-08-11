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

    novaLista->final = NULL; // Define o final da lista como NULL, indicando que a lista é vazia
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

/**
 * Adiciona um elemento no final da lista circular.
 * 
 * @param lista Ponteiro para a lista circular.
 * @param nome Nome a ser adicionado ao novo elemento.
 * @return int 0 se o elemento foi adicionado com sucesso, 1 caso contrário.
 */
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

/**
 * Adiciona um elemento no início da lista circular.
 * 
 * @param lista Ponteiro para a lista circular.
 * @param nome Nome a ser adicionado ao novo elemento.
 * @return int 0 se o elemento foi adicionado com sucesso, 1 caso contrário.
 */
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

/**
 * Remove um elemento da lista circular.
 * 
 * @param lista Ponteiro para a lista circular.
 * @param nome Nome do elemento a ser removido.
 */
void remover_elemento_lista(ListaCircular *lista, char *nome)
{
    if (lista->final == NULL) {
        printf("Lista Circular Vazia.\n");
        return;
    }

    Elemento *atual = lista->final->proximo;
    Elemento *anterior = lista->final;
    
    do {
        if (strcmp(nome, atual->nome) == 0) {
            if (atual == lista->final) {
                // O elemento está no final da lista
                if (atual->proximo == atual) {
                    // A lista só tem um elemento
                    lista->final = NULL;
                } else {
                    lista->final = anterior;
                }
            }
            anterior->proximo = atual->proximo;

            free(atual->nome);
            free(atual);
            
            break;
        }

        anterior = atual;
        atual = atual->proximo;

    } while (atual != lista->final->proximo);
}

/**
 * Exibe a lista circular completa, mostrando cada elemento seguido de uma seta e indicando
 * o retorno ao início da lista.
 * 
 * @param lista Ponteiro para a lista circular.
 */
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

/**
 * Pesquisa um elemento na lista circular.
 * 
 * @param lista Ponteiro para a lista circular.
 * @param nome Nome do elemento a ser pesquisado.
 * @return int Posição do elemento na lista (começa com 0) ou -1 se não encontrado.
 */
int pesquisar_elemento(ListaCircular *lista, char *nome)
{
    if (lista->final == NULL) {
        printf("Lista Circular Vazia.\n");
        return -1;
    }

    Elemento *atual = lista->final->proximo;

    int posicao = 0;

    do {
        if (strcmp(nome, atual->nome) == 0) {
            return posicao;
        }
        
        posicao++;
        atual = atual->proximo;

    } while(atual != lista->final->proximo);

    return -1;
}

/**
 * Destrói a lista circular e libera toda a memória alocada.
 * 
 * @param lista Ponteiro para a lista circular a ser destruída.
 */
void destruir_lista(ListaCircular *lista)
{
    if (lista->final == NULL) {
        // Lista Vazia
        free(lista);
        return;
    }

    Elemento *atual = lista->final->proximo;

    do {
        Elemento *proximo = atual->proximo;
        
        free(atual->nome);
        free(atual);

        atual = proximo;
    } while (atual != lista->final->proximo);
    
    free(lista);
}

/* Implementação da Lógica do Sorteio */

/**
 * Realiza o sorteio de um número entre 1 e a quantidade de clientes.
 * 
 * @param quantidadeClientes Número total de clientes na lista circular.
 * @return int Número sorteado.
 */
int sortear_numero(int quantidadeClientes)
{
    return (rand() % quantidadeClientes) + 1;
}

/**
 * Remove um cliente da lista circular seguindo a lógica do problema de Josephus.
 * 
 * @param clientes Ponteiro para a lista circular de clientes.
 * @param clienteAtual Ponteiro para o ponteiro do cliente atual a partir do qual a contagem começa.
 *                     Após a remoção, `clienteAtual` é atualizado para apontar para o próximo cliente.
 * @param numeroSorteado Número sorteado que determina a posição do cliente a ser removido.
 *
 */
void remover_cliente_josephus(ListaCircular *clientes, Elemento **clienteAtual, int numeroSorteado)
{
    while (numeroSorteado != 1) {
        *clienteAtual = (*clienteAtual)->proximo;
        numeroSorteado--;
    }

    Elemento *proximoCliente = (*clienteAtual)->proximo;

    printf("Removendo %s da lista...\n", (*clienteAtual)->nome);
    remover_elemento_lista(clientes, (*clienteAtual)->nome);
    exibir_lista(clientes);
    
    *clienteAtual = proximoCliente;
}

/**
 * Executa o sorteio e a lógica do problema de Josephus até restar apenas um cliente na lista.
 * 
 * @param clientes Ponteiro para a lista circular de clientes.
 */
void executar_sorteio(ListaCircular *clientes)
{
    if (clientes->final == NULL) {
        printf("A Lista Circular esta vazia! Adicione mais clientes para o sorteio.\n");
        return;
    } else if (clientes->final->proximo == clientes->final) {
        printf("A Lista Circular so tem um cliente! Adicione mais clientes para o sorteio.\n");
        return;
    }

    int quantidadeClientes = 0;
    Elemento *atual = clientes->final->proximo;

    // Contar a quantidade de clientes na lista
    do {
        quantidadeClientes++;
        atual = atual->proximo;
    } while (atual != clientes->final->proximo);

    Elemento *clienteAtual = clientes->final->proximo;

    while (quantidadeClientes > 1) {
        int numeroSorteado = sortear_numero(quantidadeClientes);

        printf("\nNumero sorteado: %d\n", numeroSorteado);

        // Print do cliente atual antes da remoção
        printf("Cliente atual antes do sorteio: %s\n", clienteAtual->nome);

        remover_cliente_josephus(clientes, &clienteAtual, numeroSorteado);

        // Print do cliente atual após a remoção
        printf("Cliente atual apos o sorteio: %s\n", clienteAtual->nome);

        // Atualiza a quantidade de clientes
        quantidadeClientes--;
    }

    printf("\nParabens!! %s venceu o sorteio.\n", clientes->final->nome);
}

int main()
{
    ListaCircular *clientes = inicializar_lista();
    int opcao;
    char nome[100];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar cliente\n");
        printf("2. Exibir lista de clientes\n");
        printf("3. Executar sorteio\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do cliente a ser adicionado: ");
                scanf("%s", nome);
                if (adicionar_elemento_no_final(clientes, nome) == 0) {
                    printf("Cliente '%s' adicionado com sucesso.\n", nome);
                }
                break;

            case 2:
                printf("Lista de clientes:\n");
                exibir_lista(clientes);
                break;

            case 3:
                executar_sorteio(clientes);
                break;

            case 4:
                destruir_lista(clientes);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}