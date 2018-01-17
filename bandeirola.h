#include <stdio.h>
#include <stdlib.h>

/* TAD: bandeirola
**
** ITENS: 
** -> int bar: o número do bar de índice i da entrada
** -> int casa: o número da casa de índice i da entrada
**
** FUNCIONAMENTO:
** É basicamente um pair que guarda o bar e a casa do respectivo dono.
** Importante: assume-se sempre o bar sendo par e a casa sendo ímpar.
** ("cada um de um lado da rua")
**
*/
typedef struct bandeirola {
	int bar;
	int casa;
} bandeirola;

/* FUNÇÃO: par
**
** PARÂMETRO DE ENTRADA: 
** -> int a: número a ser analisado
**
** FUNCIONAMENTO:
** Determina se número é par. Usado para a completude da rua.
**
** SAÍDA:
** 1 caso número seja par, 0 caso seja ímpar. Comportamento booleano.
**
** COMPLEXIDADE:
** O(1)
*/
int par(int a);

/* FUNÇÃO: max
**
** PARÂMETROS DE ENTRADA: 
** -> int a: número a ser analisado
** -> int b: número a ser analisado
**
** FUNCIONAMENTO:
** Determina qual dos números é o maior.
**
** SAÍDA:
** Caso a > b, retorna a. Caso a <= b, retorna b. Usado no cálculo por força bruta.
**
** COMPLEXIDADE:
** O(1)
*/
int max(int a, int b);

/* FUNÇÃO: troca
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *a: endereço de um par casa-bar
** -> bandeirola *b: endereço de um par casa-bar
**
** FUNCIONAMENTO:
** Troca os pares de posição, um com o outro. 
**
** SAÍDA:
** Void. Comportamento swap, utiliza-se de par temporário.
**
** COMPLEXIDADE:
** O(1)
*/
void troca(bandeirola *a, bandeirola *b);


/* FUNÇÃO: calcula_forca_bruta
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: vetor de pares casa-bar
** -> int casa_anterior: casa da qual podemos partir para conectar a bandeirola ao bar
** -> int casa_atual: casa para a qual podemos ir para conectar a bandeirola ao bar
** -> int n: quantidade de pares casa-bar
**
** FUNCIONAMENTO:
** Verificamos sempre ambas as possibilidades (pendurar ou não a bandeirola), 
** da seguinte maneira: tem-se dois contadores, um que recebe a quantidade acrescida
** de 1 da possibilidade de se pendurar a bandeirola da casa atual em seu bar e deste na
** próxima casa e outro que recebe a quantidade de não se pendurar, ou seja, continuar
** no estado atual. Ambos os contadores são atualizados percorrendo-se o vetor de pares
** de maneira recursiva, e daí é decidido qual o maior deles, ou seja, qual a maior
** quantidade de bandeirolas que podemos pendurar.
**
** SAÍDA:
** Maior entre os contadores (amarra e nao_amarra). Em outras palavras, o tamanho
** da LIS entre as casas.
**
** COMPLEXIDADE:
** O(2^(n))
*/
int calcula_forca_bruta(bandeirola *rua, int casa_anterior, int i_casa_atual, int n);

/* FUNÇÃO: forca_bruta
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: vetor de pares casa-bar
** -> int n: quantidade de pares casa-bar, tamanho do vetor rua
**
** FUNCIONAMENTO:
** Chama a função calcula_forca_bruta, inicializando seu processamento
** com a flag -1 para a primeira casa (casa_anterior), 0 para a casa_atual
** e, obviamente, n para o tamanho da rua.
**
** SAÍDA:
** Simplesmente o retorno de calcula_forca_bruta, ou seja, o tamanho
** da LIS entre as casas.
**
** COMPLEXIDADE:
** O(1), considerando que somente chama a função calcula_força_bruta, inicializando-a
*/
int forca_bruta(bandeirola *rua, int n);


/* FUNÇÃO: busca_binaria_casa
**
** PARÂMETROS DE ENTRADA: 
** -> int *rua: vetor da LIS correspondente aos números das casas da rua
** -> int inicio: índice fora do vetor (flag -1)
** -> int fim: último índice do vetor (tam - 1)
** -> int casa: casa buscada
**
** FUNCIONAMENTO:
** Partindo da ordenação garantida do LIS, podemos efetuar busca binária no vetor.
** A partir do índice mediano, reduzimos o vetor até encontrarmos a chave. Caso a chave
** Caso seja menor do que o valor correspondente ao índice mediano, procuramos a chave
** na parte esquerda. Caso seja maior, na parte direita.
**
** SAÍDA:
** Índice da chave buscada.
**
** COMPLEXIDADE:
** O(log(n))
*/
int busca_binaria_casa(int* rua, int inicio, int fim, int casa);

/* FUNÇÃO: guloso
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: vetor de pares casa-bar
** -> int n: quantidade de pares casa-bar
**
** FUNCIONAMENTO:
** Parte do algortimo de Patience Sorting, explicado em maior profundidade na documentação.
** Basicamente, adicionamos toda casa maior do que a atual ao fim de pilha  auxiliar 
** que guarda a LIS. Garantimos a corretude sem voltar atrás pelo fato de sempre a
** casa candidata ir para o final da pilha. 
** Importante: tratamos a LIS a partir das casas porque matematicamente não
** faz diferença seu tamanho caso tratássemos a partir do bar (proporção 1:1). 
** Os bares, contudo, encontram-se ordernados. 
** É justamente esse fato que possibilita tratar o problema como LIS. 
**
** SAÍDA:
** Tamanho da pilha de "cartas" que contém a Longest Increasing Subsequence.
**
** COMPLEXIDADE:
** O(n * log(n))
*/
int guloso(bandeirola *rua, int n);

/* FUNÇÃO: programacao_dinamica
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: vetor de pares casa-bar
** -> int n: quantidade de pares casa-bar
**
** FUNCIONAMENTO:
** Cria-se um vetor da programação dinâmica de tamanho n. Inicia-se a primeira posição com 
** o valor 1 (tamanho da LIS até então). Percorre-se esse vetor até o fim, considerando
** o seguinte: até o elemento do índice, caso haja alguma casa de número maior, a colocamos
** na LIS, atualizando o valor de seu tamanho (pelo valor encontrado no vetor da DP). 
** Após fixar cada índice, atualizamos seu valor com o máximo tamanho (atualizado conforme o raciocínio acima) + 1.
** Basta, daí, encontrar a quantidade máxima obtida.
** Importante: tratamos a LIS a partir das casas porque matematicamente não
** faz diferença seu tamanho caso tratássemos a partir do bar (proporção 1:1). 
** Os bares, contudo, encontram-se ordernados. 
** É justamente esse fato que possibilita tratar o problema como LIS. 
**
** SAÍDA:
** A quantidade máxima de itens, encontrada no vetor da DP.
**
** COMPLEXIDADE:
** O((n) ^ 2)
*/
int programacao_dinamica(bandeirola *rua, int n);
