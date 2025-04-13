#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    int n;
    
    printf("Qual a quantidade de números? ");
    scanf("%d", &n);

    double* vetor_1 = malloc(sizeof(double)*n);
    for (int i = 0; i < n; i++)
    {
        printf("\tNúmero %d: ", i+1);
        scanf("%lf", vetor_1+i);
    }

    double min, max;
    min = max = vetor_1[0];

    for (int i = 1; i < n; i++)
    {
        if (vetor_1[i] > max)
            max = vetor_1[i];
        if (vetor_1[i] < min)
            min = vetor_1[i];
    }

    double dif = max - min;
    if (dif != 0)
    {
        double* vetor_2 = malloc(sizeof(double)*n);
        for (int i = 0; i < n; i++)
        {
            vetor_2[i] = vetor_1[i]/dif;
        }

        printf("\nO novo vetor é: {");
        for (int i = 0; i < n; i++)
        {
            vetor_2[i] = vetor_1[i]/dif;
            printf("%g; ", vetor_2[i]);
        }
        printf("}\n");
    }
    return 0;
}