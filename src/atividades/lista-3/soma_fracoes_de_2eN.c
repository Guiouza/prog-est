#include <stdio.h>
#include <locale.h>
#include "my_math.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    unsigned int number;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);

    // Soma das frações de 2^n:
    // S = 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^n)

    // > [!NOTA] 
    // > `-n++`: primeiro usa o valor de -n, depois incrementa n++.

    // ---- Soma das frações de 2^n com For ----
    double soma = 1;
    for (int n = 1; n <= number; n++) soma += ipow(2.0, -n);
    printf("A soma é: %lf.\n", soma);

    // ---- Soma das frações de 2^n com While ----
    int n = soma = 1;
    while (n <= number) soma += ipow(2.0, -n++);
    printf("A soma é: %lf.\n", soma);

    // ---- Soma das frações de 2^n com Do While ----
    n = soma = 0;
    do {
        soma += ipow(2.0, -n++);
    } while (n <= number);
    printf("A soma é: %lf.\n", soma);

    return 0;
}