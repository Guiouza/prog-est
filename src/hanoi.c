#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define CLEAR "CLS"

int *vetor_A, *vetor_T, *vetor_B;

void pause_and_clear() {
    printf("\nPress Enter to Coninue...\n");
    getchar();
    system(CLEAR);
}

void print_tower(unsigned int n) {
    printf("\nTorre De Hanoi\nVa: ");

    for (int i = 1; i <= n; i++) {
        if (vetor_A[n-i] == 0) continue;
        printf("%d, ", vetor_A[n-i]);
    }

    printf("\b\b  \nVt: ");

    for (int i = 1; i <= n; i++) {
        if (vetor_T[n-i] == 0) continue;
        printf("%d, ", vetor_T[n-i]);
    }

    printf("\b\b  \nVb: ");

    for (int i = 1; i <= n; i++) {
        if (vetor_B[n-i] == 0) continue;
        printf("%d, ", vetor_B[n-i]);
    }

    printf("\b\b  \n");
}

void hanoi(int* va, int* vt, int* vb, unsigned int size, unsigned int n) {
    if (n == 1) {
        vb[n-1] = va[n-1];
        va[n-1] = 0;
        print_tower(size);
        pause_and_clear();
    }
    else {
        hanoi(va, vb, vt, size, n-1);

        vb[n-1] = va[n-1];
        va[n-1] = 0;
        print_tower(size);
        pause_and_clear();

        hanoi(vt, va, vb, size, n-1);
    }
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    printf("Digite o tamanho do vetor inicial: ");
    unsigned int size;
    scanf("%u", &size);

    vetor_A = malloc(size * sizeof(int));
    vetor_T = calloc(size, sizeof(int));
    vetor_B = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        vetor_A[i] = i+1;

    system(CLEAR);
    getchar();
    print_tower(size);
    pause_and_clear();

    hanoi(vetor_A, vetor_T, vetor_B, size, size);

    free(vetor_A);
    free(vetor_B);
    free(vetor_T);
    return 0;
}