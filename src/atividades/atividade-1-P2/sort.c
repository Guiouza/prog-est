#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef double* (*__sort_func) (double*, size_t); // tipo funcao de ordenacao

void trocar(double* p, double* q)
{
    double t = *p;
    *p = *q;
    *q = t;
}

double* bsort(double* list, size_t len)
{
    int i, j;

    for (size_t i = 1; i < len; i++)
    {
        for (size_t j = 0; j < len-i; j++)
        {
            if (list[j+1] < list[j])
            {
                trocar(&list[j+1], &list[j]);
            }
        }
    }
    return list;
}

double* ssort(double* list, size_t len)
{
    double *min_pos;

    for (size_t j = 0; j < len-1; j++)
    {
        min_pos = list+j;
        for (size_t i = j+1; i < len; i++)
        {
            if (*min_pos > list[i])
            {
                min_pos = list+i;
            }
        }
        trocar(min_pos, &list[j]);
    }
    return list;
}

double* msort(double* list, size_t len)
{
    // Caso base:
    if (len == 1)
    {
        double* list_orded = calloc(len, sizeof(double));
        list_orded[0] = list[0];
        return list_orded;
    }

    int n = len/2;

    double* listL = msort(list, n);
    double* listR = msort(list+n, len - n);
    double* list_orded = calloc(len, sizeof(double));

    int l = 0;
    int r = 0;
    for (int i = 0; i < len; i++)
    {
        if (r < len - n && (l >= n || listR[r] <= listL[l])) {
            list_orded[i] = listR[r];
            r++;
        }
        else {
            list_orded[i] = listL[l];
            l++;
        }
    }
    free(listL);
    free(listR);
    return list_orded;
}

double* isort(double* list, size_t len) {
    // Começa com o segundo item da lista até o último
    for (size_t i = 1; i < len; i++)
    {
        // Itera a cada elemento anterior ao item a ser ordenado
        for (size_t j = 1; j <= i; j++)
        {
            // Se o o anterior for maior troca de lugar
            if (list[i-j] > list[i-j+1])
            {
                trocar(&list[i-j], &list[i-j+1]);
            }
            else break; // Se não for passa para o próximo item
        }
    }
    return list;
}

double* quicksort(double* list, size_t tamanho)
{
    if (tamanho <= 1)
        return list;

    double pivo = list[tamanho-1];
    size_t i = 0;

    for (int j = 0; j < tamanho-1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (list[j] <= pivo) {
            // Troca de posição os elementos do listay
            trocar(list+i, list+j);
            i++;
        }
    }
    trocar(list+i, list+tamanho-1);

    size_t pi = i;

    if (pi == 0)
        quicksort(list + 1, tamanho - 1);
    else {
        quicksort(list, pi);
        quicksort(list + pi + 1, tamanho - pi - 1);
    }

    return list;
}

void test_sort(double* lista, size_t list_size, __sort_func sort_func) {
    double* lista_ordenada = malloc(list_size * sizeof(double));
    for (size_t n = 0; n < list_size; n++) {
        lista_ordenada[n] = lista[n];
    }
    lista_ordenada = sort_func(lista, list_size);
    
    for (size_t n = 0; n < list_size; n++)
        printf("%g, ", lista_ordenada[n]);

    printf("\b\b  \n==================\n");
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    size_t list_size;
    printf("Digite o tamanho da lista: ");
    scanf("%zu", &list_size);

    double* lista = malloc(sizeof(double)*list_size);
    for (size_t n = 0; n < list_size; n++) {
        printf("%zu° valor: ", n+1);
        scanf("%lf", lista+n);
    }

    printf("\nBubble Sort:\n");
    test_sort(lista, list_size, &bsort);

    printf("Selection Sort:\n");
    test_sort(lista, list_size, &ssort);

    printf("Insertion Sort:\n");
    test_sort(lista, list_size, &isort);

    printf("Merge Sort:\n");
    test_sort(lista, list_size, &msort);

    printf("Quick Sort:\n");
    test_sort(lista, list_size, &quicksort);

    return 0;
}
