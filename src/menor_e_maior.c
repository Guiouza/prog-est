#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	
	float num1, num2, num3;
	float *max, *min;
	
	printf("Digite o primeiro n�mero: ");
	scanf("%f", &num1);
	printf("Digite o segundo n�mero: ");
	scanf("%f", &num2);
	printf("Digite o terceiro n�mero: ");
	scanf("%f", &num3);
	
	if (num2 < num1 && num3 < num1) {
		max = &num1;
		if (num2 < num3)
			min = &num2;
		else min = &num3;
	}
	else if (num1 < num2 && num3 < num2) {
		max = &num2;
		if (num1 < num3)
			min = &num1;
		else min = &num3;
	}
	else {
		max = &num3;
		if (num1 < num2)
			min = &num1;
		else min = &num2;
	}
	
	printf("O menor n�mero �: %g\n", *min);
	printf("O n�mero do meio �: %g\n", num1 + num2 + num3 - *max - *min);
	printf("O maior n�mero �: %g\n", *max);
	
	return 0;
}
