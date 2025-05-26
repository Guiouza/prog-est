#include "my_math.h"

#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, ".UTF8");

	double a, b, c;
	
	printf("Digite a equação de segundo grau na forma reduzida: ax² + bx + c = 0\n\ta: ");
	scanf("%lf", &a);
	
	while (a == 0) {
		printf("O termo 'a' que acompanha x² deve ser diferente de zero!\n");
		printf("\ta: ");
		scanf("%lf", &a);
	}
	
	printf("\tb: ");
	scanf("%lf", &b);
	printf("\tc: ");
	scanf("%lf", &c);

	double delta = b*b - 4*a*c;
	
	if (delta < 0) {
		// raizes complexas:
		delta = delta * (-1);
		double parte_real = -b/(2*a);
		double parte_complexa = sqrt(delta)/(2*a);
		
		printf("As raízes da equação são:\n");
		if (parte_real != 0) {
			printf("\tx₁ = %g + %g*i\n", parte_real, parte_complexa);
			printf("\tx₂ = %g - %g*i\n", parte_real, parte_complexa);
		}
		else {
			printf("\tx₁ = %g*i\n", parte_complexa);
			printf("\tx₂ = - %g*i\n", parte_complexa);
		}
	}
	else if (delta == 0) {
		double raiz = (-b + sqrt(delta))/(2*a);
		printf("A raiz da equação é:\n");
		printf("\tx = %g\n", raiz);
	}
	else {
		double raiz_1 = (-b + sqrt(delta))/(2*a);
		double raiz_2 = (-b - sqrt(delta))/(2*a);
		printf("As raízes da equação são:\n");
		printf("\tx₁ = %g\n", raiz_1);
		printf("\tx₂ = %g\n", raiz_2);
	}
	return 0;
}
