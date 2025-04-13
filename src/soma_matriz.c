#include<stdio.h>
#include<locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    unsigned int n, m;
    
    printf("Qual o número de linhas da matriz? ");
    scanf("%u", &n);
    printf("Qual o número de colunas da matriz? ");
    scanf("%u", &m);

    printf("\nMatriz 1:\n");
    double** matriz_1 = malloc(n * sizeof(double*));
    for (unsigned int i = 0; i < n; i++)
    {
        matriz_1[i] = malloc(m * sizeof(double));
        for (unsigned int j = 0; j < m; j++)
        {
            printf("\tNúmero %d %d: ", i+1, j+1);
            scanf("%lf", matriz_1[i]+j);
        }
    }
    
    printf("\nMatriz 2:\n");
    double** matriz_2 = malloc(n * sizeof(double*));
    for (unsigned int i = 0; i < n; i++)
    {
        matriz_2[i] = malloc(m * sizeof(double));
        for (unsigned int j = 0; j < m; j++)
        {
            printf("\tNúmero %d %d: ", i+1, j+1);
            scanf("%lf", matriz_2[i]+j);
        }
    }

    printf("\nA matriz da soma é:\n");
    double** matriz_3 = malloc(n * sizeof(double*));
    for (unsigned int i = 0; i < n; i++)
    {
        matriz_3[i] = malloc(m * sizeof(double));
        for (unsigned int j = 0; j < m; j++)
        {
            matriz_3[i][j] = matriz_1[i][j] + matriz_2[i][j];
            printf("%g; ", matriz_3[i][j]);
        }
        printf("\n");
    }
    return 0;
}