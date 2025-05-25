#include <stdio.h>
#include <locale.h>

double fabs(double x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

unsigned int isqrt(unsigned int x) {
	if (x == 0.0) return 0.0; // raiz quadrada de zero é zero

	double result = 1.0; // valor inicial
	static const double epsilon = 0.1; // precisão desejada

	// Método de Newton para calcular a raiz quadrada
	while (fabs(result * result - x) > epsilon)
	{
		result = (result + x / result) / 2.0;
	}
	return (unsigned int) result;
}

int e_primo(unsigned int x) {
    if (x <= 1) return 0;
    
    int primo = 1;
    for (int i = 2; i <= isqrt(x); i += 2)
    {
        primo &= x % i != 0;
        if (i == 2) i--;
    }

    return primo;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".UTF8");

    unsigned int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%u", &numero);
    
    if (e_primo(numero))
    {
        printf("%u é primo.\n", numero);
        return 0;
    }
    printf("%u não é primo.\n", numero);
    return 0;
}