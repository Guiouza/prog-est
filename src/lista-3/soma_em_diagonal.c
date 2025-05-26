#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int number;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);

    // Soma em Diagonal:
    // S = 1/n + 2/(n-1) + 3/(n-2) + ... + (n-1)/2 + n

    // ---- Soma em Diagonal Com For ----
    double soma = number;
    for (int i = 1; i < number; i++) {
        soma += i/(number - i + 1.0);
    }
    printf("A soma é: %lf.\n", soma);

    // ---- Soma em Diagonal Com While ----
    int i = 1;
    soma = number;
    while (i < number)
    {
        soma += i/(number - i + 1.0);
        i++;
    }
    printf("A soma é: %lf.\n", soma);

    // ---- Soma em Diagonal Com Do While ----
    i = 0;
    soma = number;
    do {
        soma += i/(number - i + 1.0);
        i++;
    } while (i < number);
    printf("A soma é: %lf.\n", soma);

    return 0;
}