#include <stdio.h>

int negativos(float *vet, int N) {
    int contador = 0;
    for (int i = 0; i < N; i++) {
        if ( vet[i] < 0)
            contador++;
    }

    return contador;
}

int main() {
    float vet[] = {-1, -3, 10, 7, 2, -30, -14};

    printf("%d numeros negativos", negativos(vet, sizeof(vet)/sizeof(float)));

    return 0;
}