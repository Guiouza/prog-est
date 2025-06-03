#include <locale.h>
#include <stdio.h>

int mdc(int a, int b) {
    unsigned int resto = a % b;
    if (resto == 0) return b;
    mdc(b, resto);
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    unsigned int a, b;
    printf("Digite dois valores inteiros positivos.\na: ");
    scanf("%u", &a);
    printf("b: ");
    scanf("%u", &b);

    printf("MDC(a, b) = MDC(%u, %u) = %u.\n", a, b, mdc(a, b));
    return 0;
}
