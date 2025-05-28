#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

double round_2f(double num);

// Define um tamanho para os buffers de char[]
#define BUFFER_SIZE 200
// Path para os arquivos de configuração e de log
#define F_EMPREGADOS "empregados.csv"
#define F_RELATORIO  "relatório.csv"
#define HEADER_ESPERADO "Nome;Dependentes\n"

// Estrutura de empregado
typedef struct _empregado {
    char *nome;
    int dependentes;
} Empregado;

// Funções que calculam salário
double calcular_salario(int horas_regulares, int horas_extras);
double calcular_salario_liquido(double salario_bruto);
// Funções que calculam descontos e impostos
double calcular_previdencia_social(double salario_bruto);
double calcular_imposto_de_renda(double salario_bruto);
double calcular_imposto_estadual(double salario_bruto);
double calcular_sindicato(double salario_bruto);
double calcular_desconto_de_dependentes(int numero_de_dependentes);
// Metodos de empregrado
Empregado* new_empregado(char* nome, size_t len, int dependentes);
Empregado* parse_empregado(char* text, int len);
void free_empregado(Empregado* empregado);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    // Abre o arquivo de empregados
    FILE* f_empregrados = fopen(F_EMPREGADOS, "r");    
    // Checa o header do arquivo de empregados
    char* header = calloc(BUFFER_SIZE, sizeof( char ));
    fgets(header, BUFFER_SIZE, f_empregrados);
    if (strcmp(header, HEADER_ESPERADO))
    {
        fclose(f_empregrados);
        printf("Error!: O arquivo %s não possui o formato esperado:\n", F_EMPREGADOS);
        printf("\tformato esperado: %s",HEADER_ESPERADO);
        printf("\tformato encontrado: %s",header);
        free(header);
        return 1;
    }
    free(header);

    // Abre o arquivo de log
    FILE* f_relatorio = fopen(F_RELATORIO, "w");
    // Prepara o header do arquivo de log
    fputs("Nome;", f_relatorio);
    fputs("Salário Bruto;", f_relatorio);
    fputs("Previdência Social;", f_relatorio);
    fputs("Imposto de Renda;", f_relatorio);
    fputs("Impostos Estaduais;", f_relatorio);
    fputs("Sindicato;", f_relatorio);
    fputs("Desconto de Dependentes;", f_relatorio);
    fputs("Salário Líquido\n", f_relatorio);

    // Verifica se os arquivos foram abertos corretamente
    if (f_empregrados == NULL)
    {
        printf("Ocorreu um erro e não foi possível abrir o arquivo: %s", F_EMPREGADOS);
        return 1;
    }
    if (f_relatorio == NULL)
    {
        printf("Ocorreu um erro e não foi possível abrir o arquivo: %s", F_RELATORIO);
        return 1;
    }

    // Le os funcionários
    while(1) {
        // Le uma linha do arquivo de funcionarios
        char line[BUFFER_SIZE];
        fgets(line, BUFFER_SIZE, f_empregrados);

        if (feof(f_empregrados)) break;

        // Parseia a linha em uma struct de fucionario
        Empregado* empregado = parse_empregado(line, BUFFER_SIZE);

        // Se não conseguir parsear para o programa.
        if (empregado == NULL)
        {
            printf("Não foi possível parsear a linha:\n%s", line);
            fclose(f_empregrados);
            fclose(f_relatorio);
            return 1;
        }

        printf("Empregado %s:\n", empregado->nome);
        // Pergunta as horas regulares trabalhadas
        int horas_regulares;
        printf("\tHoras Regulares: ");
        scanf("%u", &horas_regulares);
        // Pergunta as horas extras trabalhadas
        int horas_extras;
        printf("\tHoras Extras: ");
        scanf("%u", &horas_extras);

        // Calcula o salário
        double salario_bruto = calcular_salario(horas_regulares, horas_extras);
        double previdencia_social = calcular_previdencia_social(salario_bruto);
        double imposto_de_renda = calcular_imposto_de_renda(salario_bruto);
        double imposto_estadual = calcular_imposto_estadual(salario_bruto);
        double sindicato = calcular_sindicato(salario_bruto);
        double desconto_de_dependentes = calcular_desconto_de_dependentes(empregado->dependentes);

        double salario_liquido = salario_bruto;
        salario_liquido -= previdencia_social;
        salario_liquido -= imposto_de_renda;
        salario_liquido -= imposto_estadual;
        salario_liquido -= sindicato;
        salario_liquido -= desconto_de_dependentes;

        // Escreve no arquivo de log:
        fprintf(
            f_relatorio,
            "%s;%g;%g;%g;%g;%g;%g;%.2lf\n",
            empregado->nome,
            salario_bruto,
            previdencia_social,
            imposto_de_renda,
            imposto_estadual,
            sindicato,
            desconto_de_dependentes,
            round_2f(salario_liquido)
        );

        free_empregado(empregado);
    }

    fclose(f_empregrados);
    fclose(f_relatorio);
    return 0;
}

