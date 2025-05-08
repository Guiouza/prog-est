#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PTR_SIZE sizeof(int*)
#define INT_SIZE sizeof(int)

// Limita o espaço máximo ocupado pelas matrizes
#define TAMANHO_MAXIMO 32 // A maior matriz permitida ocupa: 4.352 bytes (~4 KB)

int main(int argc, char const **argv)
{
    setlocale(LC_ALL, ".utf8");

    unsigned int m, n, p;    
    printf("Qual o número de linhas da matriz A (m)? ");
    scanf("%u", &m);
    printf("Qual o número de colunas da matriz A (n)? ");
    scanf("%u", &n);
    printf("Qual o número de colunas da matriz B (p)? ");
    scanf("%u", &p);

    // Limita o tamanho máximo das matrizes
    if (TAMANHO_MAXIMO < m) { m = TAMANHO_MAXIMO; }
    if (TAMANHO_MAXIMO < n) { n = TAMANHO_MAXIMO; }
    if (TAMANHO_MAXIMO < p) { p = TAMANHO_MAXIMO; }

    // Inicializa as linhas das matrizes A e B
    int** matriz_A = malloc(m * PTR_SIZE);
    int** matriz_B = malloc(n * PTR_SIZE);
    int** matriz_C = malloc(m * PTR_SIZE);

    printf("\nMatriz A:\n");
    for (unsigned int i = 0; i < m; i++)
    {
        // Inicializa as colunas das matrizes A e C
        matriz_A[i] = malloc(n * INT_SIZE);
        matriz_C[i] = malloc(p * INT_SIZE);
        
        // Popula a matriz A
        for (unsigned int j = 0; j < n; j++)
        {
            printf("\tValor de A(%d, %d): ", i+1, j+1);
            scanf("%d", matriz_A[i]+j);
        }
    }
    
    printf("\nMatriz B:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        matriz_B[i] = malloc(p * INT_SIZE);

        // Popula a matriz B
        for (unsigned int j = 0; j < p; j++)
        {
            printf("\tValor de B(%d, %d): ", i+1, j+1);
            scanf("%d", matriz_B[i]+j);
        }
    }

    // Calcula o produto C = A*B
    for (unsigned int lA = 0; lA < m; lA++) { // para cada linha de A
        for (unsigned int cB = 0; cB < p; cB++) { // para cara coluna de B
            int soma = 0;
            // para cada coluna de A e linha de B
            for (unsigned int i = 0; i < n; i++)
            {
                // Produto escalar entre a linha e a coluna de B
                soma += matriz_A[lA][i]*matriz_B[i][cB];
            }
            matriz_C[lA][cB] = soma;
        }
    }

    printf("\nMatriz A:\n");
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            printf("(%d) ", matriz_A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < p; j++)
        {
            printf("(%d) ", matriz_B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz C = A*B:\n");
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < p; j++)
        {
            printf("(%d) ", matriz_C[i][j]);
        }
        printf("\n");
    }

    // Libera a memória
    for (unsigned int i = 0; i < m; i++) {
        free(matriz_A[i]);
        free(matriz_C[i]);
    }
    for (unsigned int i = 0; i < n; i++) { free(matriz_B[i]); }
    free(matriz_A);
    free(matriz_B);
    free(matriz_C);

    return 0;
}

