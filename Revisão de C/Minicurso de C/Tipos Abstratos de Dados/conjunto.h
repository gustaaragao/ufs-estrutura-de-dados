#define CONJUNTO_MAX 100

typedef struct {
    int elementos[CONJUNTO_MAX];
    int tamanho;
} Conjunto;

Conjunto conjunto_vazio();

int conjunto_contem(Conjunto a, int elemento);

Conjunto adicionar_elemento_conjunto(Conjunto a, int elemento);

Conjunto ler_conjunto();

void imprimir_conjunto(Conjunto c);

Conjunto conjunto_uniao(Conjunto a, Conjunto b);

Conjunto conjunto_intersecao(Conjunto a, Conjunto b);

Conjunto conjunto_diferenca(Conjunto a, Conjunto b);

Conjunto remover_elemento_conjunto(Conjunto a, int elemento);