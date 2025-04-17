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
    unsigned int combinacao = fatorial(n)/(fatorial(n-k)*fatorial(k));
    return combinacao;
}

double rec_combinacao_nk(unsigned int n, unsigned int k) {
    if (k == 0 || n <= k)
        return 1;
    return rec_combinacao_nk(n-1, k-1) * n/(double)k;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int n;
    unsigned int k;

    printf("Digite um número natural: ");
    scanf("%u", &n);

    printf("Digite um número natural: ");
    scanf("%u", &k);

    unsigned int combinacao = combinacao_nk(n, k);

    printf("A combinacao de %u a %u é %u.\n", n, k, combinacao);

    printf("A combinacao de %u a %u é %g.\n", n, k, rec_combinacao_nk(n, k));
    return 0;
}