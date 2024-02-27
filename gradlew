#!/bin/bash

# Define a variável DIR_SCRIPT como o diretório atual
DIR_SCRIPT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Executa o wrapper Gradle na pasta do projeto
"${DIR_SCRIPT}/gradle/wrapper/gradle-wrapper.jar" "$@"
