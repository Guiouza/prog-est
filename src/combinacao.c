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
    return 0;
}