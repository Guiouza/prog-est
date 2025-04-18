#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define EQUILATERO 0
#define ISOCELES 1
#define ESCALENO 2

int verifica_triangulo(float a, float b, float c) {
	int e_triangulo = 1;
	e_triangulo &= c < a + b;
	e_triangulo &= b < a + c;
	e_triangulo &= a < b + c;

	return e_triangulo;
}

int classifica_triangulo(int a, int b, int c) {
	if (a == b && b == c)
		return EQUILATERO;
	if (a == b || b == c || a == c)
		return ISOCELES;
	return ESCALENO;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, ".utf8");
	
	float a, b, c;
	do {
		printf("Digite o comprimento dos lados (numeros positivos): ");
		scanf("%f %f %f", &a, &b, &c);
	}
	while(a < 0 && b < 0 && c < 0);
	
	if (!verifica_triangulo(a, b, c)) {
		printf("Não é triângulo");
		return 0;
	}

	printf("É um triângulo ");
	switch (classifica_triangulo(a, b, c)) {
	case EQUILATERO:
		printf("equilátero e ");
	case ISOCELES:
		printf("isóceles");
		break;
	case ESCALENO:
		printf("escaleno");
		break;
	}
	return 0;
}