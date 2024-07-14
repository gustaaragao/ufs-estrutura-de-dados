/*
# Enunciado
Em uma disciplina, há avaliações de tarefas práticas e tarefas teóricas. 
Cada estudante recebe uma média aritmética P de 3 tarefas práticas e uma média aritmética T de 2 tarefas teóricas. 
A média final é dada por F = (T + P)/2.

Devido ao baixo desempenho da turma nas tarefas teóricas, o professor decidiu aplicar a seguinte regra de normalização: 
uma nova nota T’ será dada pela nota T original vezes 10 e dividida pela maior nota T entre todos estudantes da turma. 
Assim, se João tirou 3 e a maior nota foi 6, então a nova nota de João será 10*3/6, ou 5.

Devido às inúmeras reclamações da turma, o professor resolveu ainda dar 10% de bônus na nota P de cada estudante. 
Assim, a nova nota P’ será 1,1*P.

Seu objetivo é calcular a nota final de cada estudante e a médias das novas notas T’ e P'.

# Entrada
A entrada tem:
- um número n de estudante
- uma sequência de n linhas, cada uma com as três notas das tarefas práticas, em ordem de RA
- uma sequência de n linhas, cada uma com as duas notas das tarefas teóricas, em ordem de RA

# Saida
A saída deve conter
- n linhas, cada uma com a nota final de cada estudante
- em seguida, duas linhas com as notas máximas de T e P entre todos estudantes
- por último, duas linhas com as médias de T e P
*/

#include <stdio.h>

#define MAX_ALUNOS 100

float calcular_media_vetor(float vetor[], int tamanhoVetor)
{
  float soma = 0;
  for (int i = 0; i < tamanhoVetor; i++) {
    soma += vetor[i];
  }

  return soma / tamanhoVetor;
}

void calcular_media_final(float notasFinais[MAX_ALUNOS], float notasPraticas[MAX_ALUNOS], float notasTeoricas[MAX_ALUNOS], int numeroAlunos) 
{
  for (int i = 0; i < numeroAlunos; i++) {
    notasFinais[i] = (notasPraticas[i] + notasTeoricas[i]) / 2;
  }
}

/*
É opcional indicar o tamanho máximo do vetor nas declarações de parâmetro de função.
Isso é útil porque podemos passar vetores de diferentes capacidades para a mesma função, desde que os vetores tenha o mesmo tipo.
*/ 
void multiplicar_vetor_por_fator(float vetor[], int tamanhoVetor, float fator)
{
  for (int i = 0; i < tamanhoVetor; i++) {
    vetor[i] = vetor[i] * fator;
  }
}

float obter_maior_nota(float notas[MAX_ALUNOS], int numeroAlunos)
{
  float maiorNota = 0.0;

  for (int i = 0; i < numeroAlunos; i++) {
    if (notas[i] > maiorNota) {
      maiorNota = notas[i];
    }
  }

  return maiorNota;
}

float ler_media(int quantidadeDeNotas) 
{
  float somaNotas = 0;
  float nota;

  for (int i = 0; i < quantidadeDeNotas; i++) {
    scanf("%f", &nota);
    somaNotas += nota;
  }

  return somaNotas / quantidadeDeNotas;
}

void ler_notas_teoricas(float notas[MAX_ALUNOS], int numeroAlunos)
{
  for (int i = 0; i < numeroAlunos; i++) {
    printf("\nNotas Teoricas do Aluno %d: ", i + 1);
    notas[i] = ler_media(2);
  }
}

void ler_notas_praticas(float notas[MAX_ALUNOS], int numeroAlunos)
{
  for (int i = 0; i < numeroAlunos; i++) {
    printf("\nNotas Praticas do Aluno %d: ", i + 1);
    notas[i] = ler_media(3);
  }
}

int main()
{
  int numeroAlunos;
  float notasPraticas[MAX_ALUNOS], notasTeoricas[MAX_ALUNOS], notasFinais[MAX_ALUNOS];
  float maiorNotaPratica, maiorNotaTeorica;
  float mediaNotasPraticas, mediaNotasTeoricas;

  printf("Digite o numero de alunos: ");
  scanf("%d", &numeroAlunos);

  while (numeroAlunos > MAX_ALUNOS) {
    printf("\nNumero de Alunos maior que o permitido (> %d)", MAX_ALUNOS);
    printf("\nDigite o numero de alunos: ");
    scanf("%d", &numeroAlunos);
  }

  printf("\nNotas Praticas:");

  ler_notas_praticas(notasPraticas, numeroAlunos);

  printf("\nNotas Teoricas:");

  ler_notas_teoricas(notasTeoricas, numeroAlunos);

  maiorNotaTeorica = obter_maior_nota(notasTeoricas, numeroAlunos);

  multiplicar_vetor_por_fator(notasTeoricas, numeroAlunos,  10 / maiorNotaTeorica);
  
  multiplicar_vetor_por_fator(notasPraticas, numeroAlunos,  1.1);

  calcular_media_final(notasFinais, notasPraticas, notasTeoricas, numeroAlunos);

  maiorNotaPratica = obter_maior_nota(notasPraticas, numeroAlunos);
  maiorNotaTeorica = obter_maior_nota(notasTeoricas, numeroAlunos);

  mediaNotasPraticas = calcular_media_vetor(notasPraticas, numeroAlunos);
  mediaNotasTeoricas = calcular_media_vetor(notasTeoricas, numeroAlunos);

  for (int i = 0; i < numeroAlunos; i++) {
    printf("\nNota final do Aluno %d: %.1f", i + 1, notasFinais[i]);
  }

  printf("\nMaior Nota Pratica: %.1f", maiorNotaPratica);
  printf("\nMaior Nota Teorica: %.1f", maiorNotaTeorica);

  printf("\nMedia Notas Praticas: %.1f", mediaNotasPraticas);
  printf("\nMedia Notas Teoricas: %.1f", mediaNotasTeoricas);

  return 0;
}
