#
#Objectivo:
# Abrir um terminal MSYS2 - ucrt64(C:\msys64\ucrt64.exe)
# e preparar o ambiente para COBOL executando "cobenv.sh"
#
#tecnica:
# - Adiciona os comandos entre # --- BEGIN COMMANDS --- e # --- END COMMANDS ---
# ao ".bashrc" do utilizador para um terminal MSYS2. "
# - ".bashrc" é executo automaticamente por cada abertura de terminal.
#
#Adicionamos comandos extra, nomeadamente "codbenv.sh".
#Depois ".bashrc" ser executado a ultima tarefa é limpar os comandos extra (que estão) entre
# --- BEGIN COMMANDS --- e # --- END COMMANDS ---
#Assim repoe a estrutura original do .bashrc.
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

printf 'Ready to Compile Cobol programs\n\n'

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
#(NOTA "Add-Content" adiciona crlf poromissão no final do ficheiro, -NoNewline nao coloca)
Add-Content -Path $bashrcPath -Value $linesToAppend -NoNewline   

# 5. Start terminal normalmente (exceute .bashrc and rest opened!)
Start-Process "C:\msys64\ucrt64.exe"

# run -> source cobenv.sh
