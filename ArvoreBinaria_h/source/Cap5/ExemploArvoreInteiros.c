#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    
    emOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");

    desenhaArvore(pArvoreInt, imprimeInt);

}
