/*
Aluno: Gustavo Henrique Aragao Silva
Turma: 02

2) Crie um struct que guarde nome, idade e peso um atletas.
Em um vetor, alocado dinamicamente, guarde os dados de N atletas.
Exiba uma listagem dos dados dos atletas cadastrados.
Ao final exiba a média dos pesos e quantos atletas são menores de idade.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Atleta
{
    char nome[50];
    int idade;
    float peso;
} Atleta;

int contarMenoresDeIdade(const Atleta *vetorAtleta, int tamanhoVetor)
{
    int quantidadeMenores = 0;

    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetorAtleta[i].idade < 18)
        {
            quantidadeMenores++;
        }
    }

    return quantidadeMenores;
}

float calcularMediaPeso(const Atleta *vetorAtleta, int tamanhoVetor)
{
    float somaPeso = 0.0;

    for (int i = 0; i < tamanhoVetor; i++)
    {
        somaPeso += vetorAtleta[i].peso;
    }

    return somaPeso / tamanhoVetor;
}

void mostrarAtletas(const Atleta *vetorAtleta, int tamanhoVetor)
{
    printf("\n===============================");
    printf("\nAtletas Adicionados:\n");
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\n# Atleta %d:\n", i + 1);
        printf("Nome: %s\n", vetorAtleta[i].nome);
        printf("Idade: %u\n", vetorAtleta[i].idade);
        printf("Peso: %.2f\n", vetorAtleta[i].peso);
    }
}

int main()
{
    int tamanhoVetor = 0;
    Atleta *vetorAtleta = NULL;

    printf("Digite o numero de atletas: ");
    scanf("%d", &tamanhoVetor);

    vetorAtleta = (Atleta*) malloc(tamanhoVetor * sizeof(Atleta));

    if (vetorAtleta == NULL)
    {
        printf("ERRO - MEMORIA NAO ALOCADA DINAMICAMENTE");
        return 1;
    }

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\nDigite os dados do Atleta %d", i + 1);
        printf("\nNome: ");
        scanf("%s", vetorAtleta[i].nome);
        printf("\nIdade: ");
        scanf("%d", &vetorAtleta[i].idade);
        printf("\nPeso: ");
        scanf("%f", &vetorAtleta[i].peso);
    }

    mostrarAtletas(vetorAtleta, tamanhoVetor);

    float mediaPeso = calcularMediaPeso(vetorAtleta, tamanhoVetor);
    printf("\nMedia de Peso dos Atletas: %.2f", mediaPeso);

    int quantidadeMenoresDeIdade = contarMenoresDeIdade(vetorAtleta, tamanhoVetor);
    printf("\nQuantidade de Menores de Idade: %d", quantidadeMenoresDeIdade);

    free(vetorAtleta);

    return 0;
}