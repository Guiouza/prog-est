# Resolução da Atividade 3 P2

## Arquivos
Arquivos associados à atividade 3 P2:

| Exercício | Programa em C |
| :- | :- |
| Programa do administrador | [`src/atividades/atividade-3-P2/contra_cheque.c`](/src/atividades/atividade-3-P2/contra_cheque.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make atividade-3-P2
```

Utilizando o MSVC (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
mkdir out\atividade-3-P2
cp src\atividades\atividade-3-P2\templates\* out\atividade-3-P2\
# Compilar a atividade
cl.exe src\atividades\atividade-3-P2\contra_cheque.c /Foout\atividade-3-P2\contra_cheque
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
# Mode para o diretório de build
cd out/atividade-3-P2
./contra_cheque
cd ../..
```
É recomendado executar de dentro da pasta `out/atividade-3-P2`, pois serão lidos
ou criados arquivos de texto dentro dessa pasta.

Para apagar esses arquivos basta executar:
```bash
make clean
```
Assim, todos os arquivos dentro da pasta `out/` serão apagados.

## Exercícios
Em uma empresa, o salário mensal (bruto) de um funcionário depende da quantidade de horas regulares e das horas extras realizadas no mês. O valor de cada hora regular é de R$ 113,23 e por cada hora extra, o funcionário deve receber o valor da hora regular acrescida de 50%. 

Do salário bruto do funcionário , devem-se retidos 6% são retidos pela Previdência Social, 14%, pelo Imposto de Renda, 5%, por impostos estaduais, e 1% para o Sindicato. Se o funcionário tiver três ou mais dependentes, um adicional de R$ 35 é retido para cobrir o custo extra do seguro de saúde. 

Escreva um programa no qual conste em um arquivo os nomes dos empregados e respectivo número de dependentes. Mensalmente para cada funcionário deve ser informado o número de horas mensais trabalhadas e horas extras. 

Ao final, deve ser emitido relatório informando para cada funcionário, o salário bruto, os respectivos descontos e o salário líquido (bruto menos valores retidos).
