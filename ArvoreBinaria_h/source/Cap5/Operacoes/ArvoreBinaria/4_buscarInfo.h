#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL){
        return NULL;
    }
    int result = pfc(raiz->info, info);
    if (result == 0)
        return raiz;
    
    if (result < 0)
        return buscarInfoRecursivo(raiz->esquerda, info, pfc);
    if (result > 0)
        return buscarInfoRecursivo(raiz->direita, info, pfc);

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
