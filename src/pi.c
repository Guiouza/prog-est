#include <stdio.h>
#include <locale.h>

#define _USE_MATH_DEFINES
#include <math.h>

double d_abs(double number) {
    if (number >= 0) {
        return number;
    }
    return -number;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    double pi = 0;
    double i = 1;
    int sig = 1;
    while (d_abs(M_PI - pi) > 0.001)
    {
        pi += 4*sig/i;
        i+=2;
        sig = -sig;
    }
    printf("A aproximação de pi é: %lf", pi);
    return 0;
}