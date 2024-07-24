/*
-> Declare uma struct que armazena informações de notas de uma turma.
Essa estrutura deve armazenar o número de alunos, as notas das provas e a maior nota.

-> Depois faça um programa que leia todos os dados e imprima a maior nota.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int quantidadeAlunos;
    double *notas;
    double maiorNota;
} NotasTurma;

int main()
{
    NotasTurma turma;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &turma.quantidadeAlunos);

    // Alocando dinamicamente um vetor com as notas dos alunos.
    turma.notas = malloc(turma.quantidadeAlunos * sizeof(double));
    for (int i = 0; i < turma.quantidadeAlunos; i++) {
        printf("Digite a nota do aluno [%d]: ", i + 1);
        scanf("%lf", &turma.notas[i]);
    }

    turma.maiorNota = turma.notas[0];
    for (int i = 1; i < turma.quantidadeAlunos; i++) {
        if (turma.notas[i] > turma.maiorNota) {
            turma.maiorNota = turma.notas[i];
        }
    }

    printf("\nMaior Nota: %.2lf", turma.maiorNota);

    // Liberando espaço de memória.
    free(turma.notas);
}