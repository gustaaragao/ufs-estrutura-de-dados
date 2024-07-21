// Dado um conjunto de pontos do plano, como calcular o centroide?

#include <stdio.h>

#define MAX 100

struct ponto {
    double x;
    double y;
};

double calcular_area(struct ponto conjunto[MAX], int numeroPontos)
{
    double area = 0.0;

    for (int i = 0; i < numeroPontos; i++) {
        // No lugar do Ternario poderia ser: int j = (i + 1) % numeroPontos;
        int j = (i + 1 == numeroPontos) ? 0 : i + 1;

        area += (conjunto[i].x * conjunto[j].y - conjunto[j].x * conjunto[i].y);
    }

    area = area / 2;

    return area;
}

struct ponto calcular_centroide(struct ponto conjunto[MAX], int numeroPontos) 
{
    struct ponto centroide;
    centroide.x = centroide.y = 0;

    for (int i = 0; i < numeroPontos; i++) {
        int j = (i + 1 == numeroPontos) ? 0 : i + 1;
        centroide.x += (conjunto[i].x + conjunto[j].x) * (conjunto[i].x * conjunto[j].y - conjunto[j].x * conjunto[i].y);
        centroide.y += (conjunto[i].y + conjunto[j].y) * (conjunto[i].x * conjunto[j].y - conjunto[j].x * conjunto[i].y);
    }

    double area = calcular_area(conjunto, numeroPontos);

    centroide.x /= 6*area;
    centroide.y /= 6*area;

    return centroide;
}

int main()
{
    struct ponto centroide, conjunto[100];
    
    int numeroPontos = 0;

    printf("Digite o numero de Pontos: ");
    scanf("%d", &numeroPontos);

    for (int i = 0; i < numeroPontos; i++) {
        scanf("%lf %lf", &conjunto[i].x, &conjunto[i].y);
    }

    centroide = calcular_centroide(conjunto, numeroPontos);

    printf("\nCentroide: (%.2lf, %.2lf)", centroide.x, centroide.y);

    return 0;
}