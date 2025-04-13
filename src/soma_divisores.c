#include<stdio.h>
#include<locale.h>

int soma_divisoes(int n) {
    int soma = n + 1;
    for (int i = 2; i <= n/2; i ++) {
        if (n % i == 0) {
            soma ++;
        }
    }
    return soma;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    int numero_1, numero_2;

    printf("Digite um número natural: ");
    scanf("%d", &numero_1);
    printf("Digite um número natural: ");
    scanf("%d", &numero_2);

    int soma_1 = soma_divisoes(numero_1);
    int soma_2 = soma_divisoes(numero_2);

    printf("A soma dos divisores de %d é %d.\n", numero_1, soma_1);
    printf("A soma dos divisores de %d é %d.\n", numero_2, soma_2);

    if (soma_1 == soma_2) {
        printf("Os números %d e %d são amigos.\n", numero_1, numero_2);
    }
    return 0;
}