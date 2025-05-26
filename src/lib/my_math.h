#ifndef MY_MATH_H
#define MY_MATH_H

# ifdef USE_MY_MATH_CONSTANTS
#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536
#endif

#ifndef SQRT_ERROR
#define SQRT_ERROR 1e-10
#endif

double fabs(double x);
double sqrt(double x);
double ipow(double base, int exp);

#endif