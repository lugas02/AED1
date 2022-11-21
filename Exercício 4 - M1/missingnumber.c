#include <stdio.h>

int MissingNumber(int *array, int n) {
    int missing = n;
    
    for( int i = 0; i < n; i++ )
        missing += i - array[i];

    return missing;
}

void Print(int *array, int n) {
    for( int i = 0; i < n; i++ )
        printf("%d ", array[i]);
}

int main() {
    int array[9] = {9, 2, 8, 7, 1, 0, 4, 6, 3};
    int n = sizeof(array) / sizeof(array[0]);

    Print(array, n);
    printf("\nNumero faltante: %d\n", MissingNumber(array, n));

    return 0;
}
