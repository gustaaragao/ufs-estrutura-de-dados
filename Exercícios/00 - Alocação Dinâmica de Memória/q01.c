/*
Aluno: Gustavo Henrique Aragao Silva
Turma: 02

1)Guarde N números em um vetor alocado dinamicamente.
Exiba a média dos números lidos e os múltiplos de 6 digitados.
*/

#include <stdio.h>
#include <stdlib.h>

/*
TODO:
- Criar uma função calcularMedia()

- Criar uma função filtrarMultiplos() -> Vetor
*/

void filtrarMultiplos(const int *vetor, int tamanhoVetor, int valor)
{
    printf("\nValores multiplos de %d: ", valor);
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor[i] % valor == 0)
        {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

float calcularMedia(const int *vetor, int tamanhoVetor)
{
    int soma = 0;

    for (int i = 0; i < tamanhoVetor; i++)
    {
        soma += vetor[i];
    }

    return (float)soma / tamanhoVetor;
}

void receberValores(int *vetor, int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &vetor[i]);
    }
}

int main()
{
    int tamanhoVetor = 0;
    int *vetor = NULL;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    vetor = (int *)calloc(tamanhoVetor, sizeof(int));

    if (vetor == NULL)
    {
        printf("\nFalha na Alocacao!");
        return 1;
    }

    receberValores(vetor, tamanhoVetor);

    // Calcular a média
    float media = calcularMedia(vetor, tamanhoVetor);
    printf("\nMedia = %.2f", media);

    // Mostrar os valores digitados múltiplos de 6
    filtrarMultiplos(vetor, tamanhoVetor, 6);

    free(vetor);

    return 0;
}