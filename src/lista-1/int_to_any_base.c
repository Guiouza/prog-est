#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5
#define uint_size sizeof( unsigned int )

typedef struct _array {
    unsigned int* vector;
    unsigned int size;
} * Array;

Array new_array();
void free_array(Array pointer);

Array int_to_any_base(unsigned int numero_decimal, unsigned int beta) {
    // Aloca um vetor de uint na heap
    unsigned int* numero_beta = malloc(BUFFER_SIZE * uint_size);

    unsigned int size = BUFFER_SIZE;
    long int posicao = BUFFER_SIZE;

    do {
        if (--posicao == -1) {
            // Cria um holder para receber o numero_beta antigo
            unsigned int* holder = numero_beta;
            // Cria um novo espaço maior para armazenar o número na base beta
            numero_beta = malloc(size + BUFFER_SIZE * uint_size);

            // copia os valores de holder para o novo numero_beta
            memcpy(numero_beta+size, holder, size*uint_size);
            free(holder);

            // atualiza as variaveis de motiramento do array:
            size += BUFFER_SIZE;
            posicao += BUFFER_SIZE;
        }

        numero_beta[posicao] = numero_decimal % beta;
        numero_decimal = numero_decimal / beta; // divisao inteira
    }
    while (numero_decimal != 0);

    // limpa os espaços vazios do array
    unsigned int real_size = size - posicao;
    unsigned int *holder = numero_beta;

    numero_beta = malloc(real_size * uint_size);
    memcpy(numero_beta, holder + posicao, real_size*uint_size);
    free(holder);
    
    Array number = new_array();
    number->vector = numero_beta;
    number->size = real_size;

    return number;
}

int main() {
    setlocale(LC_ALL, ".UTF8");

    unsigned int numero_decimal;
    unsigned int beta;

    printf("Digite o número em base decimal: ");
    scanf("%u", &numero_decimal);
    printf("Qual é a base beta? ");
    scanf("%u", &beta);

    Array number = int_to_any_base(numero_decimal, beta);

    printf("Esse número na base beta é: ");
    for (int i = 0; i < number->size; i++)
        printf("%u ", number->vector[i]);
    printf("\n");

    free_array(number);
    return 0;
}

/// @brief Cria um novo array na heap
/// @return `Array`: Retorna um ponteiro para o array na heap
Array new_array()
{
    Array pointer = malloc(sizeof(Array));
    return pointer;
}
/// @brief Deleta um array da heap
/// @param pointer: Um ponteiro para o array na heap
void free_array(Array pointer)
{
    free(pointer->vector);
    free(pointer);
}