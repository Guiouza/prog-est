#include<stdio.h>
#include<locale.h>


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int number;

    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);

    unsigned int fatorial = 1;
    for (unsigned int i = 2; i <= number; i++)
        fatorial *= i;

    printf("O fatorial de %u é: %u.\n", number, fatorial);

    fatorial = 1;
    unsigned int i = 2;
    while (i <= number)
        fatorial *= i++; // calcula o produto depois adiciona 1 ao i.
    
    printf("O fatorial de %u é: %u.\n", number, fatorial);

    fatorial = i = 1;
    do
    {
        fatorial *= i++;
    } while (i <= number); // calcula o produto depois adiciona 1 ao i.

    printf("O fatorial de %u é: %u.\n", number, fatorial);
    
    return 0;
}
