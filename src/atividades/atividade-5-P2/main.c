/*
A ideia aqui é diferente de ordenar a matriz em si.
Como já programei varias funções que organizam listas,
no lugar eu construirei a lista com os números da matriz, onde:
a_0;0 = l_0
...
a_0;2n = l_2n
...
...
...
a_2n;2n = l_4n(n+1)

E então eu organizo essa lista e só mostro na tela reconstruindo
as posições da matriz original.

Então a princípio não parece que a matriz está sendo organizada.
Mas ao fim do algoritmo do quicksort ela se organiza completamente.
Vale notar que esse código tem complexidade O(n^3).
Enquanto a ordenação simplesmente pegando o menor elemento e colocando na
posição correta tem complexidade O(n^4).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ---- MOSTRA A MATRIZ NO TERMINAL ----
void clean_terminal()
{
// Limpa o terminal usando o comando 'clear' no Unix/Linux ou 'cls' no Windows
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int* build_guia(size_t n)
{
    size_t tamanho = 4*n*(n+1)+1;
    int* B = malloc(tamanho * sizeof( int ));

    if (B == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a matriz guia.");
        return 0;
    }

    if (n == 0)
    {
        B[0] = 0;
        return B;
    }
    else
    {
        int* B_anterior = build_guia(n-1);
        size_t i, j, k, l;
        i = 4*n*(n-1)+1+n;
        j = 4*n*(n+1);

        size_t indicie = 0;
        size_t indicie_2 = 0;
        for (k = 0; k < n+1; k++)
            B[indicie++] = i-k;

        for (k = 0; k < n; k++)
            B[indicie++] = j--;

        for (k = 0; k < 2*n-1; k++)
        {
            B[indicie++] = ++i;
            for (l = 0; l < 2*n-1; l++)
                B[indicie++] = B_anterior[indicie_2++];
            B[indicie++] = j--;
        }
        
        for (k = 0; k < 2*n+1; k++)
            B[indicie++] = ++i;
        
        free(B_anterior);
        return B;
    }
}

int* show_matriz(int* arr, size_t n)
{
    static int* M_guia = NULL;
    // Constroi a Matriz guia se não criada
    if (M_guia == NULL)
        M_guia = build_guia(n); 
    
    clean_terminal();

    size_t pula_linha = 2*n;
    for (size_t i = 0; i < 4*n*(n+1)+1; i++) {
        printf("%d; ", arr[M_guia[i]]);

        if (pula_linha-- == 0)
        {
            pula_linha = 2*n;
            printf("\n");
        }
    }

    // Aguarda o usuário digitar enter para inicair a simulação
    printf("\nPrecione Enter para continuar:");
    while (getchar() != '\n');

    return M_guia;
}

// ---- QUICK SORT ----
void trocar(int* arr, size_t n, size_t a, size_t b) {
    if (a == b)
        return;

    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
    show_matriz(arr, n);
}

int particionar(int* arr, size_t n, size_t inicio, size_t fim) {
    int pivo = arr[fim];
    int i = inicio - 1;
    int temp; // Variavel para armazenas temporariamente um dado

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            // Troca de posição os elementos do array
            trocar(arr, n, i, j);
        }
    }
    trocar(arr, n, i+1, fim);

    return (i + 1); // Retorna o índice do pivô
}

void quickSort(int* arr, size_t n, size_t inicio, size_t fim)
{
    if (inicio < fim) {
        size_t pi = particionar(arr, n, inicio, fim);
        if (pi == 0)
        {
            quickSort(arr, n, pi + 1, fim);
        }
        else {
            quickSort(arr, n, inicio, pi - 1);
            quickSort(arr, n, pi + 1, fim);
        }
    }
}

// ---- FUNÇÃO PRINCIPAL ----
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    // ---- Carrega a ordem da matriz
    size_t tamanho;
    size_t ordem;

    size_t n = 0;
    printf("Digite o número N para a ordem 2N+1 da matriz: ");
    scanf("%u", &n);

    tamanho = 4*n*(n+1)+1; // (2n+1)^2
    ordem = 2*n+1;

    // ---- Cria a lista ----
    int* matriz = malloc(tamanho * sizeof( int ));

    if (matriz == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a matriz.");
        return 0;
    }

    size_t i, j;
    i = 0;
    j = 1;
    // ---- Carrega os valores da matriz ----
    for (size_t key = 0; key < tamanho; key++)
    {
        if (i == ordem)
        {
            i = 1;
            j++;
        }
        else i++;

        printf("Digite o valor de (%zu; %zu): ", j, i);
        scanf("%d", &matriz[key]);
    }

    while (getchar() != '\n'); // Limpa o buffer de entrada
    
    clean_terminal();
    size_t pula_linha = 2*n;
    for (size_t i = 0; i < tamanho; i++) {
        printf("%d; ", matriz[i]);

        if (pula_linha-- == 0)
        {
            pula_linha = 2*n;
            printf("\n");
        }
    }

    printf("\nPrecione Enter para continuar:");
    while (getchar() != '\n');
    clean_terminal();
    
    // ---- Organiza a Matriz ----
    quickSort(matriz, n, 0, tamanho-1);

    int* M_guia = show_matriz(matriz, n);
    printf("\nOperações terminadas:");
    while (getchar() != '\n');

    free(M_guia);
    return 0;
}