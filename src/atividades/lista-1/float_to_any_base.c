#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_RESOLUCAO 10
#define uint_size sizeof(unsigned int)

typedef struct {
    unsigned int* vector;
    unsigned int size;
} Array;

Array* create_array() {
    Array* pointer = malloc(sizeof(Array));
    return pointer;
}

void free_array(Array* pointer) {
    free(pointer->vector);
    free(pointer);
}

Array* conversor_decimal_para_beta(double numero_decimal, unsigned int beta) {
    // Aloca um vetor de uint na heap
    unsigned int *numero_beta = malloc(LIMITE_RESOLUCAO * uint_size);
    long int posicao = 0;

    while (numero_decimal != 0) {
        if (posicao == LIMITE_RESOLUCAO)
            break;

        numero_decimal = numero_decimal * beta;
        numero_beta[posicao] = (int) numero_decimal;
        numero_decimal = numero_decimal - numero_beta[posicao];
        posicao++;
    }

    // limpa os espaços vazios do array
    unsigned int size = posicao;
    unsigned int *holder = numero_beta;

    numero_beta = malloc(size * uint_size);
    memcpy(numero_beta, holder, size * uint_size);
    free(holder);
    
    Array* number = create_array();
    number->vector = numero_beta;
    number->size = size;

    return number;
}

int main() {
    // Habilita caracteres UTF-8 como 'é' 'ã' 'ç' '∑' '😎'
    setlocale(LC_ALL, ".UTF8");

    double numero_decimal;
    unsigned int beta;

    printf("Digite o número em base decimal entre 0 e 1: ");
    scanf("%lf", &numero_decimal);
    printf("Qual é a base beta? ");
    scanf("%u", &beta);

    while (numero_decimal < 0 || numero_decimal > 1) {
        printf("O número deve estar entre 0 e 1 como 0.5.\n");
        printf("Digite o número decimal novamente: ");
        scanf("%lf", &numero_decimal);
    }

    printf("Na base 10: %lf\n", numero_decimal);

    Array* number = conversor_decimal_para_beta(numero_decimal, beta);

    printf("Na base %d é: 0. ", beta);
    for (int i = 0; i < number->size; i++)
        printf("%u ", number->vector[i]);
    printf("\n");

    free_array(number);
    return 0;
}