#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include <stdlib.h>
/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL) return raiz;

    int result = pfc(raiz->info, info);
    
    if (result < 0)
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);   
    if (result > 0)
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);

    if (result == 0){

        if (raiz->esquerda == NULL)
        {
            pNohArvore pNoh = raiz->direita;
            free(raiz);
            return pNoh;
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore pNoh = raiz->esquerda;
            free(raiz);
            return pNoh;
        }
        pNohArvore pAux = raiz->direita ;
        while (pAux != NULL && pAux->esquerda != NULL)
        {
            pAux = pAux->esquerda;
        }
        raiz->info = pAux->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, pAux->info, pfc);
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore->raiz == NULL)
    {
        printf("Arvore sem Nohs\n");
        return 0;
    }
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 1;
}

#endif
