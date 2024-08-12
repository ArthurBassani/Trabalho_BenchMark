#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc)
{
    pNohArvore prox = NULL;
    if (fc(info, raiz->info) == 0)
    {
        return raiz;
    }

    if (raiz->esquerda != NULL)
        prox = excluirInfoRecursivo(raiz->esquerda, info, fc);

    if (prox != NULL)
    {
        if (prox->direita == NULL && prox->esquerda == NULL) // CASO SEJA UMA FOLHA
            raiz->esquerda = NULL;

        if (prox->direita == NULL && prox->esquerda != NULL) // CASO TENHA 1 FILHO NA DIREITA
            raiz->esquerda = prox->esquerda;

        if (prox->direita != NULL && prox->esquerda == NULL) // CASO TENHA 1 FILHO NA ESQUERDA
            raiz->direita = prox->direita;

        if (prox->direita != NULL && prox->esquerda != NULL) // CASO TENHA 2 FILHOS
        {
            int esq = -fc(info, prox->esquerda->info);
            int dir = fc(info, prox->direita->info);

            pNohArvore pDir = prox->direita;
            pNohArvore pEsq = prox->esquerda;
            pNohArvore pAux;
            if (esq < dir)
            {
                pAux = pEsq;
                while (pAux->direita != NULL)
                {
                    pAux = pAux->direita;
                }
                pAux->direita = pDir;
                raiz->esquerda = pEsq;
            }
            else
            {
                pAux = pDir;
                while (pAux->esquerda != NULL)
                {
                    pAux = pAux->esquerda;
                }
                pAux->esquerda = pEsq;
                raiz->esquerda = pDir;
            }
        }
        free(prox);
        return NULL;
    }

    if (raiz->direita != NULL)
        prox = excluirInfoRecursivo(raiz->direita, info, fc);

    if (prox != NULL)
    {
        if (prox->direita == NULL && prox->esquerda == NULL) // CASO SEJA UMA FOLHA
            raiz->direita = NULL;

        if (prox->direita == NULL && prox->esquerda != NULL)
            raiz->esquerda = prox->esquerda;

        if (prox->direita != NULL && prox->esquerda == NULL)
            raiz->direita = prox->direita;

        if (prox->direita != NULL && prox->esquerda != NULL)
        {
            int esq = fc(prox->esquerda->info, info);
            int dir = -fc(prox->direita->info, info);

            pNohArvore pDir = prox->direita;
            pNohArvore pEsq = prox->esquerda;
            pNohArvore pAux;
            if (esq < dir)
            {
                pAux = pEsq;
                while (pAux->direita != NULL)
                {
                    pAux = pAux->direita;
                }
                pAux->direita = pDir;
                raiz->direita = pEsq;
            }
            else
            {
                pAux = pDir;
                while (pAux->esquerda != NULL)
                {
                    pAux = pAux->esquerda;
                }
                pAux->esquerda = pEsq;
                raiz->direita = pDir;
            }
        }
        free(prox);
        return NULL;
    }
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore->raiz == NULL)
    {
        printf("Arvore sem Nohs\n");
        return 0;
    }

    if (pfc(arvore->raiz->info, info) == 0)
    {
        pNohArvore pRaiz = arvore->raiz;
        if (pRaiz->esquerda != NULL && pRaiz->direita == NULL)
        {
            arvore->raiz = pRaiz->esquerda;
        }
        if (pRaiz->direita != NULL && pRaiz->esquerda == NULL)
        {
            arvore->raiz = pRaiz->direita;
        }

        if (pRaiz->direita == NULL && pRaiz->esquerda == NULL)
        {
            arvore->raiz = NULL;
        }

        if (pRaiz->direita != NULL && pRaiz->esquerda != NULL)
        {
            int esq = -pfc(info, pRaiz->esquerda->info);
            int dir = pfc(info, pRaiz->direita->info);
            pNohArvore pAux;
            if (esq < dir)
            {
                pAux = pRaiz->esquerda;
                while (pAux->direita != NULL)
                {
                    pAux = pAux->direita;
                }
                pAux->direita = pRaiz->direita;
                arvore->raiz = pRaiz->esquerda;
            }
            else
            {
                pAux = pRaiz->direita;
                while (pAux->esquerda != NULL)
                {
                    pAux = pAux->esquerda;
                }
                pAux->esquerda = pRaiz->esquerda;
                arvore->raiz = pRaiz->direita;
            }

            free(pRaiz);
            return 1;
        }
    }

    excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 1;
}

#endif
