#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t {
    int reg;
    struct nodo_t *pEsq;
    struct nodo_t *pDir;
} nodo_t;

nodo_t *arvore = NULL;

/////////////////////////
 // Retorna um novo nodo.
/////////////////////////
nodo_t *Push(int reg) {
    nodo_t *novoNodo;
    novoNodo = (nodo_t *) malloc(sizeof(nodo_t));

    novoNodo->reg = reg;
    novoNodo->pEsq = NULL;
    novoNodo->pDir = NULL;

    return novoNodo;
}

/////////////////////////////////
 // Insere o novo nodo na arvore.
/////////////////////////////////
void Inserir(int reg, nodo_t **raiz) {
    nodo_t *novoNodo;
    
    if( *raiz == NULL ) {
        novoNodo = Push(reg);
        *raiz = novoNodo;
        return;
    }

    if( reg < (*raiz)->reg ) {
        Inserir(reg, &(*raiz)->pEsq);
        return;
    }

    if( reg > (*raiz)->reg ) {
        Inserir(reg, &(*raiz)->pDir);
        return;
    }

    // if( reg == (*raiz)->reg )
    printf("Nodo ja existe.\n");
}

// Para saber se a ordem dos elementos está certa
void preOrdem(nodo_t *raiz) {
    if( raiz != NULL ) {
        printf("%d ", raiz->reg);
        preOrdem(raiz->pEsq);
        preOrdem(raiz->pDir);
    }
}

////////////////////////////////////////////////////////////////////////////
 // Calcula a altura da subárvore da esquerda e da direita da variável raíz.
////////////////////////////////////////////////////////////////////////////
int Altura(nodo_t *raiz) {
    int iEsq, iDir;

    if( raiz == NULL ) {
        return 0;
    }

    iEsq = Altura(raiz->pEsq);
    iDir = Altura(raiz->pDir);

    if( iEsq > iDir ) {
        return iEsq + 1;
    } else return iDir + 1;
}

//////////////////////////////////////////////////////////////////////////
 // Calcula o fator de balanceamento da subárvore recebida como argumento.
//////////////////////////////////////////////////////////////////////////
int FB(nodo_t *raiz) {
    if( raiz == NULL ) {
        return 0;
    }

    return Altura(raiz->pEsq) - Altura(raiz->pDir);
}

/////////////////////////////////////////////////////////////////
 // Checa se a árvore é AVL. Calcula o FB de todas as subárvores.
/////////////////////////////////////////////////////////////////
int ChecarAVL(nodo_t *raiz) {
    int fb;

    if( raiz == NULL ) {
        return 1;
    }

    if( !ChecarAVL(raiz->pEsq) ) {
        return 0;
    }

    if( !ChecarAVL(raiz->pDir) ) {
        return 0;
    }

    fb = FB(raiz);
    if( fb < -1 || fb > 1 ) {
        return 0;
    } else return 1;
}

int main()
{
    int reg;
    char op = '\0';
    
    printf("Digite 'i' para inserir um numero na arvore, e x para sair do programa.\n");

    while( op != 'x' ) {
        scanf(" %c", &op);
        switch(op) {
            case 'i':
            scanf("%d", &reg);
            Inserir(reg, &arvore);
            break;

            case 'x':
            break;

            default:
            break;
        }
    }
    preOrdem(arvore);
    printf("\n");

    if( ChecarAVL(arvore) ) {
        printf("Eh avl.\n");
    } else printf("Nao eh avl.\n");

    return 0;
}
