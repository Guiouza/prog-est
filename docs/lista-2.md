# Resolução da Lista - 2

## Arquivos
Abaixo estão listados os exercícios e os arquivos a eles associados:

| Exercício | Programa em C |
| :- | :- | 
| Exercício 1 | [`src/lista-2/baskara.c`](/src/lista-2/baskara.c) |
| Exercício 2 | [`src/lista-2/menor_e_maior.c`](/src/lista-2/menor_e_maior.c) |
| Exercício 3 | [`src/lista-2/triangulo.c`](/src/lista-2/triangulo.c) |
| Exercício 4 | [`src/lista-2/mdc.c`](/src/lista-2/mdc.c) |
| Exercício 5 | [`src/lista-2/e_primo.c`](/src/lista-2/e_primo.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make lista-2
```

Utilizando o NMake (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
nmake lista-2
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC` e o `NMake`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
./out/baskara       # Para executar o exercício 1
./out/menor_e_maior # Para executar o exercício 2
./out/triangulo     # Para executar o exercício 3
./out/mdc           # Para executar o exercício 4
./out/e_primo       # Para executar o exercício 5
```

## Exercícios
1. Programa para resolver uma equação do 2º Grau (ax2+bx+c=0), (i) reais; (ii) complexas; e (iii) todas as raízes.
2. Programa para determinar o maior valor entre 3 valores reais dados.
3. Programa para dados 3 valores reais estritamente positivos, verificar se esses valores foram os lados de um triângulo.
Em caso afirmativo, verificar se é um triângulo equilátero, isósceles ou escaleno.
4. Programa para calcular o mdc(A,B), sendo A e B inteiros positivos. Verificar se algum é não nulo, neste caso o mdc é o valor não nulo. 
5. Programa para verificar se um dado inteiro positivo é um número primo.
