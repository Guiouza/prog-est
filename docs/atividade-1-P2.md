# Resolução da Atividade 1 P2

## Arquivos
Arquivos associados à atividade 1 P2:

| Exercício | Programa em C |
| :- | :- |
| Programa principal | [`src/atividades/atividade-1-P2/sort.c`](/src/atividades/atividade-1-P2/sort.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make atividade-1-P2
```

Utilizando o MSVC (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
mkdir out\atividade-1-P2
# Compilar a atividade
cl.exe src\atividades\atividade-1-P2\sort.c /Foout\atividade-2-P2\sort
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC` e o `NMake`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
# Mode para o diretório de build
cd out/atividade-2-P2
./sort         # Testa a atividade
```

## Exercícios
Implementar na Linguagem C, um programa para ordenar uma lista usando o método da inserção.
