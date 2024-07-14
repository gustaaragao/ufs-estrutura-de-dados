/*
# Enunciado
O Cebolinha é um menino muito esperto, mas tem dificuldades de dicção. 
O seu problema é que toda vez que uma palavra tem um erre (R), ou dois erres (RR), ele o troca por um ele.

Queremos escrever um programa para saber como o Cebolinha falaria uma palavra.

# Entrada
A entrada é uma única palavra que pode ou não conter erres e está escrita em caixa alta.

>> CHURRASQUEIRO

# Saida
A palavra como Cebolinha falaria.

>> CHULASQUEILO

*/

#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA 20

void falar_como_o_cebolinha(char palavra[MAX_PALAVRA], char palavraCebolinha[MAX_PALAVRA], int tamanhoPalavra)
{
  int ultimoCaracterEhErre = 0;

  int tamanhoPalavraCebolinha = 0;

  for (int i = 0; i < tamanhoPalavra; i++) {
    if (palavra[i] == 'R') {
      if (!ultimoCaracterEhErre) {
        palavraCebolinha[tamanhoPalavraCebolinha] = 'L';
        
        tamanhoPalavraCebolinha++;
        
        ultimoCaracterEhErre = 1;
      }
    } else {
      palavraCebolinha[tamanhoPalavraCebolinha] = palavra[i];

      tamanhoPalavraCebolinha++;

      ultimoCaracterEhErre = 0;
    }
  }

  palavraCebolinha[tamanhoPalavraCebolinha] = '\0';
}

int tamanho_string(char string[])
{
  int comprimento = 0;

  while (string[comprimento] != '\0') {
    comprimento += 1;
  }
  
  return comprimento;
}

int main()
{
  char palavra[MAX_PALAVRA];
  char palavraCebolinha[MAX_PALAVRA];

  printf("Digite uma palavra de %d caracteres em caixa alta: ", MAX_PALAVRA);
  scanf("%s", palavra);

  // Verificar se a palavra está em caixa alta
  for (int i = 0; palavra[i] != '\0'; i++) {
    int valorASCII = palavra[i];
    if (valorASCII >= 97 && valorASCII <= 122) {
      printf("Voce digitou um caracter (ou uma palavra) em caixa baixa!");
      return 1;
    }
  }
  
  falar_como_o_cebolinha(palavra, palavraCebolinha, tamanho_string(palavra));

  printf("\nO Cebolinha falaria: %s", palavraCebolinha);

  return 0;
}
