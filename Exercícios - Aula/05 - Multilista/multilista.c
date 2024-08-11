#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    uint16_t matricula;
    char* nome;
    struct Aluno *proximo;
} Aluno;

typedef struct ListaAlunos
{
    Aluno *inicio;
    Aluno *final;
    uint32_t quantidade;
} ListaAlunos;

typedef struct Disciplina
{
    uint8_t codigo;
    char* nome;
    ListaAlunos *matriculados;
    struct Disciplina *proximo;
} Disciplina;

typedef struct ListaDisciplinas
{
    Disciplina *inicio;
    Disciplina *fim;
    uint32_t quantidade;
} ListaDisciplinas;

ListaDisciplinas* inicializar_lista_disciplinas()
{
    ListaDisciplinas *listaDisciplinas = malloc(sizeof(ListaDisciplinas));

    if (listaDisciplinas == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA LISTA.\n");
        return NULL;
    }

    listaDisciplinas->quantidade = 0;
    listaDisciplinas->inicio = NULL;
    listaDisciplinas->fim = NULL;

    return listaDisciplinas;
}

int criar_disciplina(char nome[50], uint8_t codigo, ListaDisciplinas *listaDisciplinas)
{
    // TODO: FAZER VERIFICAO SE HÁ UMA DISCIPLINA COM ESSE CODIGO

    Disciplina *novaDisciplina = malloc(sizeof(Disciplina));

    if (novaDisciplina == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA A NOVA DISCIPLINA.\n");
        return 1;
    }

    ListaAlunos *novaListaAlunos = malloc(sizeof(ListaAlunos));

    if (novaListaAlunos == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA A NOVA LISTA DE ALUNOS PARA A NOVA DISCIPLINA.\n");
        free(novaDisciplina);
        return 1;
    }

    // Inicializando os campos da novaListaAlunos
    novaListaAlunos->quantidade = 0;
    novaListaAlunos->inicio = NULL;
    novaListaAlunos->final = NULL;

    // Inicializando os campos da novaDisciplina
    novaDisciplina->codigo = codigo; 

    // Alocando e copiando o nome
    novaDisciplina->nome = malloc(strlen(nome) + 1);
    if (novaDisciplina->nome == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOME DA DISCIPLINA.\n");
        free(novaListaAlunos);
        free(novaDisciplina);
        return 1;
    }

    strcpy(novaDisciplina->nome, nome);

    novaDisciplina->matriculados = novaListaAlunos;
    novaDisciplina->proximo = NULL;

    if (listaDisciplinas->inicio == NULL) {
        // A lista de disciplinas está vazia
        listaDisciplinas->inicio = novaDisciplina;
        listaDisciplinas->fim = novaDisciplina;
    } else {
        listaDisciplinas->fim->proximo = novaDisciplina;
        listaDisciplinas->fim = novaDisciplina;
    }
    
    listaDisciplinas->quantidade++;
    return 0;
}

int matricular_aluno_na_disciplina(uint8_t codigoDisciplina, ListaDisciplinas *listaDisciplinas, char nomeAluno[50], uint16_t matricula)
{

    

}

void excluir_aluno_da_disciplina(uint8_t codigoDisciplina, ListaDisciplinas *listaDisciplinas, uint16_t matricula)
{

}

void exibir_lista_disciplinas(ListaDisciplinas *listaDisciplinas)
{
    Disciplina *atual = listaDisciplinas->inicio;

    if (atual == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    do
    {
        printf("Codigo: %d \t Nome: %s \t Matriculados: %d\n", atual->codigo, atual->nome, atual->matriculados->quantidade);
        atual = atual->proximo;
    } while (atual != NULL);
}

void exibir_matriculados(ListaAlunos *ListaAlunos)
{
    Aluno *atual = ListaAlunos->inicio;

    if (atual == NULL) {
        printf("Nao ha alunos matriculados.\n");
        return;
    }
    
    do
    {
        if (atual->proximo == NULL) {
            // Ultimo aluno da lista
            printf("%s\n", atual->nome);
        } else {
            printf("%s, ", atual->nome);
        }

        atual = atual->proximo;
    } while (atual != NULL);
}

void exibir_lista_disciplinas_com_alunos(ListaDisciplinas *listaDisciplinas)
{
    Disciplina *atual = listaDisciplinas->inicio;

    if (atual == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    do
    {
        printf("Codigo: %d \t Nome: %s \t Alunos: ", atual->codigo, atual->nome);
        exibir_matriculados(atual->matriculados);

        atual = atual->proximo;
    } while (atual != NULL);
}

int main()
{
    ListaDisciplinas *listaDisciplinas = inicializar_lista_disciplinas();
    
    criar_disciplina("Estrutura de Dados", 100, listaDisciplinas);
    criar_disciplina("Programacao Orientada a Objetos", 101, listaDisciplinas);
    criar_disciplina("Linguagens Formais e Computabilidade", 102, listaDisciplinas);

    exibir_lista_disciplinas(listaDisciplinas);

    printf("\n");

    exibir_lista_disciplinas_com_alunos(listaDisciplinas);
    
    return 0;
}
