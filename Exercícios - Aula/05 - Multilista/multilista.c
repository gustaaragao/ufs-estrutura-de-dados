#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas
typedef struct Aluno
{
    int matricula;
    char* nome;
    struct Aluno *proximo;
} Aluno;

typedef struct ListaAlunos
{
    Aluno *inicio;
    Aluno *final;
    int quantidade;
} ListaAlunos;

typedef struct Disciplina
{
    int codigo;
    char* nome;
    ListaAlunos *matriculados;
    struct Disciplina *proximo;
} Disciplina;

typedef struct ListaDisciplinas
{
    Disciplina *inicio;
    Disciplina *fim;
    int quantidade;
} ListaDisciplinas;

// Função para inicializar a lista de disciplinas
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

// Função para criar uma nova disciplina
int criar_disciplina(char *nome, int codigo, ListaDisciplinas *listaDisciplinas)
{
    // Verifica se já existe uma disciplina com esse código
    Disciplina *atual = listaDisciplinas->inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("ERRO: JA EXISTE UMA DISCIPLINA COM ESSE CODIGO.\n");
            return 1;
        }
        atual = atual->proximo;
    }

    // Aloca memória para a nova disciplina
    Disciplina *novaDisciplina = malloc(sizeof(Disciplina));
    if (novaDisciplina == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA A NOVA DISCIPLINA.\n");
        return 1;
    }

    // Aloca e inicializa a lista de alunos
    ListaAlunos *novaListaAlunos = malloc(sizeof(ListaAlunos));
    if (novaListaAlunos == NULL) {
        printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA A NOVA LISTA DE ALUNOS.\n");
        free(novaDisciplina);
        return 1;
    }
    novaListaAlunos->quantidade = 0;
    novaListaAlunos->inicio = NULL;
    novaListaAlunos->final = NULL;

    // Inicializa os campos da novaDisciplina
    novaDisciplina->codigo = codigo;
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

    // Adiciona a nova disciplina à lista
    if (listaDisciplinas->inicio == NULL) {
        listaDisciplinas->inicio = novaDisciplina;
        listaDisciplinas->fim = novaDisciplina;
    } else {
        listaDisciplinas->fim->proximo = novaDisciplina;
        listaDisciplinas->fim = novaDisciplina;
    }

    listaDisciplinas->quantidade++;
    return 0;
}

// Função para matricular um aluno em uma disciplina
int matricular_aluno_na_disciplina(int codigoDisciplina, char *nomeAluno, int matricula, ListaDisciplinas *listaDisciplinas)
{
    Disciplina *disciplinaAlvo = listaDisciplinas->inicio;

    while (disciplinaAlvo != NULL) {
        if (disciplinaAlvo->codigo == codigoDisciplina) {
            // Aloca memória para o novo aluno
            Aluno *novoAluno = malloc(sizeof(Aluno));
            if (novoAluno == NULL) {
                printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOVO ALUNO.\n");
                return 1;
            }

            // Inicializa os campos do novoAluno
            novoAluno->nome = malloc(strlen(nomeAluno) + 1);
            if (novoAluno->nome == NULL) {
                printf("[ERRO - ALOCACAO DE MEMORIA]: NAO FOI POSSIVEL ALOCAR MEMORIA PARA O NOME DO NOVO ALUNO.\n");
                free(novoAluno);
                return 1;
            }
            strcpy(novoAluno->nome, nomeAluno);
            novoAluno->matricula = matricula;
            novoAluno->proximo = NULL;

            // Adiciona o novo aluno à lista de alunos da disciplina
            if (disciplinaAlvo->matriculados->inicio == NULL) {
                disciplinaAlvo->matriculados->inicio = novoAluno;
                disciplinaAlvo->matriculados->final = novoAluno;
            } else {
                disciplinaAlvo->matriculados->final->proximo = novoAluno;
                disciplinaAlvo->matriculados->final = novoAluno;
            }

            disciplinaAlvo->matriculados->quantidade++;
            return 0;
        }
        disciplinaAlvo = disciplinaAlvo->proximo;
    }

    printf("ERRO: O CODIGO DA DISCIPLINA NAO CONSTA NO BANCO DE DADOS.\n");
    return 1;
}

