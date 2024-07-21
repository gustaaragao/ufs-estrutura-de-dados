/*
Crie algumas função para tratar strings:

-> void copia(char str1[], char str2[]) que copia o conteúdo de str1 para str2.

-> void reverte(char str[]) que reverte o conteúdo de str.

-> int compara(char str1[], char str2[]) que
    • devolve 0 se as strings são iguais
    • devolve um número menor do que zero se str1 é lexicograficamente menor do que str2
    • devolve um número maior do que zero caso contrário 
*/

#include <stdio.h>
#include <string.h>

#define MAX 30

int compara(char str1[], char str2[])
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            // As strings são diferentes
            return str1[i] - str2[i];
            
        } else {
            // As strings são iguais -> retorne 0.
            return 0;
        }
    }
}

void reverte(char str[])
{
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (fim > inicio) {
        char temp = str[fim];
        str[fim] = str[inicio];
        str[inicio] = temp;

        inicio++;
        fim--;
    }
}

void copia(char str1[], char str2[])
{
    for (int i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
}

int main()
{
    char nome[MAX] = "gustavo", nomeCopia[MAX];

    copia(nome, nomeCopia);
    printf("Nome Copiado: %s", nomeCopia);

    reverte(nome);
    printf("\nNome Invertido: %s", nome);

    printf("\nComparando %s com %s: %d", nome, nomeCopia, compara(nome, nomeCopia));

    printf("\nComparando %s com %s: %d", nomeCopia, nomeCopia, compara(nomeCopia, nomeCopia));

    return 0;
}