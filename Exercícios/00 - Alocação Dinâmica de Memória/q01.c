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

int main()
{
    int tamanhoVetor, *vetor = NULL, soma = 0;
    // Passo 1: Receber o tamanho do Vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    // Passo 2: Alocar Dinamicamente o vetor
    vetor = (int*) calloc(tamanhoVetor, sizeof(int));
    if (vetor == NULL) 
    {
        printf("\nERRO - MEMORIA NAO ALOCADA DINAMICAMENTE");
        return;
    }

    // Passo 3: Guardar os valores digitados pelo usuário no Vetor
    for (int i=0; i<tamanhoVetor; i++)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // Passo 4: Calcular a média
    float media; 
    media = (float) soma / tamanhoVetor;
    printf("\nMedia = %f", media);
    
    // Passo 5: Mostrar os valores digitados múltiplos de 6
    printf("\nValores multiplos de 6:");
    for (int i=0; i<tamanhoVetor; i++)
    {
        if (vetor[i] % 6 == 0) printf(" %d", vetor[i]);
    }

    free(vetor);

    return 0;
}