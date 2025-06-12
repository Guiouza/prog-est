# prog-est
Esse projeto foi criado para armazenar as soluções dos exercícios do curso 2179SMB Programação Estruturada da turma de 2025 do campus IBILCE.

## Arquivos

| Listas e Aulas | Diretório |
| :- | :- |
| Lista - 1 | [src/atividades/lista-1/](docs/lista-1.md) |
| Lista - 2 | [src/atividades/lista-2/](docs/lista-2.md) |
| Lista - 3 | [src/atividades/lista-3/](docs/lista-3.md) |
| Atividade - 1 P2 | [src/atividades/atividade-1-P2/](docs/atividade-1-P2.md) |
| Atividade - 2 P2 | [src/atividades/atividade-2-P2/](docs/atividade-2-P2.md) |
| Atividade - 3 P2 | [src/atividades/atividade-3-P2/](docs/atividade-3-P2.md) |
| Atividade - 5 P2 | [src/atividades/atividade-5-P2/](docs/atividade-5-P2.md) |
| Atividade - 6 P2 | [src/atividades/atividade-6-P2/](docs/atividade-6-P2.md) |

## Sobre o DEV-C++
Não recomendo o uso dessa IDE, é possível utilizá-la sim para abrir os arquivos `.c` e compilálos individualmente. Mas há problemas quanto ao uso de caracteres utf-8 e sobre a versão do C11 e C99 que eu não sei como resolver.

### Alternativas:
Eu recomendo a utilização do Visual Studio Code (Em ambos Windows e Linux) ou do Visual Studio (em ambiente Windows), ambos da Microsoft.

[<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/vscode/vscode-original.svg" height=50/>](https://code.visualstudio.com/download)
*Clique para instalar o VS Code*

### Compiladores:

**Em Linux:** Utilize o pacote [build-essentials](https://packages.debian.org/pt-br/sid/build-essential) com o gcc e a ferramente make para compilar o projeto como foi pensado para ser feito.

```sh
# Instalando o pacote build-essentials
sudo apt install build-essentials
```

**Em Windows:** Utilize o Microsoft MSVC. É possível utilizá-lo integradamente no Visual Studio ou pelo terminal de desevolvedor com o Visual Studio Code.

Leia o artigo sobre MSVC no Visual Studio Code: <https://code.visualstudio.com/docs/cpp/config-msvc#_prerequisites>.

```pwsh
# Instalando o MSVC sem o Visual Studio (Recomendado quando utilizar o VS Code)
winget install Microsoft.VisualStudio.2022.BuildTools --force --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows11SDK.26100"
```

## Build

### Utilizando GCC e Make

O projeto contra com um Makefile para compilar os exercícios. Basta executar o comando:

```sh
make <nome_da_lista_de_exercicios>
```

Por exemplo, o comando `make lista-1` compila os exercícios da lista-1.
Cada lista tem uma documentação com as instruções próprias para compilação e execução.
Veja o link da lista a qual queira testar [aqui](#arquivos).

> [!WARNING]
> É necessário ter instalado o compilador [GCC](https://gcc.gnu.org/install/) e a ferramenta [make](https://www.gnu.org/software/make/) acessível no terminal. O DEV-C++ apesar de instalar essas ferramentar, não as disponibiliza pelo terminal.

### Utilizando o VS Code e MSVC

Abra o Developer Command Prompt ou o Developer Power Shell na pasta do projeto.
O pacote do MSVC não possui a ferramenta `make`, então é necessário compilar os programar manualmente.

```pwsh
cl src\atividades\<atividade>\<arquivo>.c src\atividades\lib\*.c /Isrc\lib /Foout\<atividade>\<executavel>
```

Novamente, cada lista tem uma documentação com as instruções próprias para compilação e execução.
Veja o link da lista a qual queira testar [aqui](#arquivos).
