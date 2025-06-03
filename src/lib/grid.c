#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

grid_t* create_grid(size_t height, size_t width)
{
    grid_t *new_grid = malloc(SIZEOF_GRID_T);
    if (new_grid == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a grid.\n");
        return NULL;
    }
    // Aloca memória para a grid
    char **celulas = calloc(height, sizeof(char *));
    if (celulas == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a grid.\n");
        return NULL;
    }

    // Inicializa as células da grid
    for (size_t y = 0; y < height; y++)
    {
        celulas[y] = calloc(width, sizeof(char));
        // Verifica se a alocação foi bem-sucedida
        if (celulas[y] == NULL)
        {
            fprintf(stderr, "Erro ao alocar memória para a linha %zu da grid.\n", y);
            // Libera a memória já alocada antes de retornar
            for (size_t i = 0; i < y; i++)
                free(celulas[i]);
            free(celulas);
            free(new_grid);
            return NULL;
        }
        else
        {
            // Preenche a linha com espaços em branco
            for (size_t x = 0; x < width; x++)
                celulas[y][x] = ' ';
        }
    }

    new_grid->height = height;
    new_grid->width = width;
    new_grid->cells = celulas;

    return new_grid;
}

void destroy_grid(grid_t *grid)
{
    if (grid == NULL)
        return;

    // Libera a memória de cada linha
    for (size_t y = 0; y < grid->height; y++)
    {
        // Libera o array de colunas
        free(grid->cells[y]);
    }
    // Libera a memória do array de linhas
    free(grid->cells);
    // Libera a memória da grid
    free(grid);
}

void draw_grid(grid_t* grid)
{
    if (grid == NULL || grid->cells == NULL)
    {
        fprintf(stderr, "Erro: grid não inicializada.\n");
        return;
    }
    if (grid->height == 0 || grid->width == 0)
    {
        fprintf(stderr, "Erro: grid vazia.\n");
        return;
    }

    // ---- Desenha a moldura superior ----
    putchar('+');
    for (size_t x = 0; x < grid->width*2 - 1; x++)
    {
        putchar('=');
    }
    puts("+");

    // ---- Desenha as linhas do grid ----
    for (size_t y = 0; y < grid->height; y++)
    {
        putchar('|');
        for (size_t x = 0; x < grid->width; x++)
        {
            putchar(get_cell(grid, x, y));
            putchar('|');
        }
        puts("\b|");
    }

    // ---- Desenha a moldura inferior ----
    putchar('+');
    for (size_t x = 0; x < grid->width*2 - 1; x++)
    {
        putchar('=');
    }
    puts("+");
}

void clear_grid(grid_t *grid)
{
    if (grid == NULL)
        return;

    // Preenche todas as células com espaços em branco
    for (size_t x = 0; x < grid->width; x++)
    {
        for (size_t y = 0; y < grid->height; y++)
        {
            set_cell(grid, x, y, ' ');
        }
    }
}

void set_cell(grid_t *grid, size_t x, size_t y, char value)
{
    if (grid == NULL || x >= grid->width || y >= grid->height)
    {
        fprintf(stderr, "Erro: tentativa de acessar célula fora dos limites da grid.\n");
        return;
    }
    grid->cells[y][x] = value;
}

char get_cell(grid_t *grid, size_t x, size_t y)
{
    if (x < grid->width && y < grid->height)
        return grid->cells[y][x];
    fprintf(stderr, "Tentativa de acessar célula fora dos limites da grid.\n");
    return -1;
}

int is_grid_empty(grid_t* grid)
{
    for (size_t y = 0; y < grid->height; y++)
    {
        for (size_t x = 0; x < grid->width; x++)
        {
            if (get_cell(grid, x, y) != ' ')
                return 0;
        }
    }
    return 1;
}
