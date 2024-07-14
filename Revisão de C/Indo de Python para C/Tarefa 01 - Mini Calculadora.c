/*
# Enunciado
Nesta tarefa, queremos implementar uma minicalculadora que realiza operações aritméticas básicas: 
soma, subtração, multiplicação e divisão.

# Entrada
A entrada é formada por um número n de operações na primeira linha seguida de n linhas representado uma 
operação em cada linha, formatadas como no exemplo:

>> 2
>> 23.8 + 0.5
>> 9 * 3.0 

# Saida
Para cada operação, seu programa deve imprimir uma linha com o resultado da operação. Para a entrada acima, 
o seu programa deve imprimir a seguinte saída:

>> 24.3
>> 27.0
https://www.ic.unicamp.br/~lehilton/cursos/1s2022/mc102w/python_c/
*/


#include <stdio.h>


int main() 
{
  int n;
  float operando1, operando2, resultado;
  char operador;

  printf("Digite o numero de operacoes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("\nOperacao %d: ", i + 1);
    scanf("%f %c %f", &operando1, &operador, &operando2);

    switch (operador)
    {
    case '+':
      resultado = operando1 + operando2;
      printf("\nResultado: %.2f", resultado);
      break;
    
    case '-':
      resultado = operando1 - operando2;
      printf("\nResultado: %.2f", resultado);
      break;
    
    case '/':
      if (operando2 == 0) {
        printf("\nResultado: ERRO - DIVISAO POR ZERO");
      } else {
        resultado = operando1 / operando2;
        printf("\nResultado: %.2f", resultado);
      }
      break;
    
    case '*':
      resultado = operando1 * operando2;
      printf("\nResultado: %.2f", resultado);
      break;

    default:
      printf("\nErro: operador nao reconhecido");
      break;
    }
  }

  return 0;
}
