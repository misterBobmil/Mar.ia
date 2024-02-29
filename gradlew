#!/bin/bash

# Define a variável DIR_SCRIPT como o diretório do script
DIR_SCRIPT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Define o diretório do projeto como o diretório pai do diretório do script
DIR_PROJECT="$(dirname "$DIR_SCRIPT")"

# Caminho para o gradle-wrapper.jar
WRAPPER_JAR="${DIR_PROJECT}/gradle/wrapper/gradle-wrapper.jar"

# Verifica se o gradle-wrapper.jar existe e é executável
if [[ -f "$WRAPPER_JAR" ]] && [[ -x "$WRAPPER_JAR" ]]; then
    # Executa o wrapper Gradle na pasta do projeto
    java -jar "$WRAPPER_JAR" "$@"
else
    echo "Erro: O arquivo gradle-wrapper.jar não foi encontrado ou não é executável."
    echo "Verifique se o arquivo está presente em $WRAPPER_JAR e tente novamente."
fi
