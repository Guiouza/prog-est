#include <stdio.h>
#include <locale.h>
#include <string.h>


unsigned int isqrt(unsigned int n) {
    double x = 0;
    x = (n + 1)*0.5;
    x = x - (x*x - n)/(2.0*x);
    x = x - (x*x - n)/(2.0*x);

    return (unsigned int) x + 1;
}

int e_primo(unsigned int x) {
    if (x <= 1)
        return 0;

    int primo = 1;
    for (int i = 2; i < isqrt(x); i += 2) {
        primo &= x % i != 0;
        if (i == 2) i--;
    }

    return primo;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &numero);
    
    if (e_primo(numero)) {
        printf("%u é primo.\n", numero);
        return 0;
    }
    printf("%u não é primo.\n", numero);
    return 0;
}