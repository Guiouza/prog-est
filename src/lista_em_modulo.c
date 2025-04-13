#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    int n;
    
    printf("Qual a quantidade de números? ");
    scanf("%d", &n);

    double* lista = malloc(sizeof(double)*n);
    double holder;
    for (int i = 0; i < n; i++)
    {
        printf("\tNúmero %d: ", i+1);
        scanf("%lf", &holder);

        if (holder < 0)
        {
            lista[i] = -holder;
            continue;
        }
        lista[i] = holder;
    }

    double max = lista[0];
    for (int i = 1; i < n; i++)
    {
        if (lista[i] > max)
        {
            max = lista[i];
        }
    }

    printf("O maior número em módulo é %g", max);
    return 0;
}