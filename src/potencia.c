#include <stdio.h>
#include <locale.h>

double rec_pow(double n, int e)
{
    if (e == 0)
        return 1;
    if (e < 0)
        return 1/rec_pow(n, -e);
    return rec_pow(n, e-1)*n;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    double number;
    printf("Digite um número real para a base: ");
    scanf("%lf", &number);
    
    int expoente;
    printf("Digite um número inteiro para o expoente: ");
    scanf("%d", &expoente);
    
    if (expoente == 0 && number == 0)
    {
        printf("(0)^(0) é indefinido.\n");
        return 0;
    }

    printf("(%g)^(%d) = %g.\n", number, expoente, rec_pow(number, expoente));
    return 0;
}