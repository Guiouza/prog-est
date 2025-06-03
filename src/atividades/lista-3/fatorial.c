#include <stdio.h>
#include <locale.h>

unsigned int rec_factorial(unsigned int n)
{
    if (n <= 1) return 1;
    return rec_factorial(n-1) * n;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    unsigned int number;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);
    
    // ---- Factorial com For ----
    unsigned int fatorial = 1;
    for (unsigned int i = 2; i <= number; i++) fatorial *= i;
    printf("O fatorial de %u é: %u.\n", number, fatorial);
    
    // ---- Factorial com While ----    
    fatorial = 1;
    unsigned int i = 2;
    // calcula o produto depois adiciona 1 ao i.
    while (i <= number) fatorial *= i++;
    printf("O fatorial de %u é: %u.\n", number, fatorial);

    // ---- Factorial com Do While ----
    fatorial = i = 1;
    // calcula o produto depois adiciona 1 ao i.
    do {
        fatorial *= i++;
    } while (i <= number);
    printf("O fatorial de %u é: %u.\n", number, fatorial);

    // ---- Factorial com Recursão ----
    printf("O fatorial de %u é: %u.\n", number, rec_factorial(number));

    return 0;
}
