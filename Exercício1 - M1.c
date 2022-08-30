#include <stdio.h>
#include <stdlib.h>

void *pBuffer = NULL; // O buffer
char *pTipos = NULL; // Armazena os tipos de dados

/*
=====================================================
InserirNum

  Inserir um número int, float ou double no buffer.
=====================================================
*/
void InserirNum(double num, int tamanho) {
    int tamBytes = 0;  // Total de bytes do buffer (exceto o tamanho do último número)

    // Conta quantos bytes tem o buffer(exceto o tamanho do último número) e armazena na variável tamBytes
    for ( int i = 0; i < tamanho; i++ ) {
        switch(pTipos[i]) {
            case 'i':
            tamBytes += sizeof(int);
            break;

            case 'f':
            tamBytes += sizeof(float);
            break;

            case 'd':
            tamBytes += sizeof(double);
            break;
        }
    }

    // Realoca memória para o novo número 
    switch(pTipos[tamanho]) {
// ---- CASO FOR UM INT ---- //
        case 'i':
        pBuffer = (int *)realloc(pBuffer, sizeof(int));
        
        if ( pBuffer == NULL ) {
            printf("Erro na alocação!!");
        }
        else { *(int *)(pBuffer + tamBytes) = (int)num; }
        break;

// ---- CASO FOR UM FLOAT ---- //
        case 'f':
        pBuffer = (float *)realloc(pBuffer, sizeof(float));
        
        if ( pBuffer == NULL ) {
            printf("Erro na alocação!!");
        }
        else { *(float *)(pBuffer + tamBytes) = (float)num; }
        break;

// ---- CASO FOR UM DOUBLE ---- //
        case 'd':
        pBuffer = (double *)realloc(pBuffer, sizeof(double));
        
        if ( pBuffer == NULL ) {
            printf("Erro na alocação!!");
        }
        else { *(double *)(pBuffer + tamBytes) = (double)num; }
        break;
    }
}


void Imprimir(int tamanho) {
    int tamBytes = 0;

    printf("Todos os numeros: | ");
    for ( int i = 0; i < tamanho; i++ ) {
        switch(pTipos[i]) {
            case 'i':
            printf("%d | ", *(int *)(pBuffer + tamBytes));
            tamBytes += sizeof(int);
            break;

            case 'f':
            printf("%f | ", *(float *)(pBuffer + tamBytes));
            tamBytes += sizeof(float);
            break;

            case 'd':
            printf("%lf | ", *(double *)(pBuffer + tamBytes));
            tamBytes += sizeof(double);
            break;
        }
    }

    tamBytes = 0;

    printf("\nTodos os inteiros: | ");
    for ( int i = 0; i < tamanho; i++ ) {
        switch(pTipos[i]) {
            case 'i':
            printf("%d | ", *(int *)(pBuffer + tamBytes));
            tamBytes += sizeof(int);
            break;

            case 'f':
            tamBytes += sizeof(float);
            break;

            case 'd':
            tamBytes += sizeof(double);
            break;
        }
    }

    tamBytes = 0;

    printf("\nTodos os floats: | ");
    for ( int i = 0; i < tamanho; i++ ) {
        switch(pTipos[i]) {
            case 'i':
            tamBytes += sizeof(int);
            break;

            case 'f':
            printf("%f | ", *(float *)(pBuffer + tamBytes));
            tamBytes += sizeof(float);
            break;

            case 'd':
            tamBytes += sizeof(double);
            break;
        }
    }

    tamBytes = 0;

    printf("\nTodos os doubles: | ");
    for ( int i = 0; i < tamanho; i++ ) {
        switch(pTipos[i]) {
            case 'i':
            tamBytes += sizeof(int);
            break;

            case 'f':
            tamBytes += sizeof(float);
            break;

            case 'd':
            printf("%lf | ", *(double *)(pBuffer + tamBytes));
            tamBytes += sizeof(double);
            break;
        }
    }
}


int main() {
    int tamanho = 0, flag = 0; // "tamanho" conta quantos números a sequência tem
    double num; // Onde iremos escrever os números
    char tipo; // Tipo de dado (i[nt], f[loat] ou d[ouble]) é armazenado no ponteiro char "pTipos"

    while( flag == 0 ) {
        printf("Escreva um tipo de dado('i' para int, 'f' para float e 'd' para double) e depois um numero, ou qualquer outra coisa para sair: ");
        scanf(" %c", &tipo);  // Não funciona sem o espaço no scanf  

        pTipos = (char *)realloc(pTipos, sizeof(char));
                
        if ( pTipos == NULL ) {
            printf("Erro na alocação!!");
            free(pBuffer);
            return 1;
        } else pTipos[tamanho] = tipo;

        switch(tipo) {
            case 'i':
            scanf("%lf", &num);
            InserirNum(num, tamanho);
            tamanho++;
            break;

            case 'f':
            scanf("%lf", &num);
            InserirNum(num, tamanho);
            tamanho++;
            break;

            case 'd':
            scanf("%lf", &num);
            InserirNum(num, tamanho);
            tamanho++;
            break;

            default:
            Imprimir(tamanho);
            flag = 1;
            break;
        }
    }

    free(pTipos);
    free(pBuffer);
    return 0;
}