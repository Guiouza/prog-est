# Resolução da Lista - 3

## Arquivos
Arquivos associados à atividade 2 P2:

| Exercício | Programa em C |
| :- | :- |
| Programa do administrador | [`src/atividade-2-P2/admin.c`](/src/atividade-2-P2/admin.c) |
| Programa de votação do usuário | [`src/atividade-2-P2/user.c`](/src/atividade-2-P2/user.c) |
| Programa de apuração | [`src/atividade-2-P2/apuracao.c`](/src/atividade-2-P2/apuracao.c) |

> [!NOTE]
> Os arquivos foram nomeados de modo arbitrário.
> Veja a lsita de exercícios na ultima sessão.

## Build:
Utilizando o Make:
```sh
# Execute esse comando na raiz do projeto
make atividade-2-P2
```

Utilizando o NMake (Lembre-se de executar o comando usando o Developer Power Shell ou o Developer Command Prompt):
```pwsh
# Execute esse comando na raiz do projeto
nmake atividade-2-P2
```

> [!WARNING]
> É necessário ter instalado o compilador `GCC` e a ferramenta `Make` ou o `MSVC` e o `NMake`.
> Veja as instruções de instalação na página inicial do projeto: [aqui](../README.md/#compiladores)

# Testando:
Para executar o programa faça a build da lista como descrito na sessão anterior e execute:
```bash
# Mode para o diretório de build
cd out/atividade-2-P2
./admin         # Testa o modulo admin
./user          # Testa o modulo user
./apuracao      # Testa o modulo apuracao
cd ../..        # Volta para o diretório inicial
```
É recomendado executar de dentro da pasta `out/atividade-2-P2`, pois serão criados
arquivos: `config.yml` e `contagem.csv`. Se executado de dentro da pasta de build
esses arquivos ficaram la dentro e não atrpalharão o diretório raiz.

Para apagar esses arquivos basta executar:
```bash
make clean
```
Assim, todos os arquivos dentro da pasta `out/` serão apagados.

## Exercícios
Criar dois programas em C que simulem uma eleição com dois módulos principais:
Administrador (configuração da eleição) e Usuário (votação e apuração).

Descrição da Tarefa
Você deverá implementar um programa, utilizando de funções para as diversas
tarefas, que simule um sistema de votação simples com as funcionalidades descritas abaixo.

- Deve-se entregar o código-fonte .c comentado em
arquivo texto que possa ser compilado pelo Dev C/C++.
- Incluir um exemplo de execução no final do arquivo (como
comentário).

Programa módulo Administrador: gerar um arquivo texto
contendo os seguintes dados:

- Solicitar o nome da eleição (ex: "Eleição para Representante de Turma"), data da votação.
- Perguntar o número de candidatos (mínimo 2, máximo 10).
- Para cada candidato, solicitar o nome completo.
- Armazenar os candidatos em uma estrutura apropriada (use struct).
- Gravar os dados em um arquivo com nome: eleição mês/ano

Programa Módulo Usuário (Votação): leia o arquivo texto que contém os dados da
eleição (nome da eleição e candidatos).

- Apresentar a lista de candidatos com seus respectivos números identificadores (ex: 1, 2, 3...).
- Permitir que os usuários votem digitando o número correspondente ao candidato.
- Permitir que a votação continue até o usuário desejar encerrar (ex: digitando 0 para encerrar).
- Armazenar os votos e totalizar para cada candidato.
- Validar para impedir votos inválidos.
- Mensagem de confirmação após cada voto.

Ao final da execução do módulo usuário:
Apuração dos Votos Após o encerramento da votação:

- Apresentar os dados da eleição: nome e data da votação.
- Mostrar o total de votos de cada candidato.
- Exibir a lista de candidatos ordenada por número de votos (do maior para o menor).
- Indicar o vencedor da eleição (em caso de empate, indicar todos os empatados em primeiro lugar).
