#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador_arquivos.h"
#include "ArvoreBinaria_h\source\Cap5\ArvoreBinaria.h"
// #include "AVL/Cap5/ArvoreAVL.h"
// #include "RubroNegra/Cap5/ArvoreRubroNegra.h"

void incluirInfosArvore(pDArvore arvore, FILE* arq, long int quantidade);
void incluirInfosArvore(pDArvore arvore, FILE* arq, long int quantidade) {
    long int i;
    int num;
    for (i = 0; i < quantidade; i++) {
        fscanf(arq,"%d",&num);
        incluirInfo(arvore, alocaInt(num),comparaInt);
    }
}


int main() {
    srand(time(NULL));
    FILE* arq;
    pDArvore arvore = criarArvore(2);
    long int quantidade;
    clock_t inicio,fim;
    pNohArvore noh = NULL;
    arq = fopen(Arq1M,"r");
    quantidade = _1M;
    int numeroParaBuscaEExclusao = Num_Busca_1m;
    

    incluirInfosArvore(arvore,arq,quantidade);

    inicio = clock();
    noh = buscarInfo(arvore,alocaInt(numeroParaBuscaEExclusao), comparaInt);
    
    // excluirInfo(arvore, alocaInt(numeroParaBuscaEExclusao), comparaInt);
    

    fim = clock();
    printf("Tempo de excluir noh em 1m: %.10f segundos\n", 
            (double)(fim - inicio) / CLOCKS_PER_SEC);

    if (noh == NULL) {
        printf("Noh nao encontrado\n");
    } else {
        printf("Noh encontrado: %d\n", *(int*)noh->info);
    }
    fclose(arq);
    return 0;
}



