#include <stdio.h>
#include <locale.h>
#include <time.h>

#define CONFIG_FILE_PATH "config.yml"
#define CONTAGEM_FILE_PATH "contagem.csv"

#define BUFFER_SIZE 256
#define MIN_CANDIDATOS 2
#define MAX_CANDIDATOS 10

void flush_stdin();
void gets_string(char* buffer, size_t size);

int get_anoAtual();

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    // ---- Abre os arquivos de configuação e contagem -----
    printf("Criando arquivo de configuração em `%s`.\n", CONFIG_FILE_PATH);
    FILE* config_file = fopen(CONFIG_FILE_PATH, "w");
    FILE* contagem_file = fopen(CONTAGEM_FILE_PATH, "w");

    // ---- Pergunta o nome da eleição ----
    char nome_da_eleicao[BUFFER_SIZE];
    printf("Nome da eleição: ");
    gets_string(nome_da_eleicao, BUFFER_SIZE);
    // Escreve no arquivo de configuração
    fprintf(config_file, "NOME_DA_ELEIÇÃO: \"%s\"\n", nome_da_eleicao);

    // ---- Pergunta a data da votação ----
    unsigned int mes, ano;
    printf("Data da votação (MM AAAA): ");
    scanf("%u %u", &mes, &ano);
    flush_stdin(); // Limpa o buffer de entrada após ler o número
    
    if (mes < 1 || mes > 12)
    {
        printf("Mês inválido. Deve ser entre 1 e 12.\n");
        fclose(config_file);
        fclose(contagem_file);
        return 0;
    }
    int anoAtual = get_anoAtual();
    if (ano < anoAtual)
    {
        printf("Ano inválido. Deve ser maior ou igual a %d.\n", anoAtual);
        fclose(config_file);
        fclose(contagem_file);
        return 0;
    }

    fprintf(config_file, "DATA_DA_VOTAÇÃO: %02u/%04u\n", mes, ano);

    // ---- Pergunta o número de candidatos ----
    size_t numero_de_candidatos;
    printf("Número de candidatos: ");
    scanf("%zu", &numero_de_candidatos);

    flush_stdin(); // Limpa o buffer de entrada após ler o número

    // Escreve no arquivo de configuração
    if (numero_de_candidatos < MIN_CANDIDATOS)
    {
        printf("O número deve ser maior que 2.\n");
        fclose(config_file);
        fclose(contagem_file);
        return 0;
    }
    if (numero_de_candidatos > MAX_CANDIDATOS)
    {
        printf("O número deve ser menor que 10.\n");
        fclose(config_file);
        fclose(contagem_file);
        return 0;
    }

    fprintf(config_file, "NUMERO_DE_CANDIDATOS: %zu\n", numero_de_candidatos);

    // ---- Pergunta o nome de cada candidato ----
    fprintf(config_file, "LISTA_DE_CANDIDATOS:\n");
    fprintf(contagem_file, "Id;Numero de votos;Nome\n");
    for (size_t i = 0; i < numero_de_candidatos; i++)
    {
        char nome[BUFFER_SIZE];
        printf("Nome do candidato %zu: ", i+1);
        gets_string(nome, BUFFER_SIZE);

        unsigned int id_do_candidato;
        printf("ID do candidato %zu: ", i+1);
        scanf("%u", &id_do_candidato);
        flush_stdin(); // Limpa o buffer de entrada após ler o número

        if (id_do_candidato == 0)
        {
            printf("ID inválido. Deve ser maior que 0.\n");
            fclose(config_file);
            fclose(contagem_file);
            return 0;
        }
        // Escreve no arquivo de configuração
        fprintf(config_file, "  - nome: \"%s\"\n", nome);
        fprintf(config_file, "    id: %u\n", id_do_candidato);

        // Escreve no arquivo de contagem
        fprintf(contagem_file, "%u;0;%s\n", id_do_candidato, nome);
    }

    // ---- Fecha o arquivo e termina o programa ----
    fclose(config_file);
    fclose(contagem_file);

    return 0;
}

void gets_string(char* buffer, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int c = getchar();
        if (c == '\n' || c == EOF)
        {
            buffer[i] = '\0';
            return;
        }
        buffer[i] = (char)c;
    }
    buffer[size - 1] = '\0'; // Garantir que a string esteja terminada
    flush_stdin();
}

void flush_stdin()
{
    while (getchar() != '\n'); // Limpa o buffer de entrada
}

int get_anoAtual() {
    time_t t;
    struct tm *infoTempo;

    // Obtém o tempo atual do sistema
    time(&t);

    // Converte o tempo para a hora local
    infoTempo = localtime(&t);

    // O ano é armazenado na estrutura tm.tm_year, que representa os anos desde 1900.
    // Então, para obter o ano atual, adicionamos 1900.
    int anoAtual = infoTempo->tm_year + 1900;

    return anoAtual;
}
