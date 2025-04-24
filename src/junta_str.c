#include<stdio.h>
#include<locale.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    char str1[BUFFER_SIZE] = "";
    char str2[BUFFER_SIZE] = "";

    printf("Digite uma frase: ");
    gets(str1);
    printf("Digite outra frase: ");
    gets(str2);

    printf("str1+str2 = %s.\n", strcat(str1, str2));

    return 0;
}