# Resolução da Lista - 3

## Arquivos
Abaixo estão listados os exercícios e os arquivos a eles associados:

| Exercício | Programa em C |
| :- | :- |
| Exercício 1 | [`src/lista-3/fatorial.c`](/src/lista-3/fatorial.c) |
| Exercício 2 | [`src/lista-3/soma_dos_naturais.c`](/src/lista-3/soma_dos_naturais.c) |
| Exercício 3 | [`src/lista-3/soma_em_diagonal.c`](/src/lista-3/soma_em_diagonal.c) |
| Exercício 4 | [`src/lista-3/soma_fracoes_de_2eN.c`](/src/lista-3/soma_fracoes_de_2eN.c) |
| Exercício 5 | [`src/lista-3/pi.c`](/src/lista-3/pi.c) |
| Exercício 6 | [`src/lista-3/cosseno.c`](/src/lista-3/cosseno.c) |
| Exercício 7 | [`src/lista-3/soma_vetores.c`](/src/lista-3/soma_vetores.c) |
| Exercício 8 | [`src/lista-3/produto_escalar.c`](/src/lista-3/produto_escalar.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make lista-3
```

Utilizando o NMake (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
nmake lista-3
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC` e o `NMake`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
./out/lista-3/fatorial              # Para executar o exercício 1
./out/lista-3/soma_dos_naturais     # Para executar o exercício 2
./out/lista-3/soma_em_diagonal      # Para executar o exercício 3
./out/lista-3/soma_fracoes_de_2eN   # Para executar o exercício 4
./out/lista-3/pi                    # Para executar o exercício 5
./out/lista-3/cosseno               # Para executar o exercício 6
./out/lista-3/soma_vetores          # Para executar o exercício 7
./out/lista-3/produto_escalar       # Para executar o exercício 8
```

## Exercícios
1.	Programa para calcular o fatorial de N,  N!, N inteiro positivo,
2.	Programa para calcular a soma S=1+2+3+...+N
3.	Programa para a soma: S=1/N + 2/(N-1) + 3/(N-2) + ... + N/1.
4.	Programa para calcular a soma a seguir com N termos: S=1/1+ 1/2+ 1/4+1/8 ...
5.	Programa para calcular o valor de π, com erro menor que 0.001, utilizando a seguinte expressão: π = 4 –4/3 +4/5 -4/7 +4/9...
6.	Programa para calcular o valor de cos(x), usando a seguinte série truncada em n termos: 1 - x^2/2! + x^4/4! - x^6/6!...
7.	Programa para ler e somar 2 vetores n-dimensionais de valores reais.
8.	Programa para ler 2 vetores N-dimensionais e calcular o produto escalar entre eles.
