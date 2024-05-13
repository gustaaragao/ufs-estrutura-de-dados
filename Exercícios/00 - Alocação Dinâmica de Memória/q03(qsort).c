/*
Aluno: Gustavo Henrique Aragao Silva
Turma: 02

3) Construa um programa que armazene nome, matrícula e média de até N alunos e dê ao usuário a possibilidade de ver a listagem dos
alunos em ordem alfabética ou em ordem de classificação.
Obs: uma vez que os dados sejam digitados, o usuário deve poder ver as listagens quantas vezes ele desejar..
*/

/* MINI DOCUMENTACAO
void qsort(void *base, size_t nitems, size_t size, int (*compare)(const void *x, const void*y))
    -> base: é o ponteiro para o vetor;
    -> nitems: número de itens do vetor;
    -> size: é o tamanho em bytes de cada elemento do vetor;
    -> compar: é uma função que será utilizada para fazer a comparação
Obs.: Caso a função retorne um valor:
        (> 0) ->  x deveria ir antes de y;
        (= 0) ->  x é equivalente a y;
        (< 0) ->  x deveria ir depois de y;

Fonte: Utilizei essas referencias para entender melhor o funcionamento do qsort.
https://www.youtube.com/watch?v=rHoOWG6Ihs4
https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

int strcmp(const char *str1, const char *str2)
    return (< 0): str1 < str2
    return (= 0): str1 == str2
    return (> 0): str1 > str2

Fonte:
https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[50];
    char matricula[12];
    float media;
} Aluno;

int compareClassificao(const void *x_void, const void *y_void)
{
    Aluno x = *(Aluno *)x_void;
    Aluno y = *(Aluno *)y_void;

    if (x.media > y.media)
    {
        return -1;
    }
    else if (x.media < y.media)
    {
        return 1;
    }

    return 0;
}

int compareAlfabeto(const void *x_void, const void *y_void)
{
    Aluno x = *(Aluno *)x_void;
    Aluno y = *(Aluno *)y_void;

    return strcmp(x.nome, y.nome);
}

void mostrarAlunos(const Aluno *vetorAluno, int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\nAluno %d:", i + 1);
        printf("\nNome: %s | Matricula: %s | Media: %.2f", vetorAluno[i].nome, vetorAluno[i].matricula, vetorAluno[i].media);
    }

    printf("\n");
}

void receberAlunos(Aluno *vetorAluno, int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\nDigite os dados do Aluno %d:", i + 1);
        printf("\nNome: ");
        scanf("%s", vetorAluno[i].nome);
        printf("\nMatricula: ");
        scanf("%s", vetorAluno[i].matricula);
        printf("\nMedia: ");
        scanf("%f", &vetorAluno[i].media);
    }
}

int main()
{
    int tamanhoVetor = 0;
    Aluno *vetorAluno = NULL;

    printf("Digite o numero de alunos: ");
    scanf("%d", &tamanhoVetor);

    vetorAluno = malloc(tamanhoVetor * sizeof(Aluno));

    if (vetorAluno == NULL)
    {
        printf("Falha na alocacao!");
        return 1;
    }

    receberAlunos(vetorAluno, tamanhoVetor);

    printf("\nListagem Alunos:");
    mostrarAlunos(vetorAluno, tamanhoVetor);

    int opcao = 0;

    while (1)
    {
        printf("\nO que deseja fazer?\n");
        printf("1. Listagem em Ordem Alfabetica\n");
        printf("2. Listagem em Ordem Classificatoria\n");
        printf("3. Encerrar Programa\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 3)
        {
            printf("\nEncerrando o programa...\n");
            break;
        }

        switch (opcao)
        {
        // Listagem Ordem Alfabetica
        case 1:
            printf("\nListagem Alunos em Ordem Alfabetica:");
            qsort(vetorAluno, tamanhoVetor, sizeof(Aluno), compareAlfabeto);
            mostrarAlunos(vetorAluno, tamanhoVetor);
            break;

        // Listagem Ordem Classificatoria
        case 2:
            printf("\nListagem Alunos em Ordem Classificatoria:");
            qsort(vetorAluno, tamanhoVetor, sizeof(Aluno), compareClassificao);
            mostrarAlunos(vetorAluno, tamanhoVetor);
            break;

        default:
            printf("\nOpcao Invalida! Tente novamente...\n");
            break;
        }
    }

    free(vetorAluno);

    return 0;
}