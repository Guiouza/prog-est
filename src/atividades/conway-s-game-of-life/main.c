#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "grid.h"

#define VIVO '#'
#define MORTO ' '

#define TIME_TO_SLEEP 200 // mili segundos

void clean_terminal();
void draw_title();
void game_pause();
void conways_simulate(grid_t* grid);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    // Abre o arquivo de configuração
    FILE *config_file = fopen("config.txt", "r");
    if (config_file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo \"config.txt\".\n");
        return 0;
    }
    
    // Carrega o tamanho da grid a partir do arquivo de configuração
    size_t height, width;
    if (fscanf(config_file, "%zu %zu:", &width, &height) != 2)
    {
        fprintf(stderr, "Erro ao ler o arquivo de configuração.\n");
        fclose(config_file);
        return 0;
    }

    // Inicializa a grid
    grid_t *grid = create_grid(height, width);
    if (grid == NULL)
    {
        fprintf(stderr, "Erro ao criar a grid.\n");
        return 1;
    }

    clean_terminal();
    draw_title();
    draw_grid(grid);

    // Carrega a grid com células vivas
    size_t x = 0;
    size_t y = 0;
    while(1) {
        x = 0;
        while (1) {
            char cell = getc(config_file);
            if (cell == VIVO || cell == MORTO)
            {
                set_cell(grid, x, y, cell);
                char cell = getc(config_file); // pula um caracter
                x++;
            }
            if (x == width)
                break;
        }
        y++;
        if (y == height)
            break;
    }

    fclose(config_file);

    clean_terminal();
    draw_title();
    draw_grid(grid);

    // Aguarda o usuário digitar enter para inicair a simulação
    printf("\nPrecione Enter para iniciar:");
    while (getchar() != '\n');

    // Inicia a simulação
    conways_simulate(grid);

    destroy_grid(grid);
    return 0;
}

void clean_terminal()
{
// Limpa o terminal usando o comando 'clear' no Unix/Linux ou 'cls' no Windows
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void draw_title()
{
    // Imprime o cabeçalho do programa
    printf("\n\n|====> Conway's Game of Life <====|\n\n");
}

void game_pause()
{
#ifdef _WIN32
    Sleep(TIME_TO_SLEEP*1000);
#else
    usleep(TIME_TO_SLEEP*1000);
#endif
}

void conways_simulate(grid_t* grid)
{
    // Aliases para height e width
    size_t height = grid->height;
    size_t width = grid->width;

    // Grid para armazenar as mudanças:
    grid_t* new_grid = create_grid(height, width);
    grid_t* to_detroy = new_grid;
    if (new_grid == NULL)
    {
        fprintf(stderr, "Não foi possível iniciar o jogo.\n");
        return;
    }

    int houve_mudancas = 1;
    do {
        clean_terminal();
        draw_title();
        draw_grid(grid);

        houve_mudancas = 0;
        // Calcula as atualizaões da grid:
        for (size_t x = 0; x < width; x ++) {
            for (size_t y = 0; y < height; y++) {
                // Calcula a quantidade de vizinhos
                int vizinhos = 0;
                if (y != 0)
                    vizinhos += get_cell(grid, x, y - 1) == VIVO;
                if (y != height - 1)
                    vizinhos += get_cell(grid, x, y + 1) == VIVO;
                if (x != width - 1)
                {
                    vizinhos += get_cell(grid, x + 1, y) == VIVO;
                    if (y != 0)
                        vizinhos += get_cell(grid, x + 1, y - 1) == VIVO;
                    if (y != height - 1)
                        vizinhos += get_cell(grid, x + 1, y + 1) == VIVO;
                }
                if (x != 0)
                {
                    vizinhos += get_cell(grid, x - 1, y) == VIVO;
                    if (y != height - 1)
                        vizinhos += get_cell(grid, x - 1, y + 1) == VIVO;
                    if (y != 0)
                        vizinhos += get_cell(grid, x - 1, y - 1) == VIVO;
                }

                // Inicia a celula na nova grid
                char status = get_cell(grid, x, y);
                set_cell(new_grid, x, y, status);
                
                // Verifica as regras do Jogo
                // Se vizinhos = 3 mantem vivo ou nasce
                if (vizinhos == 3)
                {
                    // Verifica mudanca de estado
                    if (!houve_mudancas && status == MORTO)
                        houve_mudancas = 1;
                    
                    set_cell(new_grid, x, y, VIVO);
                }
                // Se vizinhos = 2 apenas mantem vivo
                else if (vizinhos == 2 && status == VIVO)
                    set_cell(new_grid, x, y, VIVO);
                // se não morre ou mantem morto
                else {
                    // Verifica mudanca de estado
                    if (!houve_mudancas && status == VIVO)
                        houve_mudancas = 1;

                    set_cell(new_grid, x, y, MORTO);
                }
            }
        }

        // Aplica as alterações trocando as grids
        grid_t* holder = grid;
        grid = new_grid;
        new_grid = holder;

        printf("\nPrecione CTRL-C em caso de LOOP!\n");

        // Faz uma pausa para ajustar o fps
        game_pause();
    } while (houve_mudancas);

    destroy_grid(to_detroy);
}
