#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Lista {
    unsigned int tamanho;
    int* vetor;
} Lista;

Lista* createLista(unsigned int len) {
    Lista* lista = malloc(sizeof(Lista));

    lista->tamanho = len;
    lista->vetor = malloc(sizeof(int)*len);
    return lista;
}

void freeLista(Lista* lista) {
    free(lista->vetor);
    free(lista);
}

Lista* cleanLista(Lista* lista) {
    Lista* nova_lista = createLista(lista->tamanho);

    unsigned int j = 0;
    for (unsigned int i = 0; i < lista->tamanho; i++)
    {
        if (lista->vetor[i] != 0)
        {
            nova_lista->vetor[j] = lista->vetor[i];
            j++;
        }
    }
    nova_lista->tamanho = j;
    return nova_lista;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int tamanho;
    printf("Qual o tamanho da lista? ");
    scanf("%u", &tamanho);

    Lista *lista = createLista(tamanho);

    for (unsigned int i = 0; i < tamanho; i++)
    {
        printf("Digite o %i° número: ", i+1);
        scanf("%d", lista->vetor+i);
    }
    
    Lista* nova_lista = cleanLista(lista);

    printf("\nVetor orignial: x = (");
    for (unsigned int i = 0; i < lista->tamanho; i++)
    {
        printf("%d, ", lista->vetor[i]);
    }
    printf("\b\b) \nVetor final: (");
    for (unsigned int i = 0; i < nova_lista->tamanho; i++)
    {
        printf("%d, ", nova_lista->vetor[i]);
    }
    printf("\b\b) \n");
    
    freeLista(lista);
    freeLista(nova_lista);
    return 0;
}