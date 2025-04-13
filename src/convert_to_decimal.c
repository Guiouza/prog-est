#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


unsigned int converter_para_decimal(unsigned int* numero_beta, unsigned int beta, unsigned int algarismos) {
    if (algarismos == 1) {
        return *numero_beta;
    }

    return *numero_beta + beta * converter_para_decimal(numero_beta+1, beta, algarismos-1);
}

int main() {
    // Habilita caracteres UTF-8 como 'é' 'ã' 'ç' '∑' '😎'
    setlocale(LC_ALL, ".UTF8");

    unsigned int beta;
    unsigned int algarismos;

    printf("Qual é a base beta? ");
    scanf("%u", &beta);
    printf("Quantos algarismos tem o número? ");
    scanf("%u", &algarismos);

    // Cria um vetor que guarda o valor de cada algarismo
    unsigned int* numero_beta = calloc(sizeof(int), algarismos);

    // Popula o vetor numero_beta
    for (unsigned int i = 0; i < algarismos; i++) {
        unsigned int keeper;
        printf("Digite o %u° algarismo: ", algarismos-i);
        scanf("%u", &keeper);

        if (keeper >= beta) {
            printf("!! Esse não é um algarismo da base beta = %u !!\n", beta);
            printf("  Digite números entre 0 e %u\n", beta-1);
            i--;
            continue;
        }

        numero_beta[algarismos-1-i] = keeper;
    }

    // Mostra o número beta, é util para bases menores que a decimal
    printf("O número é: ");
    for (unsigned int i = 1; i <= algarismos; i++) {
        printf("%u ", numero_beta[algarismos - i]);
    }
    printf("\n");

    // Calcula o número na base decimal
    unsigned int numero_decimal = converter_para_decimal(numero_beta, beta, algarismos);

    printf("Este número em base decimal é: %u\n", numero_decimal);
    return 0;
}