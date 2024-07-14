/*
# Enunciado
O caça-palavras é um passa-tempo popular cujo objetivo é encontrar certas palavras em um diagrama.

Nesta tarefa, iremos implementar um programa que resolve um caça-palavras. As palavras estão escondidas 
em uma matriz de letras e podem estar na vertical, horizontal, ou diagonal. 

E além disso, as palavras podem aparecer tanto em ordem direta quanto na ordem invertida!

# Entrada
A entrada consiste de

- uma linha com dois inteiros m e n que correspondem ao número de linhas e de colunas da matriz
- as m linhas seguintes contém n letras cada uma, separadas por espaço
- a próxima linha contém um número p de palavras
- as p linhas seguintes contêm uma palavra em cada linha

>> 3 8
>> v e d j n a e o
>> i p y t h o n u
>> s u e w e t a e
>> 1
>> python

# Saida
A saída é parecida com a matriz de entrada, mas contém o caractere '.' nas posições em que não foi encontrada uma palavra.

. . . . . . . .
. p y t h o n .
. . . . . . . .

*/

#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA  15

#define MAX_ALTURA  15
#define MAX_LARGURA 10

void inverter_palavra(char palavra[MAX_PALAVRA], char inverso[MAX_PALAVRA])
{
	int i = strlen(palavra) - 1; // Indice do ultimo caracter da palavra
	int j = 0;

	while (i >= 0) {
		inverso[j] = palavra[i];
		i--;
		j++;
	}

	// Finalizando a string inverso
	inverso[j] = '\0';
}

void marcar_ocorrencias_diagonal(
	char palavra[MAX_PALAVRA],
	char matrizEntrada[MAX_ALTURA][MAX_LARGURA],
	char matrizSaida[MAX_ALTURA][MAX_LARGURA], 
	int numeroLinhas, int numeroColunas, 
	int i, int j
)
{
	int tamanhoPalavra = strlen(palavra);

	if (((i + tamanhoPalavra) <= numeroLinhas) && ((j + tamanhoPalavra) <= numeroColunas)) {
		// Obter a palavra da Matriz de Entrada
		char palavraMatriz[tamanhoPalavra];
		
		for (int k = 0; k < tamanhoPalavra; k++) {
			palavraMatriz[k] = matrizEntrada[i + k][j + k];
		}

		palavraMatriz[tamanhoPalavra] = '\0';

		// Verificar se há uma ocorrencia na diagonal da palavra
		if (strcmp(palavra, palavraMatriz) == 0) {
			for (int l = 0; l < tamanhoPalavra; l++) {
				// Caso haja, escreve essa palavra na matriz de saida
				matrizSaida[i + l][j + l] = palavraMatriz[l];
			}
		}
	}
}

void marcar_ocorrencias_vertical(
	char palavra[MAX_PALAVRA],
	char matrizEntrada[MAX_ALTURA][MAX_LARGURA],
	char matrizSaida[MAX_ALTURA][MAX_LARGURA], 
	int numeroLinhas, int numeroColunas, 
	int i, int j
)
{
	int tamanhoPalavra = strlen(palavra);

	if ((i + tamanhoPalavra) <= numeroLinhas) {
		// Obter a palavra da Matriz de Entrada
		char palavraMatriz[tamanhoPalavra];

		for (int k = 0; k < tamanhoPalavra; k++) {
			palavraMatriz[k] = matrizEntrada[i + k][j];
		}

		palavraMatriz[tamanhoPalavra] = '\0';

		// Verificar se há uma ocorrencia na vertical da palavra
		if (strcmp(palavra, palavraMatriz) == 0) {
			for (int l = 0; l < tamanhoPalavra; l++) {
				// Caso haja, escreve essa palavra na matriz de saida
				matrizSaida[i + l][j] = palavraMatriz[l];
			}
		}
	}
}

