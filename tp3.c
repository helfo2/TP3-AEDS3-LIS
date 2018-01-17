#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "trata_entrada.h"

#define DEFAULT_INT 0
#define DEFAULT_CHAR 0

// https://stackoverflow.com/questions/28000601/patience-sort-and-finding-the-longest-increasing-subsequence
// https://leetcode.com/articles/longest-increasing-subsequence/

int main(void) {
	char algoritmo = DEFAULT_CHAR; sc_char(algoritmo); // lê qual algoritmo usaremos

	int N = DEFAULT_INT;
	int x = DEFAULT_INT, y = DEFAULT_INT;
	
	// *** lê bares e respectivas casas, separando os bares em pares
	// e as casas em ímpares
	bandeirola* rua = preenche_rua(&N, &x, &y); 

	// *** ordena a rua (parese casa-bar) em termos somente das casas,
	quicksort(rua, 0, N - 1);

	// executa o código de processamento requerido
	seleciona_algoritmo(algoritmo, rua, N);

	free(rua);

	return 0;
}

// *** possibilitam tratar o problema como tamanho de Longest Increasing Subsequence
