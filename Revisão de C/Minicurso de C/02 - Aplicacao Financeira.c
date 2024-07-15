/*
Dada uma aplicação financeira com:
• depósito inicial inicial reais,
• depósitos mensais de mensal reais,
• juros mensais de juros porcento ao mês
• e um número de meses meses,

calcule o valor final da aplicação.
*/

#include <stdio.h>

int main()
{
    float depositoInicial, depositoMensal, taxaDeJuros, valorFinal;
    int meses;

    printf("Digite o deposito inicial: ");
    scanf("%f", &depositoInicial);
    
    printf("\nDigite o valor do deposito mensal: ");
    scanf("%f", &depositoMensal);
    
    printf("\nDigite a taxa de Juros Mensal: ");
    scanf("%f", &taxaDeJuros);

    printf("\nNumero de meses: ");
    scanf("%d", &meses);

    valorFinal = depositoInicial;

    for (int i = 0; i < meses; i++) {
        valorFinal = valorFinal * (1 + (taxaDeJuros / 100));
        valorFinal = valorFinal + depositoInicial;
    }

    printf("O valor final da aplicacao: %.2f\n", valorFinal);

    return 0;
}