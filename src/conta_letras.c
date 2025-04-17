#include<stdio.h>
#include<locale.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    char str[BUFFER_SIZE];
    char word;

    printf("Digite uma frase: ");
    gets(str);

    printf("Digite um caracter: ");
    scanf("%c", &word);

    int len = strlen(str);
    unsigned int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == word)
            count++;
    }

    printf("A letra '%c' aparece %u vezes na frase:\n%s.", word, count, str);
        
    return 0;
}