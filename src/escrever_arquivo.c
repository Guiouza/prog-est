#include<stdio.h>
#include<locale.h>
#include<string.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    FILE* file = fopen("test/escrever_arquivo/arquivo.txt", "a+");

    // Formulário
    char nome[BUFFER_SIZE];
    char* error = gets_s(nome, BUFFER_SIZE);
    fwrite(nome, sizeof(char), strlen(nome), file);
    fclose(file);
    return 0;
}