void marcar_ocorrencias_horizontal(
	char palavra[MAX_PALAVRA],
	char matrizEntrada[MAX_ALTURA][MAX_LARGURA],
	char matrizSaida[MAX_ALTURA][MAX_LARGURA], 
	int numeroLinhas, int numeroColunas, 
	int i, int j
)
{
	int tamanhoPalavra = strlen(palavra);

	if ((j + tamanhoPalavra) <= numeroColunas) {
		// Obter a palavra da Matriz de Entrada
		char palavraMatriz[tamanhoPalavra];

		for (int k = 0; k < tamanhoPalavra; k++) {
			palavraMatriz[k] = matrizEntrada[i][j + k];
		}

		palavraMatriz[tamanhoPalavra] = '\0';

		// Verificar se há uma ocorrencia na horizontal da palavra
		if (strcmp(palavra, palavraMatriz) == 0) {
			for (int l = 0; l < tamanhoPalavra; l++) {
				// Caso haja, escreve essa palavra na matriz de saida
				matrizSaida[i][j + l] = palavraMatriz[l];
			}
		}
	}
}

void marcar_ocorrencias(
	char palavra[MAX_PALAVRA],
	char matrizEntrada[MAX_ALTURA][MAX_LARGURA],
	char matrizSaida[MAX_ALTURA][MAX_LARGURA], 
	int numeroLinhas, int numeroColunas
)
{
  for (int i = 0; i < numeroLinhas; i++) {
    for (int j = 0; j < numeroColunas; j++) {
		marcar_ocorrencias_horizontal(palavra, matrizEntrada, matrizSaida, numeroLinhas, numeroColunas, i, j);
		marcar_ocorrencias_vertical(palavra, matrizEntrada, matrizSaida, numeroLinhas, numeroColunas, i, j);
		marcar_ocorrencias_diagonal(palavra, matrizEntrada, matrizSaida, numeroLinhas, numeroColunas, i, j);
    }
  }
}

void imprimir_matriz(char matriz[MAX_ALTURA][MAX_LARGURA], int numeroLinhas, int numeroColunas)
{
	printf("\n");

	for (int i = 0; i < numeroLinhas; i++) {
		for (int j = 0; j < numeroColunas; j++) {
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

void criar_matriz_pontos(char matrizSaida[MAX_ALTURA][MAX_LARGURA], int numeroLinhas, int numeroColunas)
{
	for (int i = 0; i < numeroLinhas; i++) {
    	for (int j = 0; j < numeroColunas; j++) {
      		matrizSaida[i][j] = '.';
    	}
  	}
}

void ler_matriz(char matrizEntrada[MAX_ALTURA][MAX_LARGURA], int numeroLinhas, int numeroColunas)
{
  	char caracter;

	for (int i = 0; i < numeroLinhas; i++) {
    	printf("Linha %d: ", i + 1);
    	for (int j = 0; j < numeroColunas; j++) {
			scanf(" %c", &caracter);

			matrizEntrada[i][j] = caracter;
    	}
  	}
}

int main()
{
	int numeroLinhas = 0, numeroColunas = 0;
	char matrizEntrada[MAX_ALTURA][MAX_LARGURA], matrizSaida[MAX_ALTURA][MAX_LARGURA];

	printf("Digite o numero de linhas e colunas: ");
	scanf("%d %d",&numeroLinhas, &numeroColunas);

	// Receber a Matriz de Entrada
	ler_matriz(matrizEntrada, numeroLinhas, numeroColunas);

	criar_matriz_pontos(matrizSaida, numeroLinhas, numeroColunas);

	int  numeroDePalavras = 0;

	char palavra[MAX_PALAVRA], inverso[MAX_PALAVRA];

	printf("\nDigite o numero de palavras: ");
	scanf("%d", &numeroDePalavras);

	for (int i = 0; i < numeroDePalavras; i++) {
		printf("\nDigite uma palavra: ");
		scanf("%s", palavra);
		
		// Verificar ocorrencias da palavra
		marcar_ocorrencias(palavra, matrizEntrada, matrizSaida, numeroLinhas, numeroColunas);
	
		inverter_palavra(palavra, inverso);

		// Verificar ocorrencias do inverso da palavra
		marcar_ocorrencias(inverso, matrizEntrada, matrizSaida, numeroLinhas, numeroColunas);
	}


	printf("\n=====================");
	imprimir_matriz(matrizSaida, numeroLinhas, numeroColunas);
  
	return 0;
}