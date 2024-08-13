#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include <stdio.h>
/* --------------------------*/
pNohArvore minimo(pNohArvore noh) {
    while (noh->esquerda != NULL) {
        noh = noh->esquerda;
    }
    return noh;
}

pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc, int *flag) {
    if (raiz == NULL) return raiz;

    int comp = fc(info, raiz->info);

    if (comp < 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc, flag);
    } else if (comp > 0) {
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc, flag);
    } else {
        *flag = 1;  // Marca que o nó foi encontrado e removido
        // Caso 1: Nó com apenas um filho ou nenhum
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            pNohArvore temp = (raiz->esquerda != NULL) ? raiz->esquerda : raiz->direita;
            
            if (temp == NULL) {
                // Nenhum filho, nó é folha
                temp = raiz;
                raiz = NULL;
            } else {
                // Um filho, substitui o nó removido
                *raiz = *temp;
            }
            free(temp);
        } else {
            // Caso 2: Nó com dois filhos
            pNohArvore temp = minimo(raiz->direita);

            // Copiar os dados do sucessor para o nó corrente
            raiz->info = temp->info;

            // Remover o sucessor
            raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, fc, flag);
        }
    }

    // Se a árvore tinha apenas um nó
    if (raiz == NULL) return raiz;

    // Corrigir as propriedades da árvore Rubro-Negra
    return corrigirRemocaoRubroNegra(raiz);
}

int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore->raiz == NULL) return 0;

    int flag = 0;
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc, &flag);

    // Após a exclusão, corrija as propriedades da árvore Rubro-Negra
    if (arvore->raiz != NULL) {
        arvore->raiz->cor = BLACK;
    }

    return flag;  // Retorna 1 se a exclusão foi bem-sucedida, 0 caso contrário
}

pNohArvore corrigirRemocaoRubroNegra(pNohArvore raiz) {
    if (raiz->esquerda != NULL && raiz->esquerda->cor == RED) {
        raiz = rotacaoDireita(raiz);
        raiz->cor = BLACK;
        raiz->direita->cor = RED;
    } else if (raiz->direita != NULL && raiz->direita->cor == RED) {
        raiz = rotacaoEsquerda(raiz);
        raiz->cor = BLACK;
        raiz->esquerda->cor = RED;
    }

    return raiz;
}

#endif
