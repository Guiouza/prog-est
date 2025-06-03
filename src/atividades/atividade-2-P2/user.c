#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define CONFIG_FILE_PATH "config.yml"
#define CONTAGEM_FILE_PATH "contagem.csv"

#define BUFFER_SIZE 256

typedef struct candidato {
    char* nome;
    unsigned int id;
} Candidato;
Candidato* new_candidato(char *nome, size_t len, unsigned int id);
void free_candidato(Candidato *candidato);

int incrementar_voto(unsigned int id);

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
    
    // ---- Cria a lista de candidatos ----
    Candidato* lista_de_candidatos[num_candidatos];
    
    // Inicializa a lista como ponteiros nulos
    for (size_t i = 0; i < num_candidatos; i++)
        lista_de_candidatos[i] = NULL;
    
    // Pula uma linha do arquivo
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, config_file);

    for (size_t i = 0; i < num_candidatos; i++)
    {
        // ---- Lê o nome e ID do candidato ----
        char nome_candidato[BUFFER_SIZE];
        fgets(nome_candidato, BUFFER_SIZE, config_file);
        sscanf(nome_candidato, "  - nome: \"%[^\"]\n", nome_candidato);

        unsigned int id_do_candidato;
        fscanf(config_file, "    id: %u\n", &id_do_candidato);

        // ---- Cria o candidato com o nome e o id lido ----
        Candidato *candidato = new_candidato(nome_candidato, BUFFER_SIZE, id_do_candidato);
        // Verifica se o candidato foi criado com sucesso
        if (candidato == NULL)
        {
            printf("Erro ao criar candidato %zu.\n", i + 1);
            fclose(config_file);
            for (size_t j = 0; j < i; j++)
                free_candidato(lista_de_candidatos[j]);
            return 0;
        }

        // Adiciona o candidato à lista
        lista_de_candidatos[i] = candidato;
    }

    // ---- Exibe as informações da eleição ----
    printf("Nome da eleição: %s\n", nome_da_eleicao);
    printf("Data da votação: %02u/%04u\n", mes, ano);
    
    // ---- Inicia a votação ----
    char resposta;
    printf("Permitir votação? (y/N): ");
    scanf(" %c", &resposta);

    if (resposta != 'y')
    {
        printf("Votação não iniciada.\n");
        // ---- Libera recursos e fecha o arquivo ----
        for (size_t i = 0; i < num_candidatos; i++)
            free_candidato(lista_de_candidatos[i]);

        fclose(config_file);
        return 0;
    }

    printf("Votação iniciada!\n");
    while (1)
    {
        // ---- Exibe os candidatos disponíveis ----
        printf("Candidatos disponíveis para votação:\n");
        for (size_t i = 0; i < num_candidatos; i++)
        {
            printf(
                "Candidato %zu: %s (Número: %u)\n",
                i + 1,
                lista_de_candidatos[i]->nome,
                lista_de_candidatos[i]->id
            );
        }

        // ---- Solicita o voto do usuário ----
        unsigned int voto = 0;
        printf("Digite o número do candidato para votar (ou '0' para sair): ");
        scanf("%u", &voto);

        // Se o usuário digitar 0, encerra a votação
        if (voto == 0) break;
        
        // ---- Verifica se o voto é válido ----
        unsigned int voto_valido = 0;
        for (size_t i = 0; i < num_candidatos; i++)
        {
            if (lista_de_candidatos[i]->id == voto)
            {
                voto_valido = 1;
                break;
            }
        }
        // Se o voto não for válido, solicita novamente
        if (!voto_valido)
        {
            printf("Voto inválido. Tente novamente.\n\n");
            continue;
        }

        // ---- Incrementa o voto no arquivo de contagem ----
        if (incrementar_voto(voto) == -1)
        {
            // Se ocorrer um erro ao incrementar o voto, exibe uma mensagem de erro
            printf("Erro ao registrar o voto.\n\n");
            break;
        }
        printf("Voto registrado com sucesso!\n\n");
    }
    printf("Votação encerrada.\n");
    
    // ---- Libera recursos e fecha o arquivo ----
    for (size_t i = 0; i < num_candidatos; i++)
        free_candidato(lista_de_candidatos[i]);

    fclose(config_file);
    return 0;
}

int incrementar_voto(unsigned int id)
{
    // Abre o arquivo de contagem para leitura e escrita
    FILE *contagem_file = fopen(CONTAGEM_FILE_PATH, "r+");
    if (contagem_file == NULL)
    {
        printf("Erro ao abrir o arquivo de contagem em `%s`.\n", CONTAGEM_FILE_PATH);
        return -1;
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

    while (1)
    {
        unsigned int id_candidato;
        unsigned int votos;
        char nome[BUFFER_SIZE];
        // Lê a posição atual do arquivo para voltar depois
        fpos_t pos;
        fgetpos(contagem_file, &pos);

        char line[BUFFER_SIZE*2];
        fgets(line, BUFFER_SIZE, contagem_file);
        // Lê a linha do arquivo de contagem
        if (sscanf(line, "%u;%u;%[^\n]\n", &id_candidato, &votos, nome) != 3)
        {
            printf("Erro ao ler o arquivo de contagem. Verifique o formato do arquivo.\n");
            fclose(contagem_file);
            return -1;
        }

        // Verifica se o ID do candidato corresponde ao ID do voto
        if (id_candidato == id)
        {
            // Incrementa o número de votos
            votos++;
            // Volta para o início da linha para sobrescrever
            fsetpos(contagem_file, &pos);
            // Escreve a linha atualizada no arquivo de contagem com o voto incrementado
            fprintf(contagem_file, "%u;%u;%s\n", id_candidato, votos, nome);
            fflush(contagem_file); // Garante que os dados sejam escritos no arquivo
            break;
        }
    }
    
    fclose(contagem_file);
    return 0;
}

Candidato* new_candidato(char *nome, size_t len, unsigned int id)
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