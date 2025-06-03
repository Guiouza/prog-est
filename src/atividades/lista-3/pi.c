#define USE_MY_MATH_CONSTANTS
#include "my_math.h"

#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    double pi = 0;
    double i = 1;
    int sig = 1;

    while (fabs(M_PI - pi) > 0.001)
    {
        pi += 4*sig/i;
        i+=2;
        sig = -sig;
    }

    printf("A aproximação de pi é: %lf\n", pi);
    return 0;
}