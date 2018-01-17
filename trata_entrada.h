#include "bandeirola.h"

// Definições cujo proposito é auxiliar na legibilidade
#define sc_char(c) scanf("%c", &c)
#define sc_int_1(a) scanf("%d", &a)
#define sc_int_2(a, b) scanf("%d %d", &a, &b)

/* FUNÇÃO: particao
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: a rua a ser particionada no QuickSort 
** -> int inicio: a partir de que bar ordenamos
** -> int fim: até que bar ordenamos
**
** FUNCIONAMENTO:
** Escolhe o pivot sempre como o bar inicial e caminha na partição da rua 
** a fim de identificar as posições que podem ser trocadas, efetuando a 
** troca quando necessário.
**
** SAÍDA: 
** Último índice alcançado na partição.
** 
** COMPLEXIDADE:
** O(log(n))
*/
int particao(bandeirola *rua, int inicio, int fim);

/* FUNÇÃO: quicksort
**
** PARÂMETROS DE ENTRADA: 
** -> bandeirola *rua: a rua a ser ordenada pelo QuickSort 
** -> int inicio: a partir de que bar ordenamos (inicia-se do zero)
** -> int fim: até que bar ordenamos (inicia-se pelo N - 1, último bar)
**
** FUNCIONAMENTO:
** Particiona recursivamente a rua, ordenando por bares em ordem crescente,
** de partição em partição.
**
** SAÍDA: 
** Void. Vetor ordenado a partir de seu endereço.
**
** COMPLEXIDADE:
** O(n * log(n))
*/
void quicksort(bandeirola *rua, int inicio, int fim);


/* FUNÇÃO: preenche_rua
**
** PARÂMETROS DE ENTRADA: 
** -> int *N: a quantidade de bares/casas
** -> int *x: determinado bar de índice i da entrada
** -> int *y: determinada casa de índice i da entrada
**
** FUNCIONAMENTO:
** Lê os dados da rua, basicamente cada bar, associando-o respectivamente à
** sua casa. Utiliza-se da entrada por motivos de evitar variáveis globais.
** Importante: assume-se aqui que todo bar é par e toda casa é ímpar, para
** o correto tratamento do problema enquanto de LIS (Longest Increasing Subsequence).
**
** SAÍDA: 
** Uma alocação da rua completa, devidamente usada na função main do programa.
**
** COMPLEXIDADE:
** O(N)
*/
bandeirola *preenche_rua(int *N, int *x, int *y);

/* FUNÇÃO: seleciona_algoritmo
**
** PARÂMETROS DE ENTRADA: 
** -> char algoritmo: caractere de seleção, informado na entrada
** -> bandeirola *rua: rua sobre a qual processaremos o tamanho da LIS
** -> int N: quantidade de casas/bares na rua
**
** FUNCIONAMENTO:
** Escolhe, a partir do caractere de seleção, qual dos três algoritmos
** disponíveis deve ser usado para calcular o tamanho da LIS (guloso, 
** força bruta ou dinâmico - 'g', 'b' ou 'd')
**
** SAÍDA: 
** Void. Printa o resultado na saída padrão.
**
** COMPLEXIDADE:
** O(1), considerando somente a seleção pelo switch
*/
void seleciona_algoritmo(char algoritmo, bandeirola *rua, int N);
