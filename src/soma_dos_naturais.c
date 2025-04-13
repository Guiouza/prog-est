#include<stdio.h>
#include<locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    unsigned int number;
    printf("Digite um número naural positivo: ");
    scanf("%u", &number);

    // for:
    unsigned int soma = number;
    for (unsigned int i = 0; i < number; i++)
    {
        soma += i;
    }
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    // while:
    unsigned int i = 0;
    soma = number;
    while (i < number)
    {
        soma += i++;
    }
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    // do while:
    soma = number;
    i = 0;
    do
    {
        soma += i++;
    } while (i < number);
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    return 0;
}