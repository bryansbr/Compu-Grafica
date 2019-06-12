/*

Nombre del archivo: main.cpp
Fecha de creación: 28/05/2019
Fecha de modificación: 28/05/2019
Autores: Bryan Steven Biojó       1629366-3743
		 Herney Eduardo Quintero  1528556-3743

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

/*

Para ejecutar correctamente el programa, la información tiene que estar de la siguiente manera en el archivo plano:

5 --> Tamaño de las dos matrices.

1 2 3 8 4      ------------
9 4 2 3 5                  |
14 11 27 35 40   Matriz 1  |
26 27 34 41 55             |
10 20 30 40 50 ------------

4 7 0 11 21    ------------
8 2 7 0 1                  |
3 12 15 18 24    Matriz 2  |
7 10 19 17 20              |
25 24 33 45 50 ------------

*/

int main(void) {
	freopen("matrices.txt","r",stdin); //Leemos la información desde un archivo plano.
	int n; //Tamaño de la matriz.
	scanf("%d", &n); //Leemos el tamaño de la matriz.
	int firstMatrix[n][n], secondMatrix[n][n]; //Declaramos las matrices.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &firstMatrix[i][j]); //Leemos los datos de la primer matriz.
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &secondMatrix[i][j]); //Leemos los datos de la segunda matriz.
		}
	}

	int firstTransMatrix[n][n], secondTransMatrix[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// Trasponemos las matrices.
			firstTransMatrix[i][j] = firstMatrix[j][i];
			firstTransMatrix[j][i] = firstMatrix[i][j];
			secondTransMatrix[i][j] = secondMatrix[j][i];
			secondTransMatrix[j][i] = secondMatrix[i][j];
		}
	}

	printf("La traspuesta de la primera matriz es:\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d", firstTransMatrix[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", firstTransMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("La traspuesta de la segunda matriz es:\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d", secondTransMatrix[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", secondTransMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int matrixProduct[n][n]; //Matriz con el producto.
	memset(matrixProduct,0,sizeof(matrixProduct)); //Inicializamos Matriz.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				matrixProduct[i][j] += (firstMatrix[i][k]*secondMatrix[k][j]);
			}
		}
	}

	printf("El producto entre la primera matriz y la segunda matriz es:\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d", matrixProduct[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", matrixProduct[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
