#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria_h\source\Cap5\ArvoreBinaria.h"
#include <time.h>

int main() {
    int quantidade;
    int i;
    FILE* arq = fopen("Numeros Aleatorios BENCHMARK.txt","r");

    quantidade = 1000;

    srand(time(NULL));
    
    pDArvore arvore = criarArvore(2);

    clock_t tempo_inserir_1000_infos_abb = clock();


    for (i = 0; i < quantidade; i++) {
        int numero_aleatorio = rand();
        incluirInfo(arvore, alocaInt(numero_aleatorio),comparaInt);
        printf("%d\n",numero_aleatorio);
        // fprintf(arq,"%d\n",numero_aleatorio);
        // int numero_aleatorio = fscanf(arq,"%d\n",numero_aleatorio);

    }

    // desenhaArvore(arvore,imprimeInt);

    printf("Tempo para ler %d numeros aleatorios: %.6f segundos\n", 
            (double)(clock() - tempo_inserir_1000_infos_abb) / CLOCKS_PER_SEC);

    fclose(arq);
    return 0;
}
