/*
# Enunciado
Na corrida de lesmas, cada lesma é classificada em um nível dependendo de sua velocidade. 
O problema é que as lesmas mais rápidas também se cansam mais rapidamente. Assim

- se sua velocidade é menor ou igual a 10 cm/h, então ela consegue andar por 3 h até parar;
- se sua velocidade é maior que 10 cm/h e menor ou igual a 20 cm/h, então ela consegue andar por 2 h até parar;
- se sua velocidade é maior que 20 cm/h e menor ou igual a 100cm/h, então ela consegue andar por 1 h até parar.

Suponha que não existem lesmas que rastejam mais rapidamente que 100 cm/h.

Sua tarefa é identificar qual é a velocidade da lesma mais rápida que pode competir em uma maratona de uma certa duração.

# Entrada
A entrada é composta de
- um número inteiro n na primeira linha
- seguida de n linhas, cada uma representando a velocidade de uma lesma como um número inteiro
- um número inteiro, representando a duração em horas da competição

# Saida
A saída é uma única linha representando a velocidade da lesma mais rápida que pode competir.
*/

#include <stdio.h>

#define MAX_LESMAS 100
#define MAX_VELOCIDADE 100

int main()
{
  int numeroDeLesmas;
  int velocidades[MAX_LESMAS];
  int duracaoProva;
  int velocidadeLimite;

  printf("Digite o numero de Lesmas: ");
  scanf("%d", &numeroDeLesmas);

  if (numeroDeLesmas > MAX_LESMAS) {
    printf("\nQuantidade invalida de Lesmas -> Maximo de %d Lesmas por corrida", MAX_LESMAS);
    return 1;
  }

  for (int i = 0; i < numeroDeLesmas; i++) {
    // Coletar a Velocidade de cada Lesma
    printf("\nDigite a velocidade da Lesma %d: ", i + 1);
    scanf("%d", &velocidades[i]);

    // Pelo enunciado, nao existe lesma com mais de 100 cm/h de velocidade. Esse bloco de codigo verifica isso.
    while (velocidades[i] > MAX_VELOCIDADE) {
      printf("\nA Velocidade digitada eh invalida (> %d cm/h). Digite uma Velocidade novamente.", MAX_VELOCIDADE);
      printf("\nDigite a velocidade da Lesma %d: ", i + 1);
      scanf("%d", &velocidades[i]);
    }
  }

  // Coletar a Duracao da Prova
  printf("\nDuracao da Prova: ");
  scanf("%d", &duracaoProva);

  while (duracaoProva < 1) {
    printf("\nA Duracao de Prova digitada eh invalida. Digite uma duracao de Prova novamente");
    printf("\nDuracao da Prova: ");
    scanf("%d", &duracaoProva);
  }

  // Definir a Velocidade Limite para o Evento
  if (duracaoProva == 1) {
    velocidadeLimite = 100;
  } else if (duracaoProva == 2) {
    velocidadeLimite = 20;
  } else if (duracaoProva == 3) {
    velocidadeLimite = 10;
  } else if (duracaoProva > 3) {
    printf("\nNenhuma lesma conseguiu terminar a prova!");
    return 1;
  }

  int maiorVelocidade = 0;

  // Definir a maior velocidade das Lesmas Qualificadas ---> Para qualificar: VELOCIDADE_LESMA <= VELOCIDADE_LIMITE
  for (int i = 0; i < numeroDeLesmas; i++) {
    // Verificar se a Lesma eh qualificada (consegue terminar a prova) e se sua velocidade eh maior que a maiorVelocidade
    if (velocidades[i] <= velocidadeLimite && velocidades[i] > maiorVelocidade) {
      maiorVelocidade = velocidades[i];
    }
  }

  printf("\nMaior velocidade: %d", maiorVelocidade);

  return 0;
}
