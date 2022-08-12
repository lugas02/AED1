//Lista C09 - Exercício 6

#include <stdio.h>
#include <stdlib.h>

void troca_Inteiro(int *ptrX, int *ptrY) {
    int temp = *ptrX;

    *ptrX = *ptrX * 2;
    *ptrY = *ptrY * 2;

    printf("\nSoma do dobro de a e b: %d\n\n", (*ptrX + *ptrY));
}

int main()
{
    int a, b;

    printf("Digite a: ");
    scanf("%d", &a);
    printf("Digite b: ");
    scanf("%d", &b);

    troca_Inteiro(&a, &b);

    printf("a: %d\nb: %d", a, b);

    return 0;
}
