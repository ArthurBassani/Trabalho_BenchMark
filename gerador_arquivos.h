#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Arq1k "1k Numeros Aleatorios BENCHMARK.txt"
#define Arq10k "10k Numeros Aleatorios BENCHMARK.txt"
#define Arq100k "100k Numeros Aleatorios BENCHMARK.txt"
#define Arq1M "1M Numeros Aleatorios BENCHMARK.txt"
#define Num_Busca_1k 18792
#define Num_Busca_10k 7276
#define Num_Busca_100k 26051
#define Num_Busca_1m 8350
#define _1k 1000
#define _10k 10000
#define _100k 100000
#define _1M 1000000

long int gerarLongIntAleatorio();
int gerarNumerosAleatorios(char nomeArquivo[],long int quantidade);

long int gerarLongIntAleatorio() {
    long int num = ((long int)rand() * RAND_MAX) + rand();
    return num;
}
int gerarNumerosAleatorios(char nomeArquivo[],long int quantidade) {
    FILE* arq = fopen(nomeArquivo,"w");
    long int i;
    srand(time(NULL));
    for (i = 0; i < quantidade; i++) {
        fprintf(arq,"%ld\n",rand());
    }
    fclose(arq);
    return 0;
}



void gera_arquivo_1k_numeros() {
    long int quantidade = 1000;
    gerarNumerosAleatorios(Arq1k,quantidade);
}

void gera_arquivo_10k_numeros() {
    long int quantidade = 10000;
    gerarNumerosAleatorios(Arq10k,quantidade);
}
void gera_arquivo_100k_numeros() {
    long int quantidade = 100000;
    gerarNumerosAleatorios(Arq100k,quantidade);
}
void gera_arquivo_1M_numeros() {
    long int quantidade = 1000000;
    gerarNumerosAleatorios(Arq1M,quantidade);
}

