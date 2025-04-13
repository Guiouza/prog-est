#include<stdio.h>
#include<locale.h>

unsigned int fatorial(unsigned int numero) {
    unsigned int fatorial = 1;
    for (int i = 1; i <= numero; i++)
    {
        fatorial *= i;
    }
    return fatorial;
}

unsigned int combinacao_nk(unsigned int n, unsigned int k) {
    return fatorial(n)/(fatorial(n-k)*fatorial(k));;
}

double pow_nat(double x, unsigned int n) {
    double prod = 1;
    for (unsigned int i = 1; i <= n; i++)
    {
        prod *= x;
    }
    return prod;
}

double binomio(double a, double b, unsigned int n) {
    double soma = 0;
    for (int i = 0; i <= n; i++)
    {
        soma += combinacao_nk(n, i)*pow_nat(a, i)*pow_nat(b, n-i);
    }
    return soma;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    double a, b;
    unsigned int n;

    printf("Digite um número real (a): ");
    scanf("%lf", &a);

    printf("Digite um número real (b): ");
    scanf("%lf", &b);
    
    printf("Digite um número natural (n): ");
    scanf("%u", &n);
    
    printf("(%g + %g)^%u é %g.\n", a, b, n, binomio(a, b, n));
    printf("(%g - %g)^%u é %g.\n", a, b, n, binomio(a, -b, n));
    return 0;
}