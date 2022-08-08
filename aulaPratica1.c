// Lucas Costa Garcia
// 2022/1 - 22000297 - M1 - ALGORITMOS E ESTRUTURAS DE DADOS I

// Lista 02 - Comandos Condicionais
// 10. Faça um programa que receba a altura e o sexo de uma pessoa, calcule e mostre seu
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
    } else {
    if ( sexo == 'm' ) {
        pesoIdeal = ( 62.1 * h ) - 44.7;
        }
    }

    printf("Seu peso ideal: %.2f kg", pesoIdeal);

    return 0;
}