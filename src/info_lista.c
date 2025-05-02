#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Nó da lista ligada
typedef struct Node {
    unsigned int data;
    struct Node *next;
} Node;

// Ponteiro para um nó
typedef Node* NodePtr;

/// @brief Cria um novo nó e armazeno o valor de data
/// @param data Um número inteiro para ser armazenado no nó.
/// @return Retorna um ponteiro para o nó craido.
NodePtr createNode(unsigned int data);

/// @brief Libera a memória ocupada pela lista ligada
/// @param no_raiz Um ponteiro para o primeiro nó.
void freeNode(NodePtr no_raiz);

/// @brief Insere um nó no início da lista
/// @param no_raiz Um ponteiro para o primeiro nó.
/// @param data Um número inteiro para ser armazenado no nó.
/// @return Retorna um ponteiro para o novo nó raiz.
NodePtr insertNode(NodePtr no_raiz, unsigned int data);

/// @brief Conta número de nós na lista ligada.
/// @param no_raiz Um ponteiro para o primeiro nó.
/// @return Retorna o tamanho da lista ligada.
unsigned int getNumOfNodes(NodePtr no_raiz);

/// @brief Procura pelo nó com o menor valor.
/// @param no_raiz Um ponteiro para o primeiro nó.
/// @return Retorna um ponteiro para o menor nó
NodePtr getMinNode(NodePtr no_raiz);

/// @brief Procura pelo nó com o maior valor.
/// @param no_raiz Um ponteiro para o primeiro nó.
/// @return Retorna um ponteiro para o maior nó
NodePtr getMaxNode(NodePtr no_raiz);

/// @brief Calcula a média dos números pares da lista ligada
/// @param no_raiz Um ponteiro para o primeiro nó
/// @return Um a média dos números pares
double getEvenMean(NodePtr no_raiz);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    NodePtr no_raiz = NULL;

    while (1)
    {
        int number;
        printf("Digite um valor: ");
        scanf("%d", &number);
        // para quando o número é negativo
        if (number < 0) break;
        // Só insere se for negativo
        no_raiz = insertNode(no_raiz, number);
    }

    // Ignora o primeiro nó que é o numero negativo
    unsigned int tamanho = getNumOfNodes(no_raiz);
    NodePtr min_node = getMinNode(no_raiz);
    NodePtr max_node = getMaxNode(no_raiz);
    double media = getEvenMean(no_raiz);

    printf("Números inteiros positivos digitados = %u.\n", tamanho);

    // Se não forem digitados números negativos para aqui
    if (tamanho == 0) return 0;

    printf("O valor do menor número inteiro positivo digitado = %u.\n", min_node->data);
    printf("O valor do maior número inteiro positivo digitado = %u.\n", max_node->data);
    
    if (media == -1)
    {
        printf("Nenhum número par foi digitado.\n");
        return 0;
    }

    printf("A média dos números pares positivos digitados = %g.\n", media);

    freeNode(no_raiz);
    return 0;
}

NodePtr createNode(unsigned int data) {
    // Cria um novo node
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    // Armazena o valor de data e limpa o ponteiro para next
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeNode(NodePtr no_raiz) {
    // Se o ponteiro para o nó por fazio nao faz nada
    if (no_raiz == NULL) return;
    // Se nao for vazio libera o próximo nó
    freeNode(no_raiz->next);
    // Ao fim da recursão todos os próximos nós sao liberados
    // Libera o ultimo nó
    free(no_raiz);
}

NodePtr insertNode(NodePtr no_raiz, unsigned int data) {
    // Cria um novo nó
    NodePtr newNode = createNode(data);
    // Aponta o proximo node como o início da lista
    newNode->next = no_raiz;
    return newNode;
}

unsigned int getNumOfNodes(NodePtr no_raiz) {
    unsigned int tamanho = 0;

    // Percorre a lista até o ultimo nó
    NodePtr node = no_raiz;
    while (node != NULL)
    {
        tamanho += 1;
        node = node->next;
    }
    return tamanho;
}

NodePtr getMinNode(NodePtr no_raiz)
{
    if (no_raiz == NULL) return NULL;
    NodePtr min_node = no_raiz;

    // Percorre a lista até o ultimo nó
    NodePtr node = no_raiz->next;
    while (node != NULL)
    {   
        if (node->data < min_node->data)
        {
            min_node = node;
        }

        node = node->next;
    }
    return min_node;
}

NodePtr getMaxNode(NodePtr no_raiz)
{
    if (no_raiz == NULL) return NULL;
    NodePtr max_node = no_raiz;
    // Percorre a lista até o ultimo nó
    NodePtr node = no_raiz->next;
    while (node != NULL)
    {   
        if (node->data > max_node->data)
        {
            max_node = node;
        }

        node = node->next;
    }
    return max_node;
}

double getEvenMean(NodePtr no_raiz)
{
    unsigned int soma = 0;
    unsigned int tamanho = 0;
    int tem_pares = 0;
    // Percorre a lista até o ultimo nó
    NodePtr node = no_raiz;
    while (node != NULL) {
        // se for par soma
        if (node->data % 2 == 0) {
            tem_pares = 1;
            soma += node->data;
        }

        tamanho++;
        node = node->next;
    }

    if (tem_pares) return soma / ((double) tamanho);
    return -1;
}