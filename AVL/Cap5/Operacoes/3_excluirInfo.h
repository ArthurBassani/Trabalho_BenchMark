#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include <stdlib.h>

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){
    if (raiz == NULL)return raiz;
    //Caso 1 e 2 - N� com nenhum ou 1 filho
    int res = pfc(info, raiz->info);
    if (res < 0){
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else if (res > 0){
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);   
    }
    else{
        if (raiz->esquerda == NULL)
        {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        //Caso 3 - Noh com 2 filhos
        pNohArvore pAux = raiz->direita ;
        while (pAux != NULL && pAux->esquerda != NULL)
        {
            pAux = pAux->esquerda;
        }
        raiz->info = pAux->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, pAux->info, pfc);
    }
    
    raiz->fb = alturaRecursiva(raiz->direita) -
               alturaRecursiva(raiz->esquerda);

    if (raiz->fb == 2 || raiz->fb == -2)
    {
        // precisa balancear, ent�o verifica qual rota��o aplicar
        if (raiz->fb == 2)
        {
            // sinais iguais -> rota��o simples
            if ((raiz->direita  != NULL && (raiz->direita->fb  == 1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL  && (raiz->esquerda->fb == 1 || raiz->esquerda->fb == 0)))
            {
                printf("rotacao simples esquerda\n");
                // rotacao simples esquerda
                pNohArvore novaRaiz = rotacaoEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            // sinais diferentes -> rotacao dupla direita-esquerda
            if ((raiz->direita != NULL && raiz->direita->fb  == -1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == -1))
            {
                printf("rotacao dupla direita-esquerda\n");
                // rotacao dupla direita-esquerda
                pNohArvore novaRaiz = rotacaoDireitaEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }
        }


        if (raiz->fb == -2)
        {
            // sinais iguais -> rota��o simples
            if ((raiz->direita != NULL && (raiz->direita->fb  == -1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL && (raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0)))
            {
                printf(" -> Rotacao simples Direita <- ");
                printf("rotacao simples direita\n");
                // rotacao simples direita
                pNohArvore novaRaiz = rotacaoDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            // sinais diferentes -> rotacao dupla
            if ((raiz->direita != NULL && raiz->direita->fb  == 1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == 1))
            {
                printf("rotacao dupla esquerda-direita\n");
                // rotacao dupla esquerda-direita
                pNohArvore novaRaiz = rotacaoEsquerdaDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }
        }
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 0;
}
#endif
