#include <stdio.h>
#include <locale.h>

#define MAX_FALTAS 18
#define MEDIA_MIN_DO_EXAME 4
#define MEDIA_MIN_DA_APROVACAO_SEM_EXAME 7
#define MEDIA_MIN_DA_APROVACAO_COM_EXAME 5


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, ".utf8");

    unsigned int faltas;
    printf("Digite o número de faltas: ");
    scanf("%u", &faltas);

    if (faltas > MAX_FALTAS)
    {
        printf("Aluno reprovado por faltas.\n");
        return 0;
    }
    
    double notas[3] = {0, 0, 0};
    printf("Digite a primeira nota: ");
    scanf("%lf", notas);
    printf("Digite a segunda nota: ");
    scanf("%lf", notas+1);

    double media = (notas[0]+notas[1])/2.0;
    if (media >= MEDIA_MIN_DA_APROVACAO_SEM_EXAME)
    {
        printf("Aluno aprovado sem necesidade de exame.\n");
        return 0;
    }
    if (media < MEDIA_MIN_DO_EXAME)
    {
        printf("Aluno reprovado sem nota suficiente para o exame.\n");
        return 0;
    }

    printf("Digite a nota do exame: ");
    scanf("%lf", notas+2);

    media = (media + notas[2])/2.0;

    if (media >= MEDIA_MIN_DA_APROVACAO_COM_EXAME)
    {
        printf("Aluno aprovado por exame.\n");
        return 0;
    }

    printf("Aluno reprovado sem nota suficiente.\n");
    return 0;
}