int excluir_aluno_da_disciplina(int codigoDisciplina, int matricula, ListaDisciplinas *listaDisciplinas)
{
    Disciplina *disciplinaAlvo = listaDisciplinas->inicio;

    while (disciplinaAlvo != NULL) {
        if (disciplinaAlvo->codigo == codigoDisciplina) {
            
            Aluno *alunoAtual = disciplinaAlvo->matriculados->inicio;
            Aluno *alunoAnterior = NULL;

            while (alunoAtual != NULL) {
                if (alunoAtual->matricula == matricula) {
                    // Encontramos o aluno a ser excluido
                    if (alunoAnterior == NULL) {
                        // Esse aluno é o primeiro da lista
                        disciplinaAlvo->matriculados->inicio = alunoAtual->proximo;
                        if (disciplinaAlvo->matriculados->inicio == NULL) {
                            // A lista agora está vazia
                            disciplinaAlvo->matriculados->final = NULL;
                        }
                    } else {
                        // O aluno está no meio da lista ou no final
                        alunoAnterior->proximo = alunoAtual->proximo;

                        if (alunoAtual->proximo == NULL) {
                            // O aluno está no final da lista
                            disciplinaAlvo->matriculados->final = alunoAnterior;
                        }
                    }


                    free(alunoAtual->nome);
                    free(alunoAtual);            

                    disciplinaAlvo->matriculados->quantidade--;

                    printf("Aluno %d deletado com sucesso!\n", matricula);

                    return 0;
                }

                alunoAtual = alunoAtual->proximo;
            }

            printf("ERRO: O ALUNO NAO ESTA MATRICULADO NA DISCIPLINA");

            return 1;
        }

        disciplinaAlvo = disciplinaAlvo->proximo;
    }

    printf("ERRO: O CODIGO DA DISCIPLINA NAO CONSTA NO BANCO DE DADOS.\n");
    return 1;
}

// Função para exibir a lista de disciplinas
void exibir_lista_disciplinas(ListaDisciplinas *listaDisciplinas)
{
    Disciplina *atual = listaDisciplinas->inicio;

    if (atual == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    while (atual != NULL) {
        printf("Codigo: %d \t Nome: %s \t Matriculados: %d\n", atual->codigo, atual->nome, atual->matriculados->quantidade);
        atual = atual->proximo;
    }
}

// Função para exibir os alunos matriculados
void exibir_matriculados(ListaAlunos *listaAlunos)
{
    Aluno *atual = listaAlunos->inicio;

    if (atual == NULL) {
        printf("Nao ha alunos matriculados.\n");
        return;
    }

    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para exibir a lista de disciplinas com os alunos matriculados
void exibir_lista_disciplinas_com_alunos(ListaDisciplinas *listaDisciplinas)
{
    Disciplina *atual = listaDisciplinas->inicio;

    if (atual == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    while (atual != NULL) {
        printf("Codigo: %d \t Nome: %s \t Alunos: ", atual->codigo, atual->nome);
        exibir_matriculados(atual->matriculados);
        atual = atual->proximo;
    }
}

int main()
{
    ListaDisciplinas *listaDisciplinas = inicializar_lista_disciplinas();
    int opcao;
    int codigoDisciplina;
    char nomeAluno[50];
    char nomeDisciplina[50];
    int matricula;

    do {
        printf("\nMenu:\n");
        printf("1. Criar disciplina\n");
        printf("2. Matricular aluno em disciplina\n");
        printf("3. Excluir aluno de disciplina\n");
        printf("4. Exibir lista de disciplinas\n");
        printf("5. Exibir lista de disciplinas com alunos matriculados\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome da disciplina: ");
                scanf("%s", nomeDisciplina);
                printf("Digite o codigo da disciplina: ");
                scanf("%d", &codigoDisciplina);
                criar_disciplina(nomeDisciplina, codigoDisciplina, listaDisciplinas);
                break;
            case 2:
                printf("Digite o codigo da disciplina: ");
                scanf("%d", &codigoDisciplina);
                printf("Digite o nome do aluno: ");
                scanf("%s", nomeAluno);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                matricular_aluno_na_disciplina(codigoDisciplina, nomeAluno, matricula, listaDisciplinas);
                break;
            case 3:
                printf("Digite o codigo da disciplina: ");
                scanf("%d", &codigoDisciplina);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                excluir_aluno_da_disciplina(codigoDisciplina, matricula, listaDisciplinas);
                break;
            case 4:
                exibir_lista_disciplinas(listaDisciplinas);
                break;
            case 5:
                exibir_lista_disciplinas_com_alunos(listaDisciplinas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}