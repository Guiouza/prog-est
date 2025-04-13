#include<stdio.h>
#include<locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    unsigned int number;
    double soma;
    
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);
    
    soma = number;
    for (int i = 1; i < number; i++) {
        soma += i/(number - i + 1.0);
    }
    printf("A soma é: %lf.\n", soma);
    
    int i = 1;
    soma = number;
    while (i < number)
    {
        soma += i/(number - i + 1.0);
        i++;
    }
    printf("A soma é: %lf.\n", soma);
    
    i = 0;
    soma = number;
    do
    {
        soma += i/(number - i + 1.0);
        i++;
    } while (i < number);
    printf("A soma é: %lf.\n", soma);
    
    return 0;
}