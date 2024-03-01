#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

// Diretório restrito para a IA
const string DIRETORIO_ARQUIVOS = "diretorio_restrito";

// Função para restringir acesso ao diretório restrito
void restringir_acesso() {
    try {
        mkdir(DIRETORIO_ARQUIVOS.c_str(), 0700);  // Permissões: Somente o proprietário pode ler, escrever e acessar
    } catch (const exception& e) {
        cout << "Erro ao restringir o acesso ao diretório: " << e.what() << endl;
    }
}

// Função para criar uma nova pasta dentro do diretório de arquivos restrito
string criar_nova_pasta(string nome_pasta) {
    string nova_pasta = DIRETORIO_ARQUIVOS + "/" + nome_pasta;
    mkdir(nova_pasta.c_str(), 0700);
    return nova_pasta;
}

// Função para criar um novo arquivo dentro de uma pasta específica
void criar_novo_arquivo(string nome_arquivo, string conteudo, string pasta = "") {
    string caminho_arquivo;
    if (!pasta.empty()) {
        caminho_arquivo = DIRETORIO_ARQUIVOS + "/" + pasta + "/" + nome_arquivo;
    } else {
        caminho_arquivo = DIRETORIO_ARQUIVOS + "/" + nome_arquivo;
    }
    ofstream arquivo(caminho_arquivo);
    if (arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
    } else {
        cout << "Erro ao criar o arquivo: " << caminho_arquivo << endl;
    }
}

// Função para listar todos os arquivos e pastas dentro de uma pasta específica do diretório de arquivos restrito
vector<string> listar_arquivos_e_pastas(string pasta = "") {
    string caminho_pasta;
    if (!pasta.empty()) {
        caminho_pasta = DIRETORIO_ARQUIVOS + "/" + pasta;
    } else {
        caminho_pasta = DIRETORIO_ARQUIVOS;
    }
    vector<string> conteudo_pasta;
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(caminho_pasta.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            conteudo_pasta.push_back(ent->d_name);
        }
        closedir(dir);
    } else {
        cout << "Erro ao listar a pasta: " << caminho_pasta << endl;
    }
    return conteudo_pasta;
}

// Função para mover um arquivo ou pasta para um novo local dentro do diretório de arquivos restrito
void mover_arquivo_ou_pasta(string origem, string destino) {
    string origem_path = DIRETORIO_ARQUIVOS + "/" + origem;
    string destino_path = DIRETORIO_ARQUIVOS + "/" + destino;
    if (rename(origem_path.c_str(), destino_path.c_str()) != 0) {
        cout << "Erro ao mover o arquivo ou pasta." << endl;
    }
}

// Função para deletar um arquivo ou pasta do diretório de arquivos restrito
void deletar_arquivo_ou_pasta(string arquivo_ou_pasta) {
    string caminho = DIRETORIO_ARQUIVOS + "/" + arquivo_ou_pasta;
    if (remove(caminho.c_str()) != 0) {
        cout << "Erro ao deletar o arquivo ou pasta." << endl;
    }
}

// Função para limpar uma pasta específica do diretório de arquivos restrito (deleta todos os arquivos e pastas dentro dela)
void limpar_pasta(string pasta) {
    string caminho_pasta = DIRETORIO_ARQUIVOS + "/" + pasta;
    vector<string> conteudo_pasta = listar_arquivos_e_pastas(pasta);
    for (const string& arquivo : conteudo_pasta) {
        string caminho_arquivo = caminho_pasta + "/" + arquivo;
        if (remove(caminho_arquivo.c_str()) != 0) {
            cout << "Erro ao deletar o arquivo: " << caminho_arquivo << endl;
        }
    }
}

// Função principal
int main() {
    cout << "Bem-vindo ao sistema de gerenciamento de arquivos da IA!" << endl;
    cout << "Por favor, escolha uma das opções abaixo:" << endl;
    cout << "Opções:" << endl;
    cout << "- criar_pasta: Criar uma nova pasta" << endl;
    cout << "- listar: Listar arquivos e pastas" << endl;
    cout << "- mover: Mover um arquivo ou pasta" << endl;
    cout << "- deletar: Deletar um arquivo ou pasta" << endl;
    cout << "- limpar: Limpar uma pasta (deletar todos os arquivos e pastas dentro dela)" << endl;

    while (true) {
        string comando;
        cout << "\nDigite o comando desejado ou 'sair' para encerrar: ";
        getline(cin, comando);
        if (comando == "sair") {
            cout << "Até logo!" << endl;
            break;
        } else if (comando == "criar_pasta") {
            // Chamar a função para criar pasta
        } else if (comando == "listar") {
            // Chamar a função para listar arquivos e pastas
        } else if (comando == "mover") {
            // Chamar a função para mover arquivo ou pasta
        } else if (comando == "deletar") {
            // Chamar a função para deletar arquivo ou pasta
        } else if (comando == "limpar") {
            // Chamar a função para limpar pasta
        } else {
            cout << "Comando inválido." << endl;
        }
    }

    return 0;
}
