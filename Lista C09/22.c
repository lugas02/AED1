#include <stdio.h>

int SomarArrays(int vet1[], int vet2[], int size1, int size2) {
    int vet3[size1];

    if ( size1 != size2 ) {
        return 0;
    }

    printf("Array: ");
    for ( int i = 0; i < size1; i++) {
        *(vet3 + i) = *(vet1 + i) + *(vet2 + i);
        printf("%d ", *(vet3 + i));
    }

    return 1;
}

int main() {
    int vet1[] = {2, 4, 8};
    int vet2[] = {3, 7, 11};

    if ( SomarArrays(vet1, vet2, sizeof(vet1)/sizeof(int), sizeof(vet2)/sizeof(int)) ) {
        printf("\nDeu certo!");
    } else printf("Arrays de tamanhos diferentes!");

    return 0;
}