#ifndef ALTURA_ARVORE_BINARIA_H
#define ALTURA_ARVORE_BINARIA_H

int altura (pNohArvore raiz){
    if(raiz == NULL) return 0;
    if(raiz->esquerda == NULL && raiz->esquerda == NULL) return 0;

    int alturaEsq, alturaDir;

    alturaEsq = 1 + altura(raiz->esquerda);
    alturaDir = 1 + altura(raiz->direita);

    if(alturaEsq > alturaDir) return alturaEsq;

    return alturaDir;
}


#endif