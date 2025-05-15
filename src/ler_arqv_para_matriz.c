#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    FILE* file = fopen("test/ler_arqv_para_matriz/matriz.txt", "r");
    unsigned int m, n;
    fscanf(file, "%u %u", &m, &n);

    double** matriz = malloc(sizeof(double*)*m);

    for (int i = 0; i < m; i++)
    {
        matriz[i] = malloc(sizeof(double)*n);

        for (int j = 0; j < n; j++) {
            fscanf(file, "%lf", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            printf("(%g) ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}