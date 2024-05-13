/*
Aluno: Gustavo Henrique Aragao Silva
Turma: 02

3) Construa um programa que armazene nome, matrícula e média de até N alunos e dê ao usuário a possibilidade de ver a listagem dos
alunos em ordem alfabética ou em ordem de classificação.
Obs: uma vez que os dados sejam digitados, o usuário deve poder ver as listagens quantas vezes ele desejar..
*/

/* MINI DOCUMENTACAO
Essa implementacao foi feita sem utilizar o qsort... Decidi por fim implementar dois algoritmos distintos de ordenação para efetuar
a listagem proposta.

Por fim, de resto o programa é literalmente o mesmo do apresentado no arquivo "q03(qsort).c"
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

void ordenarOrdemClassificacao(Aluno *vetorAluno, int tamanhoVetor)
{
}


void ordenarOrdemAlfabetica(Aluno *vetorAluno, int tamanhoVetor)
{
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
            // TODO
            mostrarAlunos(vetorAluno, tamanhoVetor);
            break;

        // Listagem Ordem Classificatoria
        case 2:
            printf("\nListagem Alunos em Ordem Classificatoria:");
            // TODO
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