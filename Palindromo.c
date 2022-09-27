// Lucas Costa Garcia
// 2022/1 - 22000297 - M1 - ALGORITMOS E ESTRUTURAS DE DADOS I
// Exercício 2 - M1
// 

/*
Fazer um programa que testa se uma sequência de caracteres fornecida pelo usuário é um palíndromo, 
ou seja, é uma palavra cuja primeira metade é simétrica à segunda metade.

O usuário digita uma letra e tecla enter até que ele digite x e enter para terminar a sequência.

Implemente a função POP e PUSH de pilha e resolva o problema com elas. No vídeo demonstre pelo menos 4 casos de sim e 4 casos de não.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *sequencia;
    char *topo;
    char *base;
    int tamanho;
} pilha_t;

pilha_t *pilha = NULL;


/*
==========================
Reset
Inicia a variável "pilha".
==========================
*/
void Reset() {
    pilha = (pilha_t *) malloc((sizeof(char *) * 3) + sizeof(int));
    
    pilha->sequencia = NULL;
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->tamanho = 0;
}

/*
======================================
Push
Insere caracteres em pilha->sequencia.
======================================
*/
void Push(char letra) {
    if ( pilha->sequencia == NULL ) {
        pilha->sequencia = (char *) malloc(sizeof(char));
        if( pilha->sequencia == NULL) {
            printf("Erro.");
            return;
        }
        *(pilha->sequencia) = letra;
        
        pilha->topo = pilha->sequencia;
        pilha->base = pilha->sequencia;
        pilha->tamanho++;

        return;
    }
    
    pilha->tamanho++;
    pilha->sequencia = (char *) realloc(pilha->sequencia, sizeof(char) * (pilha->tamanho));
    pilha->topo = pilha->sequencia;

    for( int i = 0; i < (pilha->tamanho - 1); i++) {
        pilha->topo += sizeof(char);
    }
    *(pilha->topo) = letra;

    return;
}

/*
=============================================================================================
Palindromo
Checa se "pilha->sequencia" é um palindrimo. 
Metade da sequência, começando pelo topo, é salva em outra pilha e seus topos são comparados.
=============================================================================================
*/
int Palindromo() {
    int par = pilha->tamanho;

    pilha_t *novaPilha;
    novaPilha = (pilha_t *) malloc(sizeof(pilha_t));
    if ( novaPilha == NULL ) {
        printf("Erro.");
        return 1;
    }

    novaPilha->sequencia = (char *) malloc(sizeof(char) * (pilha->tamanho/2));
    if ( novaPilha->sequencia == NULL ) {
        printf("Erro.");
        free(novaPilha);
        return 1;
    }

    novaPilha->topo = novaPilha->sequencia;
    novaPilha->base = novaPilha->sequencia;
    novaPilha->tamanho =  (pilha->tamanho)/2;

    for( int i = 0; i <= (pilha->tamanho)/2; i++ ){
        *(novaPilha->topo) = *(pilha->topo);
        
        pilha->tamanho--;
        pilha->topo -= sizeof(char);
        pilha->sequencia = (char *) realloc(pilha->sequencia, sizeof(char) * pilha->tamanho);
        
        novaPilha->topo += sizeof(char);
    }
    novaPilha->topo -= sizeof(char);

    if( par%2 != 0 ) {
        pilha->tamanho--;
        pilha->topo -= sizeof(char);
        pilha->sequencia = (char *) realloc(pilha->sequencia, sizeof(char) * pilha->tamanho);
    }

    while( *(pilha->topo) == *(novaPilha->topo) && pilha->tamanho > 0 ) {
        pilha->topo -= sizeof(char);
        novaPilha->topo -= sizeof(char);

        pilha->tamanho--;
        novaPilha->tamanho--;

        pilha->sequencia = (char *) realloc(pilha->sequencia, sizeof(char) * pilha->tamanho);
        novaPilha->sequencia = (char *) realloc(novaPilha->sequencia, sizeof(char) * novaPilha->tamanho);
    }

    if( pilha->tamanho == 0 ) {
        free(novaPilha->sequencia);
        free(novaPilha);
        return 0;
    } else {
        free(novaPilha->sequencia);
        free(novaPilha);
        return 1;
    }


}

int main() {
    char letra;
    Reset();

    printf("Digite uma letra(x para sair): ");
    while ( letra != 'x' ) {
        scanf(" %c", &letra);

        if ( letra != 'x') {
            Push(letra);
        }
    }

    if ( !Palindromo() ) {
        printf("Eh um palindromo.");
    } else printf("Nao eh um palindromo.");

    free(pilha->sequencia);
    free(pilha);
    return 0;
}