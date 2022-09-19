#include <stdio.h>

int main() {
    int vet[] = {1, 2, 3, 4, 5}; // vet é o endereço de memória do primeiro elemento do array
    int *pVet = vet;

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++) {
        printf("%d ", *(pVet + i));
    }

    return 0;
}