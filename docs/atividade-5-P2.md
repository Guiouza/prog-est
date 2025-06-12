# Resolução da Atividade 5 P2

## Arquivos
Arquivos associados à atividade 5 P2:

| Exercício | Programa em C |
| :- | :- |
| Programa do administrador | [`src/atividades/atividade-5-P2/main.c`](/src/atividades/atividade-5-P2/main.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make atividade-5-P2
```

Utilizando o MSVC (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
mkdir out\atividade-5-P2
# Compilar a atividade
cl.exe src\atividades\atividade-5-P2\main.c /Foout\atividade-5-P2\main
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
# Mode para o diretório de build
cd out/atividade-5-P2
./main.c        # Executa o programa
cd ../..        # Volta para o diretório inicial
```

Para apagar esses arquivos basta executar:
```bash
make clean
```
Assim, todos os arquivos dentro da pasta `out/` serão apagados.

## Exercícios
Considere uma matriz quadrada de ordem 2n+1.
Cada matriz tem o seu elemento central e podemos considerar anéis ao redor dele.
O primeiro anel é formado pelos vizinhos do elemento central, o próximo anel, é
formado pelos vizinhos destes, externamente, e assim sucessivamente.

Elabore um programa em Linguagem C, que leia ou solicite a entrada da dimensão da matriz e seus elementos.

Organize estes números de forma que o menor fique no elemento central.
Os demais vão ficar nos anéis, em ordem crescente e no sentido anti-horário,
considerando como ponto inicial, o elemento imediatamente superior ao elemento
central, e assim sucessivamente, com cada anel sempre iniciando no elemento
imediatamente superior ao anterior na coluna do elemento central.

A cada movimento deve-se fazer mudança de 2 números e apresentado a nova matriz
(com um tempo de visualização).

Exemplo:

 1  3  2
-2  1  3
5   9  -5

1  3  2
-2  -5  3
5   9  1

 1  -2  2
3  -5  3
 5   9  1