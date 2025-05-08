/*
 * Exercício 3B
 * Aluno: Guilherme Meneghin de Souza
 */

#include <stdio.h>
#include <locale.h>

#define BUFFER_SIZE 100

int main()
{
    setlocale(LC_ALL, ".utf8");

    // Recebe a string do stdin:
    char string[BUFFER_SIZE] = "";
    printf("Digite as palavras separadas por espaço: ");
    gets(string);

    // Conta o número de palavras
    int numero_palavras = 0;
    // Marca o de procurar espaços e procurar palavras
    int procurando_espacos = 0;

    for (int i = 0; i < 99 && string[i] != '\0'; i++)
    {
        // Se não estiver procurando espaços:
        if (!procurando_espacos)
        {
            // Se achar uma palavra:
            if (string[i] != ' ') {
                numero_palavras++; // conta a palavra
                procurando_espacos = 1; // começa a procurar espaços
            }
        }
        // Se estiver procurando espaços e char algum
        else if (string[i] == ' ') {
            procurando_espacos = 0; // começa a procurar palavras
        }
    }

    // Imprime o número de palavras encontradas
    printf("A contagem de palavras é: %d.\n", numero_palavras);
    return 0;
}
