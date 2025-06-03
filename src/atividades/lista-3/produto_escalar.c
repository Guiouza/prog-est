#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define DOUBLE_SIZE sizeof( double )
#define MAX_SIZE 1024 // Tamanho máximo de cada vetor (1024 bytes)

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    size_t n;
    printf("Qual a dimenção dos vetores? ");
    scanf("%zu", &n);

    if (n == 0)
    {
        printf("Os vetores devem ter pelo menos uma coordenada.\n");
        return 0;
    }

    if (n *DOUBLE_SIZE >= MAX_SIZE)
    {
        printf("O vetor é muito grande (%zu bytes)! O tamanho máximo é %zu bytes.\n",
            n * DOUBLE_SIZE,
            MAX_SIZE
        );
        printf("A conta para o tamanho da vetor é:\n");
        printf("Tamanho da vetor = n * %zu\n", DOUBLE_SIZE);
        return 0;
    }

    printf("\nVetor 1:\n");
    double* vetor_1 = malloc(n * DOUBLE_SIZE);
    for (size_t i = 0; i < n; i++)
    {
        printf("\tNúmero %zu: ", i+1);
        scanf("%lf", vetor_1+i);
    }
    
    printf("\nVetor 2:\n");
    double* vetor_2 = malloc(n * DOUBLE_SIZE);
    for (size_t i = 0; i < n; i++)
    {
        printf("\tNúmero %zu: ", i+1);
        scanf("%lf", vetor_2+i);
    }

    double produto_escalar = 0;
    for (size_t i = 0; i < n; i++)
    {
        produto_escalar += vetor_1[i] * vetor_2[i];
    }
    
    printf("\nO produto escalar dos vetores é: %g\n", produto_escalar);

    free(vetor_1);
    free(vetor_2);

    return 0;
}