#include<stdio.h>
#include<locale.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");
    
    char str[BUFFER_SIZE] = "";

    printf("Digite uma frase: ");
    gets(str);

    int len;
    for (len = 0; str[len] != '\0'; len++);
    len++;

    printf("A frase abaixo tem %d caracteres:\n'%s'.\n", len, str);
        
    return 0;
}