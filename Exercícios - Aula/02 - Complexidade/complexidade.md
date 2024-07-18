# Resolução dos Exercícios

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
soma = 0;
for(x=0; x<n; x++) {
  if (vetor[x] % 2 == 0)
    soma = soma + vetor[x];
}
media = soma / n;
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

## Exercício 01. Cada uma das seguintes fórmulas representa o número de operações de determinado algoritmo. Exprimir cada uma delas usando a notação O:
```
a) n² + 5n

b) 3n² + 5n

c) (n + 7)(n – 2)

d) 100n + 5

e) 6Log₂N + 9N

f) 3N⁴ + NLog₂N

g) 5N² + N³/2
```

## Exercício 02. Escrever um trecho de programa contendo um laço para calcular a soma de todos os números inteiros de 1 a n. Fazer uma análise do tempo requerido, contando o número de somas e atribuições efetuadas e a seguir concluir qual a ordem do algoritmo.

```c 

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

```