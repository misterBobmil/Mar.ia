#!/bin/bash

# Define a variável DIR_SCRIPT como o diretório do script
DIR_SCRIPT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Define o diretório do projeto como o diretório pai do diretório do script
DIR_PROJECT="$(dirname "$DIR_SCRIPT")"

# Executa o wrapper Gradle na pasta do projeto
"${DIR_PROJECT}/gradlew" "$@"
