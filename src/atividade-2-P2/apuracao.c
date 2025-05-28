#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define CONTAGEM_FILE_PATH "contagem.csv"
#define CONFIG_FILE_PATH "config.yml"

#define BUFFER_SIZE 256

typedef struct candidato {
    char* nome;
    unsigned int id;
    unsigned int votos;
} Candidato;
Candidato* new_candidato(char *nome, size_t len, unsigned int id, unsigned int votos);
void free_candidato(Candidato *candidato);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    // ---- Inicia a eleicao lendo o arquivo de configuração ----
    FILE *config_file = fopen(CONFIG_FILE_PATH, "r");
    if (config_file == NULL)
    {
        printf("Erro ao abrir o arquivo de configuração em `%s`.\n", CONFIG_FILE_PATH);
        return 0;
    }

    // ---- Lê as informações da eleição ----
    char nome_da_eleicao[BUFFER_SIZE];
    fgets(nome_da_eleicao, BUFFER_SIZE, config_file);
    sscanf(nome_da_eleicao, "NOME_DA_ELEIÇÃO: \"%[^\n\"]\n", nome_da_eleicao);
    
    unsigned int mes, ano;
    fscanf(config_file, "DATA_DA_VOTAÇÃO: %u/%u\n", &mes, &ano);

    size_t num_candidatos;
    fscanf(config_file, "NUMERO_DE_CANDIDATOS: %zu\n", &num_candidatos);

    fclose(config_file);

    // ---- Exibe as informações da eleição ----
    printf("Nome da eleição: %s\n", nome_da_eleicao);
    printf("Data da votação: %02u/%04u\n", mes, ano);

    // Abre o arquivo de contagem para leitura
    FILE *contagem_file = fopen(CONTAGEM_FILE_PATH, "r");
    if (contagem_file == NULL)
    {
        printf("Erro ao abrir o arquivo de contagem em `%s`.\n", CONTAGEM_FILE_PATH);
        return 0;
    }

    // Lê o cabeçalho do arquivo de contagem
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, contagem_file);
    // Verifica se o cabeçalho está correto
    if (strcmp(buffer, "Id;Numero de votos;Nome\n") != 0)
    {
        printf("Erro no formato do arquivo de contagem. Verifique o cabeçalho.\n");
        fclose(contagem_file);
        return -1;
    }

    // ---- Cria a lista de candidatos ----
    Candidato* lista_de_candidatos[num_candidatos];
    // Inicializa a lista como ponteiros nulos
    for (size_t i = 0; i < num_candidatos; i++)
        lista_de_candidatos[i] = NULL;
    
    unsigned int max_votos = 0;
    unsigned int num_de_votos = 0;
    for (size_t i = 0; i < num_candidatos; i++) {
        unsigned int id_candidato;
        unsigned int votos;
        char nome[BUFFER_SIZE];
        
        char line[BUFFER_SIZE*2];
        fgets(line, BUFFER_SIZE, contagem_file);
        // Lê a linha do arquivo de contagem
        if (sscanf(line, "%u;%u;%[^\n]\n", &id_candidato, &votos, nome) != 3)
        {
            printf("Erro ao ler o arquivo de contagem. Verifique o formato do arquivo.\n");
            fclose(contagem_file);
            return -1;
        }
        num_de_votos++;
        if (votos > max_votos) max_votos = votos;

        Candidato *candidato = new_candidato(nome, BUFFER_SIZE, id_candidato, votos);

        lista_de_candidatos[i] = candidato;
    }

    Candidato* vencedores[num_candidatos];
    for (size_t j = 0; j < num_candidatos; j++)
        vencedores[j] = NULL;

    // ---- Exibe os candidatos e seus votos ----
    size_t i = 0;
    for (size_t j = 0; j < num_candidatos; j++)
    {
        printf("Candidato: %s\n", lista_de_candidatos[j]->nome);
        printf("ID: %u\n", lista_de_candidatos[j]->id);
        printf("Votos: %u\n", lista_de_candidatos[j]->votos);
        printf("Porcentagem: %.2f%%\n", 
               (double)lista_de_candidatos[j]->votos / num_de_votos * 100);
        printf("\n");

        if (lista_de_candidatos[j]->votos == max_votos)
        {
            vencedores[i++] = lista_de_candidatos[j];
        }
    }

    // ---- Exibe o vencedor ou vencedores ----
    printf("\nVencedor(es):\n");
    if (i == 0)
    {
        printf("Nenhum candidato recebeu votos.\n");
    }
    else
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("Candidato: %s ", vencedores[j]->nome);
            printf("ID: %u\n", vencedores[j]->id);
        }
    }

    // ---- Libera a memória alocada para os candidatos ----
    for (size_t j = 0; j < num_candidatos; j++)
    {
        free_candidato(lista_de_candidatos[j]);
    }
    fclose(contagem_file);
    return 0;
}

Candidato* new_candidato(char *nome, size_t len, unsigned int id, unsigned int votos)
{
    Candidato *candidato = (Candidato*) malloc(sizeof(Candidato));
    if (candidato == NULL)
    {
        printf("Erro ao alocar memória para o candidato.\n");
        return NULL;
    }

    candidato->nome = (char*) malloc(len * sizeof(char));
    if (candidato->nome == NULL)
    {
        printf("Erro ao alocar memória para o nome do candidato.\n");
        free(candidato);
        return NULL;
    }
    // Copia o nome do candidato para a estrutura
    snprintf(candidato->nome, len, "%s", nome);

    candidato->id = id;
    candidato->votos = votos; // Inicializa o número de votos como 0
    return candidato;
}

void free_candidato(Candidato *candidato)
{
    if (candidato != NULL)
    {
        free(candidato->nome);
        free(candidato);
    }
}
