#include "trata_entrada.h"

int particao(bandeirola *rua, int inicio, int fim) {
	int pivot = rua[inicio].bar; // sempre a partir do início
	int i = inicio - 1;
	int j = fim + 1;
	
	while(1) { // percorre toda a partição, se necessário
		while(rua[++i].bar < pivot);
		while(rua[--j].bar > pivot);
		
		if(i >= j) return j;
		troca(&rua[i], &rua[j]); // troca valores fora de ordem
	}
}

void quicksort(bandeirola *rua, int inicio, int fim) { 
	if(inicio < fim) {
		int p = particao(rua, inicio, fim); // particiona
		quicksort(rua, inicio, p); // particiona primeira metade
		quicksort(rua, p + 1, fim); // particiona segunda metade
	}
}

bandeirola *preenche_rua(int *N, int *x, int *y) {
	sc_int_1(*N); // lê quantidade de casas/bares

	bandeirola* rua = (bandeirola*)malloc((*N) * sizeof(bandeirola));

	int i;
	for(i = 0; i < (*N); i++) {
		sc_int_2((*x), (*y));
		
		if(par(*x)) { // assume que todo bar é par
			rua[i].bar = (*x);
			rua[i].casa = (*y);
		} else { // se o x não é o par, o y é pelo padrão da entrada
			rua[i].bar = (*y);
			rua[i].casa = (*x);
		}
	}

	return rua; // rua "completa"
}

void seleciona_algoritmo(char algoritmo, bandeirola *rua, int N) {
	switch(algoritmo) { // seleciona por qual meio a solução de tamanho de LIS será calculada
		case 'g': printf("%d\n", guloso(rua, N));
				  break;
		case 'd': printf("%d\n", programacao_dinamica(rua, N));
				  break;
		case 'b': printf("%d\n", forca_bruta(rua, N));
				  break;
		default: break; // faz nada caso não seja um dos três algortimos
	}
}
