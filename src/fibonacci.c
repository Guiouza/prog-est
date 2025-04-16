#include <stdio.h>
#include <locale.h>

unsigned int fibonacci(unsigned int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int number;
    printf("Digite um número natural: ");
    scanf("%u", &number);
    
    printf("O %u-ésimo número de Fibonacci é %d.\n", number, fibonacci(number));
    return 0;
}