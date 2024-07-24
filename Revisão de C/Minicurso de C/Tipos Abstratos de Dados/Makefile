all: conjunto matriz

conjunto: conjuntos_cliente.o conjunto.o
	gcc conjuntos_cliente.o conjunto.o -lm -o conjunto

conjuntos_cliente.o:
	gcc -std=c99 -Wall -Werror -Wvla -c conjuntos_cliente.c

conjunto.o: conjunto.c conjunto.h
	gcc -std=c99 -Wall -Werror -Wvla -c conjunto.c

matriz: matrizes_cliente.o matrizes.o
	gcc matrizes_cliente.o matrizes.o -lm -o matriz

matrizes_cliente.o:
	gcc -std=c99 -Wall -Werror -Wvla -c matrizes_cliente.c

matrizes.o: matrizes.c matrizes.h
	gcc -std=c99 -Wall -Werror -Wvla -c matrizes.c

clean:
	del -f *.o conjunto.exe matriz.exe