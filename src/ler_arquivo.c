#include<stdio.h>
#include<locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    FILE* file = fopen("test/ler_arquivo/arquivo.yml", "r");

    while (!feof(file)) {
        printf("%c", fgetc(file));
    }

    fclose(file);
    return 0;
}