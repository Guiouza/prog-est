#include <stdio.h>
#include <locale.h>

unsigned int rec_sum(unsigned int n)
{
    // Caso base: se n for 0 ou 1, retorna n.
    if (n <= 1) return n;
    // Chamada recursiva: soma o valor atual de n com a soma dos naturais anteriores.
    return rec_sum(n-1) + n;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");
    
    unsigned int number;
    printf("Digite um número naural positivo: ");
    scanf("%u", &number);

    // Soma dos Naturais:
    // S = 1 + 2 + 3 + ... + n

    // ---- Soma dos Naturais Com For ----
    unsigned int soma = number;
    for (unsigned int i = 0; i < number; i++) soma += i;
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    // ---- Soma dos Naturais Com While ----
    unsigned int i = 0;
    soma = number;
    while (i < number) soma += i++;
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    // ---- Soma dos Naturais Com Do While ----
    soma = number;
    i = 0;
    do {
        soma += i++;
    } while (i < number);
    printf("A soma dos %u primeiros naturais é: %u.\n", number, soma);

    // ---- Soma dos Naturais Com Recursão ----
    printf("A soma dos %u primeiros naturais é: %u.\n", number, rec_sum(number));

    return 0;
}