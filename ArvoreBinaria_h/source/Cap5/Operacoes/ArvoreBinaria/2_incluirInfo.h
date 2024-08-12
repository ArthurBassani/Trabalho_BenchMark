#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){
    if(raiz == NULL){
        pNohArvore pNovo = malloc(sizeof(pNohArvore));
        
        pNovo->direita = NULL;
        pNovo->esquerda = NULL;
        pNovo->info = info;

        return pNovo;
    }

    if(pfc(raiz->info,info) <= 0){
        raiz->esquerda = incluirInfoRecursivo(raiz->esquerda,info,pfc);
    }else{
        raiz->direita = incluirInfoRecursivo(raiz->direita,info,pfc);
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
    if(arvore->raiz == NULL){
        arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
    }else{
        incluirInfoRecursivo(arvore->raiz, info, pfc);
    }
}

#endif

