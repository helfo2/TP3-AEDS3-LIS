#include <stdlib.h>

#include "bandeirola.h"

int par(int a) {
	if(a % 2 == 0) return 1;
	else return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

void troca(bandeirola *a, bandeirola *b) {
	bandeirola t = *a;
	*a = *b;
	*b = t;
}

int calcula_forca_bruta(bandeirola *rua, int casa_anterior, int i_casa_atual, int n) {
	if(i_casa_atual == n) return 0;
	int amarra = 0;
    
    if(rua[i_casa_atual].casa > casa_anterior) {
        amarra = 1 + calcula_forca_bruta(rua, rua[i_casa_atual].casa, i_casa_atual + 1, n);
    }
    
    int nao_amarra = calcula_forca_bruta(rua, casa_anterior, i_casa_atual + 1, n);
    
    return max(amarra, nao_amarra); // O(2ˆn)
}

int forca_bruta(bandeirola *rua, int n) {
	return calcula_forca_bruta(rua, -1, 0, n);
}

int busca_binaria_casa(int* rua, int inicio, int fim, int casa) {
    while(fim - inicio > 1) {
	    int meio = inicio + (fim - inicio) / 2;
	    
	    if(rua[meio] >= casa) fim = meio;
	    else inicio = meio;
    }
 
    return fim;
}

int guloso(bandeirola *rua, int n) {
    int *aux = (int*)malloc(n * sizeof(int)); // auxiliar, guarda as casas da LIS
    int tam = 1; // pilha de "cartas" "vazia", supomos ao menos uma carta
 	int i;

    aux[0] = rua[0].casa; // inicia-se da primeira casa
    for(i = 1; i < n; i++) {
        if(rua[i].casa < aux[0]) { // casa atual tem número menor
            aux[0] = rua[i].casa; // temos uma casa de número menor, iniciamos dela
        }
        else if(rua[i].casa > aux[tam - 1]) { // casa atual tem número maior
            aux[tam++] = rua[i].casa; // supomos, sem voltar atrás, a nova casa no fim da LIS
        }
        else { // casas tem números iguais, temos um candidato para o fim da LIS
            // identificamos onde se encontra (último índice) a casa candidata na pilha de LIS
            // isso garante que teremos uma nova LIS, como se jogássemos fora os elementos maiores do que a casa candidata
            aux[busca_binaria_casa(aux, -1, tam - 1, rua[i].casa)] = rua[i].casa;
        }
    }
 	
 	free(aux); // como só nos interessa o tamanho, não a LIS em si

    return tam; 
}

int programacao_dinamica(bandeirola *rua, int n) {
	int *dp = (int*)malloc(n * sizeof(int));
	dp[0] = 1;
	int tam = 1, i, j;
	
	for(i = 1; i < n; i++) {
		int max_bandeiras = 0;
		for(j = 0; j < i; j++) {
			if(rua[i].casa > rua[j].casa) { // inclui-se essa casa na LIS
				max_bandeiras = max(max_bandeiras, dp[j]);
			}
		}

		// adiciona-se à posição i uma casa à mais do tamanho máximo que ela pode conter
		dp[i] = max_bandeiras + 1; 
		tam = max(tam, dp[i]); // pega-se o tamanho máximo, ou seja, o tamanho da LIS
	}
	
	return tam;
}
