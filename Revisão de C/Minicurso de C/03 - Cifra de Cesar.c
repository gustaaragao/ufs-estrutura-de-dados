/*
A Cifra de César é uma das formas mais simples de criptografia
• E uma das mais fáceis de quebrar…
• Dado um parâmetro inteiro k
• cada letra é trocada pela k-ésima letra após ela
    – Se k = 1, a é trocada por b, b por c, c por d, etc
    – Se k = 2, a é trocada por c, b por d, c por e, etc
• ao chegar no final do alfabeto, nós voltamos para o início

Observacao: Para desencriptar, basta fazer o mesmo processo para 26 − k.

Vamos fazer um programa que encripta uma sequência de letras usando a cifra de César...
*/

#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA 30

void encriptar_palavra(char palavra[MAX_PALAVRA], char palavraEncriptada[MAX_PALAVRA], int k)
{
    int tamanhoPalavra = strlen(palavra);

    for (int i = 0; i < tamanhoPalavra; i++) {
        if (palavra[i] + k >= 65 && palavra[i] + k <= 90) {
            palavraEncriptada[i] = palavra[i] + k;
        } else if (palavra[i] + k >= 97 && palavra[i] + k <= 122) {
            palavraEncriptada[i] = palavra[i] + k;
        } else {
            palavraEncriptada[i] = palavra[i] + k - 26;
        }
    }

    palavraEncriptada[tamanhoPalavra] = '\0';
}

int main ()
{
    char palavra[MAX_PALAVRA], palavraEncriptada[MAX_PALAVRA];
    int tamanhoPalavra = 0, k = 0;

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    printf("Digite o valor de k: ");
    scanf("%d", &k);
    
    encriptar_palavra(palavra, palavraEncriptada, k);

    printf("\nPalavra encriptada: %s", palavraEncriptada);

    return 0;
}