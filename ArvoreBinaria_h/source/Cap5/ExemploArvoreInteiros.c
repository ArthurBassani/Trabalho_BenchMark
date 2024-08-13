#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(4), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(7), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(6), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(8), comparaInt);
    
    printf("\n");

    desenhaArvore(pArvoreInt, imprimeInt);
    excluirInfo(pArvoreInt, alocaInt(4), comparaInt);
    desenhaArvore(pArvoreInt, imprimeInt);
    printf("\n\n");

}