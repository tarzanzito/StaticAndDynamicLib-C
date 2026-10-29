
#
# Objectivo: Este script abre o terminal MSYS2 (C:\msys64\ucrt64.exe) e corre de imediato "cobenv.sh (COBOL)
#
#Este script é para ser executado no PowerShell do Windows, e tem como objetivo abrir o terminal MSYS2
# e executar o ficheiro cobenv.sh (que configura o ambiente de desenvolvimento Cobol) automaticamente.
#Adiciona os comandos entre # --- BEGIN COMMANDS --- e # --- END COMMANDS ---
#Ao .bashrc  do utilizador no MSYS2, para que sejam executados sempre que o terminal for aberto.
#Depois bashrc é limpo para não executar novamente na próxima vez que o terminal for aberto. 
#Repoe a estrutura original do .bashrc.
#

$currentDir = Get-Location
# 1. Obtem as pastas (formato Windows em formato MSYS2)
$msysDir = $currentDir.Path -replace '^([A-Za-z]):', '/$1' -replace '\\', '/'

# 2. Caminho para o ficheiro .bashrc do teu utilizador no MSYS2
$bashrcPath = "C:\msys64\home\$env:USERNAME\.bashrc"

# If ".bashrc" not exist then create for resolve errors
if (-not (Test-Path $bashrcPath))
{
     New-Item -ItemType File -Path $bashrcPath -Force
}

# 3. Commands inside ".bashrc" (commands after start terminal)
$linesToAppend = @"
# --- BEGIN COMMANDS ---

printf 'Started...\n\n'
cd '$msysDir'

printf 'Running [sourcecobenv.sh] to set Cobol environment...\n\n'

source cobenv.sh

#if [ $? -eq 0 ]; then
if [  "$?" = "True" ]; then
    printf '\n[source cobenv.sh] executed successfully...\n\n'
else
    printf '\n[source cobenv.sh] ERROR...\n\n'
fi

#Prompt: 
unset PS1
#export PS1="\[\e[0m\]\$ "
export PS1="\[\e[0m\]:\$ "
#export PS1="\[\e[32m\]\u@\h\[\e[0m\]:\$ "
#export PS1="\[\e[32m\]\u@\h \[\e[35m\]UCRT64\[\e[0m\] \[\e[33m\]\$\[\e[0m\] "

printf "pwd\n\e[33m[%s]\e[0m\n\n" "$(pwd)"

# Remove este proprio bloco para nao correr nas proximas vezes que se abrir o terminal
#sed -i '/# --- BEGIN COMMANDS ---/,/# --- END COMMANDS ---/d' ~/.bashrc 
sed -i -e '/# --- BEGIN COMMANDS ---.*/,/# --- END COMMANDS ---.*/d' ~/.bashrc 
# OBRIGATORIO comentario ou newline, sed passa-se sem esta linha (a razao desconheco)
# --- END COMMANDS ---
"@ 

#write-host $bashrcPath
##C:\msys64\home\Paulo\.bashrc
#Read-Host "ENTER para continuar"
#write-host  $linesToAppend
#Read-Host "ENTER para continuar"

# 4. Add commands at end end of .bashrc
#(NOTA Add-Content adiciona crlf no final do ficheiro, se nao quiseres usa -NoNewline)
Add-Content -Path $bashrcPath -Value $linesToAppend -NoNewline   

# 5. Start terminal normalmente (exceute .bashrc and rest opened!)
Start-Process "C:\msys64\ucrt64.exe"

# run -> source cobenv.sh
