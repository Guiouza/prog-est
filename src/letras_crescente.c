#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Fazendo do jeito preguiçoso pq lidar com memoria é muito chato
#define BUFFER_SIZE 100

// Merge Sort
char* order(char* s, int tamanho)
{
    // Caso base:
    if (tamanho == 1)
    {
        char* s2 = calloc(sizeof(char), 2);
        s2[0] = s[0];
        s2[1] = '\0';
        return s2;
    }

    int n = tamanho/2;
    char* sL = order(s, n);
    char* sR = order(s+n, tamanho - n);
    char* s2 = calloc(sizeof(char), tamanho+1);
    s2[tamanho] = '\0';

    int l = 0;
    int r = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (r < tamanho - n && (l >= n || sR[r] <= sL[l])) {
            s2[i] = sR[r];
            r++;
        }
        else {
            s2[i] = sL[l];
            l++;
        }
    }
    free(sL);
    free(sR);
    return s2;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    printf("Digite uma palavra com até 100 caracteres:\n");

    char string[BUFFER_SIZE];
    scanf("%s", string);

    int tamanho = strlen(string);

    if (tamanho == 0)
    {
        printf("Nenhuma string foi digitada.\n");
        return 0;
    }

    char* new_string = order(string, tamanho);

    printf("A string original era: %s\n", string);
    printf("A string organizada é: %s\n", new_string);

    free(new_string);
    return 0;
}