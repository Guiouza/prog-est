#include "my_math.h"

/// @brief Calcula o valor absoluto de um número
/// @param x Um número real
/// @return | x | o valor absoluto de x (`double`)
double fabs(double x)
{
    if (x >= 0) return x;
    return -x;
}

/// @brief Calcula a raiz quadrada de um número pelo método de Newton
///
/// O erro da aproximação é definido em `SQRT_ERROR` (default: `1e-10`).
/// Para alterar defina `SQRT_ERROR` antes de incluir `my_math.h`.
/// @param x Um número real
/// @return Retorna a raiz quadrada de x (`double`)
/// @warning Se x for negativo, retorna -1
double sqrt(double x)
{
    // Se x for negativo, retorna -1
    // Isso é necessário para evitar divisão por zero
    // e também para melhorar a precisão
    if (x < 0) return -1;
    // Error: negative number
    if (x < 0) return -1;

    // Retorna o número se for 0 ou 1
    // Isso é necessário para evitar divisão por zero
    // e também para melhorar a precisão
    if (x == 0 || x == 1) return x;

    // ---- Metodo de Newton ----
    double guess = x / 2.0;

    while (fabs(guess * guess - x) >= SQRT_ERROR)
    {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

/// @brief Calcula a potência de um número real a um expoente inteiro
/// @param base O número real que será elevado a um expoente inteiro
/// @param exp O expoente inteiro
/// @return Retorna o resultado da potência (`double`)
double ipow(double base, int exp)
{
    if (exp < 0) return 1.0 / ipow(base, -exp);

    double result = 1.0;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}