#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef double* (*__sort_func) (double*, size_t);

double* bsort(double* list, size_t len) {
    int i, j;
    long long* p = list;

    for (size_t i = 1; i < len; i++)
    {
        for (size_t j = 0; j < len-i; j++)
        {
            if (list[j+1] < list[j])
            {
                p[j+1] = p[j+1] ^ p[j];
                p[j] = p[j] ^ p[j+1];
                p[j+1] = p[j+1] ^ p[j];
            }
            
        }
    }
    return list;
}

double* ssort(double* list, size_t len) {
    double *min_pos;
    double key;

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
        key = list[j];
        list[j] = *min_pos;
        (*min_pos) = key;
    }
    return list;
}

double* msort(double* list, size_t len)
{
    // Caso base:
    if (len == 1)
    {
        double* list_orded = calloc(sizeof(double), len);
        list_orded[0] = list[0];
        return list_orded;
    }

    int n = len/2;

    double* listL = msort(list, n);
    double* listR = msort(list+n, len - n);
    double* list_orded = calloc(sizeof(double), len);

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

void test_sort(size_t list_size, __sort_func sort_func) {
    double* lista = malloc(sizeof(double)*list_size);
    double* lista_ordenada;

    for (size_t n = 0; n < list_size; n++)
    scanf_s("%lf", lista+n);
    
    lista_ordenada = sort_func(lista, list_size);
    
    printf("==================\n");
    for (size_t n = 0; n < list_size; n++)
        printf("%g\n", lista_ordenada[n]);

    printf("==================\n");
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    test_sort(5, &bsort);
    test_sort(5, &ssort);
    test_sort(5, &msort);
    
    return 0;
}