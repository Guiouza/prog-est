# Resolução da Lista - 1

## Arquivos
Abaixo estão listados os exercícios e os arquivos a eles associados:

| Exercício | Programa em C |
| :- | :- | 
| Exercício 1 | [`src/lista-1/convert_to_int.c`](/src/lista-1/convert_to_int.c) |
| Exercício 2 | [`src/lista-1/int_to_any_base.c`](/src/lista-1/int_to_any_base.c) |
| Exercício 3 | [`src/lista-1/float_to_any_base.c`](/src/lista-1/float_to_any_base.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Use o pdf da lista linkado a baixo para saber qual exercício é qual:
> [Lista-1: Lista_exercicios_fev_2025.pdf](https://github.com/user-attachments/files/20445451/Lista_exercicios_fev_2025.pdf)

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make lista-1
```

Utilizando o NMake (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
nmake lista-1
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC` e o `NMake`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
./out/convert_to_int        # Para executar o exercício 1
./out/int_to_any_base       # Para executar o exercício 1
./out/float_to_any_base     # Para executar o exercício 1
```
