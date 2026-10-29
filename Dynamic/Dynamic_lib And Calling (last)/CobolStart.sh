
#
#To run usage: source CobolStart.sh
#Uso dentro de terminal "MSYS2 UCRT64 COBOL"
#

clear

printf 'Started...\n'

printf 'Running [sourcecobenv.sh] to set Cobol environment...\n'

source cobenv.sh
$result=$?

#printf '[last:%d]\n' $result

if [[ $result -eq 0 ]]; then
#if [[  "$result" = "True" ]]; then
    printf '[source cobenv.sh] executed successfully...\n\n'
else
    printf '[source cobenv.sh] ERROR...\n\n'
fi

#Prompt: 
printf 'Set Prompt....\n'
unset PS1
#export PS1="\[\e[0m\]\$ "
export PS1="\[\e[32m\]\u@\h\[\e[0m\]:\$ "
##export PS1="\[\e[32m\]\u@\h \[\e[35m\]UCRT64\[\e[0m\] \[\e[33m\]\$\[\e[0m\] "
#printf "pwd\n\e[33m[%s]\e[0m\n\n" "$(pwd)"
printf 'Ready to Compile Cobol programs\n\n'