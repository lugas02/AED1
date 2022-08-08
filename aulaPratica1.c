// Lucas Costa Garcia - M1

// Lista 02 - Comandos Condicionais
// 10. Faça um programa que receba a altura e o sexo de uma pessoa e calcule e mostre seu
// peso ideal, utilizando as seguintes fórmulas (onde h corresponde à altura):

// Homens: (72.7 ∗ h) − 58
// Mulheres: (62, 1 ∗ h) − 44, 7

#include <stdio.h>

int main() {
    float h, pesoIdeal;
    char sexo;

    printf("Digite o sexo ('h' para homem e 'm' para mulher): ");
    scanf("%c", &sexo);
    
    printf("Digite a altura: ");
    scanf("%f", &h);

    if ( sexo == 'h' ) {
        pesoIdeal = ( 72.7 * h ) - 58;
        printf("Seu peso ideal: %.2f kg", pesoIdeal);
    } else {
    if ( sexo == 'm' ) {                                 // if desnecessário.
        pesoIdeal = ( 62.1 * h ) - 44.7;
        printf("Seu peso ideal: %.2f kg", pesoIdeal);    // printf repetido.
        }
    }

    return 0;
}