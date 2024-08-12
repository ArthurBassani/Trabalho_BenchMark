#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (pfc(raiz->info, info) == 0)
    {
        return raiz;
    }

    if (raiz->esquerda != NULL)
        buscarInfoRecursivo(raiz->esquerda, info, pfc);
    if (raiz->direita != NULL)
        buscarInfoRecursivo(raiz->direita, info, pfc);
}

/* ----------------------------------------------------------*/
pNohArvore buscarInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore->raiz == NULL)
    {
        printf("Arvore sem informações\n");
    }
    return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif
