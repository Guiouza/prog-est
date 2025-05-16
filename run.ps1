# Define o diretório de origem dos arquivos .c
$diretorioFonte = "src"

# Solicita o nome do arquivo .c ao usuário
$nomeArquivoC = Read-Host "Digite o nome do arquivo .c (ex: meu_codigo.c)"

# Define o nome do arquivo de saída (sem a extensão .c)
$nomeArquivoBase = [System.IO.Path]::GetFileNameWithoutExtension($nomeArquivoC)

# Define o diretório de saída para o executável
$diretorioSaida = "out"

# Cria o diretório de saída se ele não existir
if (-not (Test-Path -Path $diretorioSaida -PathType Container)) {
    Write-Host "Criando o diretório de saída: '$diretorioSaida'"
    New-Item -Path $diretorioSaida -ItemType Directory | Out-Null
}

# Define o caminho completo para o arquivo .c dentro do diretório src
$caminhoArquivoC = Get-Location | Join-Path -ChildPath "$diretorioFonte/$nomeArquivoC"

# Define o caminho completo para o arquivo executável de saída
$caminhoArquivoExe = Join-Path -Path $diretorioSaida -ChildPath "$nomeArquivoBase.exe"
$caminhoArquivoObj = Join-Path -Path $diretorioSaida -ChildPath "$nomeArquivoBase.obj"

# Verifica se o diretório src existe
if (-not (Test-Path -Path $diretorioFonte -PathType Container)) {
    Write-Error "Erro: O diretório de origem '$diretorioFonte' não foi encontrado."
    exit 1
}

# Verifica se o arquivo .c existe dentro do diretório src
if (-not (Test-Path -Path $caminhoArquivoC -PathType Leaf)) {
    Write-Error "Erro: O arquivo '$caminhoArquivoC' não foi encontrado."
    exit 1
}

# Tenta encontrar o compilador cl.exe (ferramentas do Visual Studio)
$clPath = Get-Command cl.exe -ErrorAction SilentlyContinue

if (-not $clPath) {
    Write-Error "Erro: O compilador 'cl.exe' não foi encontrado. Certifique-se de que o 'Visual C++ Build Tools' esteja instalado e no seu PATH."
    Write-Host "Você pode precisar executar o 'Developer Command Prompt for VS' ou configurar as variáveis de ambiente."
    exit 1
}

# Comando para compilar o arquivo .c
$comandoCompilacao = "$clPath /Zi /EHsc /nologo /Fo:`"$caminhoArquivoObj`" /Fe:`"$caminhoArquivoExe`" `"$caminhoArquivoC`""

Write-Host "Compilando: '$caminhoArquivoC' -> '$caminhoArquivoExe'"

# Executa o comando de compilação
try {
    Invoke-Expression $comandoCompilacao
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Erro durante a compilação. Código de saída: $($LASTEXITCODE)"
        exit $LASTEXITCODE
    }
}
catch {
    Write-Error "Erro ao executar o comando de compilação: $_"
    exit 1
}

# Define o caminho completo para o executável a ser executado
$caminhoExecutavel = $caminhoArquivoExe

# Executa o arquivo .exe
Write-Host "Executando: '$caminhoExecutavel'"
Start-Process -FilePath $caminhoExecutavel