#!/bin/bash

# Solicita o nome do arquivo .c ao usuário
read -p "Digite o nome do arquivo .c (ex: meu_codigo.c): " nomeArquivoC

# Define o nome do arquivo de saída (sem a extensão .c)
nomeArquivoBase=$(basename "$nomeArquivoC" .c)

# Define o diretório de saída para o executável
diretorioSaida="out"

# Cria o diretório de saída se ele não existir
if [ ! -d "$diretorioSaida" ]; then
  echo "Criando o diretório de saída: '$diretorioSaida'"
  mkdir -p "$diretorioSaida"
fi

# Define o caminho completo para o arquivo .c
caminhoArquivoC=$(pwd)/src/"$nomeArquivoC"

# Define o caminho completo para o arquivo executável de saída
caminhoArquivoExe="$diretorioSaida/$nomeArquivoBase"

# Verifica se o arquivo .c existe
if [ ! -f "$caminhoArquivoC" ]; then
  echo "Erro: O arquivo '$caminhoArquivoC' não foi encontrado." >&2
  exit 1
fi

# Comando para compilar o arquivo .c usando gcc
comandoCompilacao="gcc \"$caminhoArquivoC\" -o \"$caminhoArquivoExe\""

echo "Compilando: '$caminhoArquivoC' -> '$caminhoArquivoExe'"

# Executa o comando de compilação
eval "$comandoCompilacao"

# Verifica o código de saída da compilação
if [ $? -ne 0 ]; then
  echo "Erro durante a compilação." >&2
  exit $?
fi

# Define o caminho completo para o executável a ser executado
caminhoExecutavel="./$caminhoArquivoExe"

# Executa o arquivo .exe
echo "Executando: '$caminhoExecutavel'"
"$caminhoExecutavel"