// Lógica de salário:
double calcular_salario(int horas_regulares, int horas_extras)
{
    static const double SALARIO_BASE = 0.0;
    static const double SALARIO_POR_HORA_REGULAR = 113.23;
    static const double TAXA_DE_HORA_EXTRA = 1.5;
    // Calcula o salário bruto:
    double salario = SALARIO_BASE;
    salario += horas_regulares*SALARIO_POR_HORA_REGULAR;
    salario += horas_extras*SALARIO_POR_HORA_REGULAR*TAXA_DE_HORA_EXTRA;
    return salario;
}

double calcular_previdencia_social(double salario_bruto) 
{
    static const double TAXA_DE_PREVIDENCIA_SOCIAL = 0.06;
    return salario_bruto*TAXA_DE_PREVIDENCIA_SOCIAL;
}

double calcular_imposto_de_renda(double salario_bruto)
{
    static const double TAXA_DE_IMPOSTO_DE_RENDA = 0.14;
    return salario_bruto*TAXA_DE_IMPOSTO_DE_RENDA;
}

double calcular_imposto_estadual(double salario_bruto)
{
    static const double TAXA_DE_IMPOSTOS_ESTADUAIS = 0.05;
    return salario_bruto*TAXA_DE_IMPOSTOS_ESTADUAIS;
}

double calcular_sindicato(double salario_bruto)
{
    static const double TAXA_DE_SINDICATO = 0.01;
    return salario_bruto*TAXA_DE_SINDICATO;
}

double calcular_desconto_de_dependentes(int numero_de_dependentes)
{
    static const double DESCONTO_DE_DEPENDENTES = 35.0;
    // Alícotas de número de dependentes:
    // 3+ dependetes:
    if (numero_de_dependentes >= 3) return DESCONTO_DE_DEPENDENTES;
    // 0..2 dependentes:
    return 0.0;
}

// Métodos de empregado:
Empregado* new_empregado(char* nome, size_t len, int dependentes)
{
    Empregado* empregado = malloc(sizeof ( Empregado ));
    
    empregado->nome = calloc(len, sizeof( char ));
    strcpy(empregado->nome, nome);

    empregado->dependentes = dependentes;
    
    return empregado;
}

Empregado* parse_empregado(char* text, int len)
{
    int semicolon = -1;

    // Encontra o indicie com o caracter ponto e virgula `;`
    for (int i = 0; i < len-1; i++)
    {
        if (text[i] == ';')
        {
            semicolon = i;
            break;
        }
    }
    // Retorna erro se não encontrar a virgula
    if (semicolon == -1) return NULL;
    
    // Copia o numero de dependentes no documento para uma variavel
    int n_dependentes = -1;
    sscanf(text+(semicolon+1), "%d", &n_dependentes);
    // Verifica se o número de dependentes é negativo e retorna erro
    if (n_dependentes < 0) return NULL;

    // Copia o nome no documento para uma variavel
    char* nome = calloc(semicolon+1, sizeof( char ));
    strncpy(nome, text, semicolon);
    nome[semicolon] = '\0';

    // Cria um novo empregado
    Empregado* Empregado = new_empregado(nome, semicolon+1, n_dependentes);

    free(nome);
    return Empregado;
}

void free_empregado(Empregado* empregado)
{
    free(empregado->nome);
    free(empregado);
}

double round_2f(double num)
{
    int termo_significativo = num*100;
    int termo_a_arredondar = (num*100 - termo_significativo)*10;

    if (termo_a_arredondar >= 5) termo_significativo++;
    
    return ((double) termo_significativo) / 100.0;
}
