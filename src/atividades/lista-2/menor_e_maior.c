#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, ".UTF8");
	
	double num1, num2, num3;
	double *max, *min;
	
	printf("Digite o primeiro número: ");
	scanf("%lf", &num1);
	printf("Digite o segundo número: ");
	scanf("%lf", &num2);
	printf("Digite o terceiro número: ");
	scanf("%lf", &num3);
	
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
	
	printf("O menor número é: %g\n", *min);
	printf("O número do meio é: %g\n", num1 + num2 + num3 - *max - *min);
	printf("O maior número é: %g\n", *max);
	
	return 0;
}
