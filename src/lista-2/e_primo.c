#define SQRT_ERROR 0.1 // sqrt para com precisão em 0.1
// Isso porque precisamos apenas do inteiro mais próximo da raiz
#include "my_math.h"

#include <stdio.h>
#include <locale.h>

int e_primo(unsigned int x) {
    // 0 e 1 não são primos
    if (x <= 1) return 0;

    unsigned int sqrt_x = (unsigned int) sqrt(x) + 1;
    // Somamos 1 para garantir que a raiz seja arredondada para cima
    // Isso é necessário para evitar por exemplo sqrt(4) = 1.9 => sqrt_x = 1
    // e se sqrt_x = 1, não conseguimos fazer o loop.

    for (int i = 2; i <= sqrt; i += 2)
    {
        // Se x for divisível por i, não é primo
        if (x % i != 0) return 0;

        // Passa a ser impar
        // se i for 1, i+=2 para não repetir os pares
        if (i == 2) i--;
    }

    // Se não for divisível por nenhum número entre 2 e sqrt(x), é primo
    return 1;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    unsigned int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &numero);
    
    if (e_primo(numero))
    {
        printf("%u é primo.\n", numero);
        return 0;
    }
    printf("%u não é primo.\n", numero);
    return 0;
}