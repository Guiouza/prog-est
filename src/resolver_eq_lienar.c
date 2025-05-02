#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double prod_escalar(double* v, double* u, unsigned int dimensao)
{
    double soma = 0;
    for (unsigned int i = 0; i < dimensao; i++)
    {
        soma += v[i]*u[i];
    }
    return soma;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int icognitas;
    printf("Qual o número de icógnitas? ");
    scanf("%u", &icognitas);
    
    double** matriz_A = malloc(sizeof(double*)*icognitas);
    double* matriz_B = malloc(sizeof(double)*icognitas);
    double* matriz_X = malloc(sizeof(double)*icognitas);

    for (unsigned int i = 0; i < icognitas; i++)
    {
        matriz_A[i] = malloc(sizeof(double)*(i+1));
        for (unsigned int j = 0; j < i+1; j++)
        {
            printf("A(%u,%u) = ", i+1, j+1);
            scanf("%lf", matriz_A[i]+j);

            while (i == j && matriz_A[i][j] == 0)
            {
                printf("As icógnitas da diagonal devem ser diferentes de zero.\n", i+1, j+1);
                printf("A(%u,%u) = ", i+1, j+1);
                scanf("%lf", matriz_A[i]+j);
            }
        }
    }
    for (unsigned int i = 0; i < icognitas; i++)
    {
        printf("B(%u) = ", i+1);
        scanf("%lf", matriz_B+i);
    }

    matriz_X[0] = matriz_B[0] / matriz_A[0][0];
    for (unsigned int i = 1; i < icognitas; i++)
    {
        matriz_X[i] = (matriz_B[i] - prod_escalar(matriz_A[i], matriz_X, i))/matriz_A[i][i];
    }

    printf("\nMatriz A:\n");
    for (unsigned int i = 0; i < icognitas; i++)
    {
        for (unsigned int j = 0; j < i+1; j++)
        {
            printf("(%g) ", matriz_A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (unsigned int i = 0; i < icognitas; i++)
    {
        printf("(%g) ", matriz_B[i]);
        printf("\n");
    }

    printf("\nMatriz X:\n");
    for (unsigned int i = 0; i < icognitas; i++)
    {
        printf("(%g) ", matriz_X[i]);
        printf("\n");
    }

    free(matriz_B);
    free(matriz_X);
    for (unsigned int i = 0; i < icognitas; i++)
    {
        free(matriz_A[i]);
    }
    free(matriz_A);
    return 0;    
}