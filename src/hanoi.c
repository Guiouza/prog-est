/****************************************************************
 *             Resolução do Problema da Torre de Hanoi          *
 *                                                              *
 * Aluno: Guilherme Meneghin de Souza                           *
 *                                                              *
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Define uma constante para o comando de clear do systema.
Eu optei por definir a constante, pois esse comando muda em cada sistema operacional.
Defina para "clear" se estiver usando linux ou mac.
*/
#define CLEAR "CLS"

// Faz o mesmo que o fflush(stdin).
void limpar_stdin();

// Pausa o programa e limpa a tela para o próximo movimento na torre.
void pause_and_clear();

// Imprime na tela o estado de cada vetor.
void print_tower(unsigned int size);

// Resolve a torre de Hanoi de forma recursiva:
void hanoi(unsigned *v_init, unsigned *v_auxi, unsigned *v_final, unsigned int size, unsigned int n);

// Define na memoria o ponteiro para cada vetor do exercício.
unsigned int *vetor_A, *vetor_T, *vetor_B;

int main(int argc, char const *argv[])
{
    // Permite usar caracteres da lingua portuguesa e outros.
    setlocale(LC_ALL, ".utf8");

    // Pergunta o número de discos da torre
    printf("Digite o tamanho do vetor inicial: ");

    // Guarda o valor digitado na variável size (tamanho).
    unsigned int size;
    scanf("%u", &size);

    // Inicializa os vetores alocando memória de acordo com o tamanho da torre.
    vetor_A = malloc(size * sizeof(unsigned int)); // aloca memória sem limpar
    vetor_T = calloc(size, sizeof(unsigned int));  // aloca memória, mas limpa antes.
    vetor_B = calloc(size, sizeof(unsigned int));  // aloca memória, mas limpa antes.

    // Popula a primeira torre com os N discos o menor no começo e o maior no fim.
    for (unsigned int i = 0; i < size; i++)
        vetor_A[i] = size - i;

    // Equivalente ao fflush().
    // Estou fazendo desse jeito, porque fflush nao funciona no meu compilador.
    limpar_stdin();
    // Limpa a tela
    system(CLEAR);

    // Mostra o estado inicial da torre.
    print_tower(size);
    pause_and_clear();

    // Resolve a torre imprimindo cada passo.
    hanoi(vetor_A, vetor_T, vetor_B, size, size);

    // Libera a memória ocupada pelos vetores.
    free(vetor_A);
    free(vetor_B);
    free(vetor_T);
    
    return 0;
}

void limpar_stdin() {
    // A função fflush não funciona no meu compilador
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lê e descarta cada caractere
    }
}

void pause_and_clear()
{
    printf("\nPress Enter to Coninue...\n");
    // Não faz nada enquanto não receber um '\n' no stdin.
    while (getchar() != '\n')
        ;
    // Limpa o terminal
    system(CLEAR);
}

void print_tower(unsigned int size)
{
    // Imprime Va
    printf("\nTorre De Hanoi\nVa: ");
    for (int i = 0; i < size; i++)
    {
        if (vetor_A[i] == 0)
            continue;               // pula espaços vazios
        printf("%u, ", vetor_A[i]); // imprime os números
    }

    // Imprime Vt
    printf("\b\b  \nVt: ");
    for (int i = 0; i < size; i++)
    {
        if (vetor_T[i] == 0)
            continue;
        printf("%u, ", vetor_T[i]);
    }

    // Imprime Vb
    printf("\b\b  \nVb: ");
    for (int i = 0; i < size; i++)
    {
        if (vetor_B[i] == 0)
            continue;
        printf("%u, ", vetor_B[i]);
    }
    printf("\b\b  \n");
    /*
     * Nota, '\b' move o cursor um caracter para trás, logo '\b ' exclui o último caracter.
     * Isso serve para apagar o ', ' deixado após o último número impresso.
     */
}

void hanoi(unsigned int *v_init, unsigned int *v_auxi, unsigned int *v_final, unsigned int size, unsigned int n)
{
    if (n == 1)
    {
        // Caso base:

        // Move o primeiro disco da torre incial para a torre final.
        v_final[0] = v_init[0];
        v_init[0] = 0;
        // Mostra o estado da torre.
        print_tower(size);
        pause_and_clear();
    }
    else
    {
        // Caso n > 1:

        // Move os n-1 primeiros discos da torre inicial para a torre auxiliar.
        hanoi(v_init+1, v_final+1, v_auxi+1, size, n - 1);

        // Caso base, move o último disco da torre incial para a torre final.
        v_final[0] = v_init[0];
        v_init[0] = 0;
        // Mostra o estado da torre.
        print_tower(size);
        pause_and_clear();

        // Move os n-1 primeiros discos da torre auxiliar para a torre final.
        hanoi(v_auxi+1, v_init+1, v_final+1, size, n - 1);

        // Nota: Quando somo um ao ponteiro dos vetores nas linhas 148 e 158
        // estou aplicando o algorítimo de Hanoi para a pilha ignorando o primeiro disco,
        // ou seja, ignorando o disco maior. Por isso no caso base movemos o disco no indicíe 0.
    }
}