# Exercícios de Programação Estruturada

Resolução das listas de exercícios do curso de programação estruturada.

## Lista 1
Exercícios da lista 1:

- [Exercício 1 - convert_to_decimal.c](src/convert_to_decimal.c)
- [Exercício 2 - convert_from_decimal.c](src/convert_from_decimal.c)
- [Exercício 3 - convert_from_decimal_float.c](src/convert_from_decimal_float.c)

## Lista 2
Exercícios da lista 2:

- [Exercício 1 - formula_de_baskara.c](src/formula_de_baskara.c)
- [Exercício 2 e 3 - menor_e_maior.c](src/menor_e_maior.c)
- [Exercício 4 e 5 - e_triangulo.c](src/e_triangulo.c)
- [Exercício 6 - mdc.c](src/mdc.c)
- [Exercício 7 - e_primo.c](src/e_primo.c)

## Lista 3
Exercícios da lista 3:

- [Exercício 1 - fatorial.c](src/fatorial.c)
- [Exercício 2 - soma_dos_naturais.c](src/soma_dos_naturais.c)
- [Exercício 3 - soma_em_diagonal.c](src/soma_em_diagonal.c)
- [Exercício 4 - soma_dos_inversos_2eN.c](src/soma_dos_inversos_2eN.c)
- [Exercício 5 - pi.c](src/pi.c)
- [Exercício 6 - cosseno.c](src/cosseno.c)
- [Exercício 7 - lista_em_modulo.c](src/lista_em_modulo.c)
- [Exercício 8 - lista_div_amplitude.c](src/lista_div_amplitude.c)
- [Exercício 9 - soma_matriz.c](src/soma_matriz.c)

## Aula 10/04/2025
Exercícios da aula do dia 10/04 sobre as estruturas `for`, `while` e `do while`:

- [Exercício 1 - fatorial.c](src/fatorial.c)
- [Exercício 2 - combinacao.c](src/combinacao.c)
- [Exercício 3 - binomio_de_newton.c](src/binomio_de_newton.c)
- [Exercício 4 - soma_divisores.c](src/soma_divisores.c)

## Aula 15/04/2025
Exercícios da aula do dia 15/04 sobre funções e recursão:

- [Exercício 1 - soma_dos_naturais.c](src/soma_dos_naturais.c)
- [Exercício 2 - fatorial.c](src/fatorial.c)
- [Exercício 3 - potencia.c](src/potencia.c)
- [Exercício 4 - fibonacci.c](src/fibonacci.c)
- [Exercício 5 - combinacao.c](src/combinacao.c)

## Aula 17/04/2025
Exercícios da aula do dia 17/04 sobre a biblioteca `string.h`:

- [Exercício 1 - conta_letras.c](src/conta_letras.c)
- [Exercício 2 - tamanho_str.c](src/tamanho_str.c)
- [Exercício 3 - junta_str.c](src/junta_str.c)

## Desafio da Aula 22/04/2025

- [Exercício 1 - hanoi.c](/src/hanoi.c)

## Lista 4:
Exercícios da lista 4:

- [Exercício 1 - nota_e_media.c](/src/nota_e_media.c)
- [Exercício 2 - info_lista.c](/src/info_lista.c)
- [Exercício 3 - resolver_eq_lienar.c](/src/resolver_eq_lienar.c)
- [Exercício 4 - letras_crescente.c](/src/letras_crescente.c)
- [Exercício 5 - limpar_lista.c](/src/limpar_lista.c)

# Algorítmos de Ordenação: Aula 08/05/2025
- [Exercício 1 - insertion sort](src/sort.c)

# Como Compilar os Programas

Eu uso o compilador Microsoft Visual C++ usando no Visual Studio.

## Baixando o MSVC
Abra um terminal do windows, para abrir pesquise `cmd` na barra de pesquisa.
Execute o comando:

```pwsh
winget install Microsoft.VisualStudio.2022.BuildTools --force --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows11SDK.26100"
```

Esse comando iniciará a baixar o instalador do Visual Studio, Visual Studio Installer, que por sua vez instalará o MSVC e um terminal de desenvolvedor.

## Compilando o Código
Eu programei um script de powershell para facilitar a compilação e o teste dos programas. Basta abrir o terminal de desenvolverdor: Vá em iniciar > Pesquiser por `dev` > Abra o ` Developer PowerShell for VS 2022` > Navegue até o diretório do repositório `prog-est/` > Execute o comando `./run` e siga as instruções do programa.
Basta inserir o nome do arquivo que quer compilar, por exemplo: `hanoi.c`. Lembrando que todos os programas estão listados na página do github separados por lista e por nome. O script irá compilar e executar o programa, nesse caso `hanoi.exe`, automaticamente para você.

## Desinstalando o Compilador
Abra o Visual Studio Installer e desinstale o MSVC por lá. Depois é desinstale o terminal e o instalador do Visual Studio como se desinstalaria qualquer outros aplicativo do Windows.