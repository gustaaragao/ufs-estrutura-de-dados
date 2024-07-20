# Resolução dos Exemplos

## Exemplo 01. Calcule a Complexidade desse algoritmo.
```c
soma = 0;
for(x=0; x<n; x++) {
  if (vetor[x] % 2 == 0)
    soma = soma + vetor[x];
}
media = soma / n;
```
### Resolução: 
```c
soma = 0;                     // 1
for(x=0; x<n; x++) {          // 1 + (n + 1) + n*(1 + 1) = 3n + 2
  if (vetor[x] % 2 == 0)      // n * (1 + 1) = 2n
    soma = soma + z;          // n * (1 + 1) = 2n
}
media = soma / n;             // 2

// f(n) = 1 + (3n + 2) + 2n + 2n + 2 -> f(n) = 7n + 5.
```

## Exemplo 02. Calcule a Complexidade desse algoritmo.
```c
for(x=0; x < n-1; x++) {
  for(y = 1; y < n; y++) {
    if(vetor[x] > vetor[y]) {
      aux = vetor[x];
      vetor[x] = vetor[y];
      vetor[y] = aux;
    }
  }
}
```
### Resolução: 
```c
// Resolução usando a abordagem de "simplificação" ===> for -> while

int x = 0;                        // 1 
while (x < n - 1) {               // 2n
  int y = 1;                      // (n - 1)
  while (y < n) {                 // (n) * (n - 1)
    if(vetor[x] > vetor[y]) {     // (n - 1) * (n - 1)
      aux = vetor[x];             // (n - 1) * (n - 1)
      vetor[x] = vetor[y];        // (n - 1) * (n - 1)
      vetor[y] = aux;             // (n - 1) * (n - 1)
    }
    y = y + 1;                    // 2 * (n - 1) * (n - 1)
  }
  x = x + 1;                      // 2 * (n - 1)
}
/*
f(n) = 1 + 2n + (n - 1) + n² - n + (6n² - 12n + 6) + 2n - 2
f(n) = 7n² - 8n + 4
*/

// ------------------------------------------------------------------------

// Resolução direta
for(x=0; x < n-1; x++) {          // (1) + (n) * 2 + (n-1) * 2 = 4n - 1
  for(y = 1; y < n; y++) {        // (1) + (n) + (n-1) * 2 = (3n - 1) * (n - 1) = 3n² - 4n + 1
    if(vetor[x] > vetor[y]) {     // (1) * (n - 1) * (n - 1) = n² - 2n + 1
      aux = vetor[x];             // (1) * (n - 1) * (n - 1) = n² - 2n + 1
      vetor[x] = vetor[y];        // (1) * (n - 1) * (n - 1) = n² - 2n + 1
      vetor[y] = aux;             // (1) * (n - 1) * (n - 1) = n² - 2n + 1
    }
  } // -> Esse bloco executa (n - 1) vezes
} // -> Esse bloco executa (n - 1) vezes

/*
f(n) = 4 * (n² - 2n + 1) + (3n² - 4n + 1) + (4n - 1) = 7n² - 8n + 4.
*/
```
# Resolução dos Exercícios

## Exercício 01. Cada uma das seguintes fórmulas representa o número de operações de determinado algoritmo. Exprimir cada uma delas usando a notação O:
```
a) n² + 5n  -> O(n²)

b) 3n² + 5n -> O(n²)

c) (n + 7)(n – 2) -> O(n²)

d) 100n + 5 -> O(n)

e) 6Log₂N + 9N -> O(Log₂N)

f) 3N⁴ + NLog₂N -> O(n⁴)

g) 5N² + N³/2 -> O(n³)


# Cheat sheet
|-> Considere os coeficientes iguais a 1.
|-> O(1) > O(logN) > O(Log₂N) > O(N) > O(NlogN) > O(N²) > O(N³) > O(2ᴺ)
```

## Exercício 02. Escrever um trecho de programa contendo um laço para calcular a soma de todos os números inteiros de 1 a n. Fazer uma análise do tempo requerido, contando o número de somas e atribuições efetuadas e a seguir concluir qual a ordem do algoritmo.

```c 
int soma = 0;                       // 1

for (int i = 1; i < n + 1; i++) {   // 1 + 2 * (n + 1) + 2 * n = 4n + 3
  soma = soma + i;                  // n * (2) = 2n
}

// f(n) = 1 + (4n + 3) + 2n = 6n + 4.
```

## Exercício 03. Calcular a complexidade do seguinte trecho de programa:

```pascal
I := 1;
while I <= N do begin
  J := 1;
  while J <= N do begin
    K := 1;
    while K <= N do begin
      Writeln(I, J, K);
      K := K + 1;
    end;
    J := J + 1;
  end;
  I := I + 1;
end;
```

## Resolução: 
```pascal
I := 1;                     // 1
while I <= N do begin       // n + 1 = n + 1
  J := 1;                   // 1 * n = n
  while J <= N do begin     // (n + 1) * n = n² + n
    K := 1;                 // n * n * 1 = n²
    while K <= N do begin   // n * n * (n + 1) = n³ + n²
      Writeln(I, J, K);     // n * n * n * 1 = n³
      K := K + 1;           // n * n * n * 2 = 2n³
    end;
    J := J + 1;             // n * n * 2 = 2n²
  end;
  I := I + 1;               // n * 2 = 2n
end;

// f(n) = 1 + (n + 1) + n + (n² + n) + n² + (n³ + n²) + n³ + 2n³ + 2n² + 2n
// f(n) = 4n³ + 5n² + 5n + 2  -> O(n³)
```