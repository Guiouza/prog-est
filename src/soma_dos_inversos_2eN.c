#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    unsigned int number;
    double soma = 1;

    printf("Digite um número inteiro positivo: ");
    scanf("%u", &number);

    for (int i = 1; i <= number; i++)
    {
        soma += pow(2.0, -i);
    }
    printf("A soma é: %lf.\n", soma);

    int i = soma = 1;
    while (i <= number)
    {
        soma += pow(2.0, -i++);
    }
    printf("A soma é: %lf.\n", soma);
    
    i = soma = 0;
    do {
        soma += pow(2.0, -i++);
    }
    while (i <= number);
    printf("A soma é: %lf.\n", soma);
    return 0;
}