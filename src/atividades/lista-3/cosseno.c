#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    double x;
    printf("Digite um valor de x: ");
    scanf("%lf", &x);

    double cos_x = 1;
    for (int i = 1; i < 100; i++)
    {
        double term = 1;
        for (int j = 1; j <= 2*i; j++)
        {
            term *= x/j;
        }
        if (i % 2 == 0)
            cos_x += term;
        else
            cos_x -= term;
    }

    printf("O valor de cos(%.2lf) é: %.10lf\n", x, cos_x);
    return 0;
}