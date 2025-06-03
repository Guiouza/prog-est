#ifndef GRID
#define GRID

#include <stdio.h>

typedef struct grid_t {
    size_t height;
    size_t width;
    char** cells;
} grid_t;

#define SIZEOF_GRID_T sizeof( grid_t )

/// @brief Cria uma grid com o tamanho especificado
/// @param height O numero de linhas da grid
/// @param width O numero de colunas da grid
/// @return Um ponteiro para a grid alocada dinamicamente
/// @note A grid é inicializada com espaços em branco (' ').
///
/// E precisa ser destruída com `destroy_grid` para evitar vazamento de memória.
grid_t* create_grid(size_t height, size_t width);

/// @brief Libera a memória alocada para a grid
/// @param grid Um ponteiro para a grid a ser destruída
/// @note É importante chamar essa função para evitar vazamento de memória.
void destroy_grid(grid_t* grid);

/// @brief Desenha uma grid com os epaçamentos e em uma moldura
/// @param grid A matriz que representa o grid
/// @param rows O número de linhas do grid
/// @param cols O número de colunas do grid
/// @note Um exemplo de grid seria:
/// ```
///  draw_grid({"xox", "oxo", "x o"}, 3, 3);
///  +=====+
///  |x o x|
///  |o x o|
///  |x   o|
///  +=====+
/// ```
/// O caracter '\0' é ignorado, pois o número de colunas é passado como 3.
void draw_grid(grid_t* grid);

/// @brief Limpa a grid, preenchendo todas as células com espaços em branco (' ')
/// @param grid Um ponteiro para a grid a ser limpa
/// @note Esta função não libera a memória da grid, apenas limpa seu conteúdo.
void clear_grid(grid_t* grid);

/// @brief Muda o valor de uma célula específica na grid
/// @param grid Um ponteiro para a grid onde a célula será alterada
/// @param x A linha da célula a ser alterada
/// @param y A coluna da célula a ser alterada
/// @param value O valor a ser atribuído à célula
/// @note Certifique-se de que `x` e `y` estão dentro dos limites da grid
/// para evitar comportamento indefinido.
void set_cell(grid_t* grid, size_t x, size_t y, char value);

/// @brief Retorna o valor da célula com cordenada (x,y)
/// @param grid Um ponteiro para a grid
/// @param x O índicie da coluna da célula
/// @param y O índicie da linha da célula
char get_cell(grid_t *grid, size_t x, size_t y);

/// @brief Verifica se todas as células de uma grid são ' '
/// @param grid Um ponteiro para a grid a ser analisada
/// @return Retorna 0 se a grid não está vazia e 1 se está
int is_grid_empty(grid_t* grid);

#endif