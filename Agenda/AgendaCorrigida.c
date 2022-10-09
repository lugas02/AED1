/*
Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
    1. Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
        1.1. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
        1.2. Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
    2. Não pode usar struct em todo o programa.
    3. Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
    4. Implementar a base de dados da agenda usando lista duplamente ligada
        4.1. Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

/*
Para corrigir:
    1. Buffer overflow (scanf);
    2. Warnings (Type-casting); [RESOLVIDO]
    3. Checar se malloc retorna NULL;
    4. pLast no pList.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer = NULL;
void *pList = NULL;


/*
========================================================================
Push
    Aloca memória para um nodo e o usuário escreve diretamente nela.
========================================================================
*/
void *Push() {
    void *newNode;

    newNode = (void *) malloc( (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *) * 2) );
    if ( newNode == NULL )
        return newNode;

    printf("Digite o nome: ");
    scanf("%s", (char *)newNode);

    printf("Digite a idade: ");
    scanf("%i", (int *)( newNode + (sizeof(char) * 11) ));

    printf("Digite o telefone: ");
    scanf("%i", (int *)( newNode + (sizeof(char) * 11) + sizeof(int) ));

    *(int **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) ) = NULL;
    *(int **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void *) ) = NULL;

    return newNode;
}


/*
===================================================
InsertList
    Insere o nodo na lista em ordem alfabética.
===================================================
*/
void InsertList() {
    void *newNode = Push();

    if ( !pList ) {    // Chega se a lista está vazia.
        pList = newNode;
        return;
    }

    *(void **)pBuffer = /*(void *)*/pList;    // pBuffer recebe o endereço de memória do primeiro nodo.

    while ( *(void **)pBuffer && (strcmp(*(void **)pBuffer, (char *)newNode) < 1) ) {    // Checa se o endereço de memória contido em pBuffer é nulo e se a string do nodo atual é menor que a string do novo nodo.
        *(void **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) ) = *(void **)pBuffer;    // pPrev do novo nodo guarda o endereço de memória do nodo atual.
        *(void **)pBuffer = *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *)) );    // pBuffer guarda o ponteiro do nodo seguinte.
    }

    if ( *(void **)pBuffer == (void **)pList ) {    // Checa se deve inserir o novo no início da fila
        pList = newNode;
        *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) ) = newNode;    // pPrev do nodo atual aponta para o novo nodo  
        *(void **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *)) ) = *(void **)pBuffer;    // pNext do novo nodo aponta para o nodo atual

        return;
    }

    if ( !(*(void **)pBuffer) ) {    // Checa se deve inserir no último lugar da fila
        *(void **)pBuffer = *(void **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) );    // pBuffer recebe o ponteiro para o último nodo
        *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *)) ) = /*(void *)*/newNode;   // pNext do último nodo da lista aponta para o novo nodo

        return;
    }

    // Insere no meio da fila
    *(void **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void *) ) = *(void **)pBuffer;    // pNext do nodo nodo aponta para o nodo atual
    *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) ) = /*(void *)*/newNode;    // pPrev do nodo atual aponta para o novo nodo
    
    *(void **)pBuffer = *(void **)( newNode + (sizeof(char) * 11) + (sizeof(int) * 2) );    // pBuffer receve o ponteiro pPrev do novo nodo

    *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void *) ) = /*(void *)*/newNode;    // O pNext do ponteiro antecessor ao novo nodo aponta para o novo nodo

    return;
}


/*
=======================================
Pop
    Retira o primeiro nodo da lista.
=======================================
*/
void Pop() {
    if ( !pList ) {
        printf("Agenda vazia!\n");
        return;
    }

    *(void **)pBuffer = /*(void *)*/pList;
    
    if ( *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *)) ) == NULL ) {
        free(pList);
        pList = NULL;

        return;
    }

    *(void **)pBuffer = *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + (sizeof(void *)) );
    *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) ) = NULL;
    
    free(pList);
    pList = *(void **)pBuffer;

    return;
}


/*
=======================================
Clear
    Deleta todos os nodos da lista.
=======================================
*/
void Clear() {
    if ( !pList ) {
        printf("Agenda vazia!\n");
        return;
    }

    while ( pList ) {
        Pop();
    }

    return;
}


/*
======================================================
Search
    Procura um nodo pela string dada pelo usuário.
======================================================
*/
void Search() {
    if ( !pList ) {
        printf("Agenda vazia!\n");
        return;
    }

    printf("Digite um nome para procurar: ");
    scanf("%s", (char *)( pBuffer + sizeof(void *) + sizeof(char) ));

    *(void **)pBuffer = /*(void *)*/pList;

    while ( *(void **)pBuffer && strcmp(pBuffer + sizeof(void *) + sizeof(char), *(void **)pBuffer) != 0 ) {
        *(void **)pBuffer = *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void *) );
    }

    if ( !(*(void **)pBuffer) ) {
        printf("Nao achamos!\n");
        return;
    }

    printf("%s\n", *(char **)pBuffer);
    printf("%i\n", *(int *)( *(int *)pBuffer + (sizeof(char) * 11) ));
    printf("%i\n", *(int *)( *(int *)pBuffer + (sizeof(char) * 11) + sizeof(int) ));

    return;
}


/*
=========================================
PrintAll
    Imprime todos os nodos da lista.
=========================================
*/
void PrintAll() {
    if ( !pList ) {
        printf("Agenda vazia!\n");
        return;
    }

    *(void **)pBuffer = /*(void *)*/pList;

    printf("//---------------------------------//");
    while ( *(void **)pBuffer ) {
        printf("\n%s\n", *(char **)pBuffer);
        printf("%i\n", *(int *)( *(void **)pBuffer + (sizeof(char) * 11) ));
        printf("%i\n", *(int *)( *(void **)pBuffer + (sizeof(char) * 11) + sizeof(int) ));

        *(void **)pBuffer = *(void **)( *(void **)pBuffer + (sizeof(char) * 11) + (sizeof(int) * 2) + sizeof(void *) );
    }
    printf("//---------------------------------//\n");

    return;
}


int main() {
    pBuffer = (void *) malloc( sizeof(void *) + (sizeof(char) * 12) );  // Memória para guardar um endereço de um nodo, um char para o menu e 11 chars para a string
    *(char *)( pBuffer + sizeof(void *) ) = 'a';  // Precaução
    
    printf("Menu: ");
    printf("'n' para nova pessoa, 'p' para retirar um, 'i' para imprimir, 's' para procurar por nome, 'c' para limpar a agenda, 'x' para sair. \n");
    
    while ( *(char *)(pBuffer + sizeof(void *)) != 'x' ) {
        scanf("%c", (char *)(pBuffer + sizeof(void *)));
        switch( *(char *)(pBuffer + sizeof(void *)) ) {
            case 'n':
            InsertList();
            break;

            case 'p':
            Pop();
            break;

            case 'i':
            PrintAll();
            break;

            case 's':
            Search();
            break;

            case 'c':
            Clear();
            break;

            case 'x':
            Clear();
            break;
        }
    }

    free(pBuffer);
    return 0;
}
