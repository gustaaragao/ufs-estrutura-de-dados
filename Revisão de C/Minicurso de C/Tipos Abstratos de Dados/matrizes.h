#define MATRIZ_MAX 100

typedef struct {
    double elementos[MATRIZ_MAX][MATRIZ_MAX];
    int nLinhas;
    int nColunas;
} Matriz;

Matriz matriz_nova(int linhas, int colunas , double elementos[][MATRIZ_MAX]);

void imprimir_matriz(Matriz m);

Matriz soma_matrizes(Matriz m1, Matriz m2);

Matriz multiplicacao_matrizes(Matriz m1, Matriz m2);

Matriz multiplicacao_por_escalar_matrizes(Matriz m, double escalar);
