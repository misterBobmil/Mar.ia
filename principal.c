#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>  
#include <sys/stat.h> 
#include <ctype.h> 

#define DIRETORIO_ARQUIVOS "diretorio_restrito"

char* criar_nova_pasta(char* nome_pasta) {
    char* nova_pasta = malloc(strlen(DIRETORIO_ARQUIVOS) + strlen(nome_pasta) + 2); 
    sprintf(nova_pasta, "%s/%s", DIRETORIO_ARQUIVOS, nome_pasta);
    mkdir(nova_pasta, 0700);
    return nova_pasta;
}

void criar_novo_arquivo(char* nome_arquivo, char* conteudo, char* pasta) {
    char caminho_arquivo[strlen(DIRETORIO_ARQUIVOS) + strlen(pasta) + strlen(nome_arquivo) + 3]; 
    if (pasta != NULL) {
        sprintf(caminho_arquivo, "%s/%s/%s", DIRETORIO_ARQUIVOS, pasta, nome_arquivo);
    } else {
        sprintf(caminho_arquivo, "%s/%s", DIRETORIO_ARQUIVOS, nome_arquivo);
    }
    FILE* arquivo = fopen(caminho_arquivo, "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s", conteudo);
        fclose(arquivo);
    } else {
        printf("Erro ao criar o arquivo: %s\n", caminho_arquivo);
    }
}

char** listar_arquivos_e_pastas(char* pasta) {
    char caminho_pasta[strlen(DIRETORIO_ARQUIVOS) + strlen(pasta) + 2]; 
    if (pasta != NULL) {
        sprintf(caminho_pasta, "%s/%s", DIRETORIO_ARQUIVOS, pasta);
    } else {
        sprintf(caminho_pasta, "%s", DIRETORIO_ARQUIVOS);
    }
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(caminho_pasta)) != NULL) {
        int contador = 0;
        char** conteudo_pasta = malloc(100 * sizeof(char*)); 
        while ((ent = readdir(dir)) != NULL) {
            conteudo_pasta[contador] = malloc(strlen(ent->d_name) + 1); 
            strcpy(conteudo_pasta[contador], ent->d_name);
            contador++;
        }
        closedir(dir);
        return conteudo_pasta;
    } else {
        printf("Erro ao listar a pasta: %s\n", caminho_pasta);
        return NULL;
    }
}

void mover_arquivo_ou_pasta(char* origem, char* destino) {
    char origem_path[strlen(DIRETORIO_ARQUIVOS) + strlen(origem) + 2]; 
    char destino_path[strlen(DIRETORIO_ARQUIVOS) + strlen(destino) + 2]; 
    sprintf(origem_path, "%s/%s", DIRETORIO_ARQUIVOS, origem);
    sprintf(destino_path, "%s/%s", DIRETORIO_ARQUIVOS, destino);
    if (rename(origem_path, destino_path) != 0) {
        printf("Erro ao mover o arquivo ou pasta.\n");
    }
}

void deletar_arquivo_ou_pasta(char* arquivo_ou_pasta) {
    char caminho[strlen(DIRETORIO_ARQUIVOS) + strlen(arquivo_ou_pasta) + 2]; 
    sprintf(caminho, "%s/%s", DIRETORIO_ARQUIVOS, arquivo_ou_pasta);
    if (remove(caminho) != 0) {
        printf("Erro ao deletar o arquivo ou pasta.\n");
    }
}

void limpar_pasta(char* pasta) {
    char caminho_pasta[strlen(DIRETORIO_ARQUIVOS) + strlen(pasta) + 2]; 
    sprintf(caminho_pasta, "%s/%s", DIRETORIO_ARQUIVOS, pasta);
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(caminho_pasta)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char caminho_arquivo[strlen(caminho_pasta) + strlen(ent->d_name) + 2]; 
                sprintf(caminho_arquivo, "%s/%s", caminho_pasta, ent->d_name);
                if (remove(caminho_arquivo) != 0) {
                    printf("Erro ao deletar o arquivo: %s\n", caminho_arquivo);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Erro ao listar a pasta: %s\n", caminho_pasta);
    }
}

void salvar_estado() {
    FILE* arquivo = fopen("estado_conversa.txt", "w");
    if (arquivo != NULL) {
        // Implementação da função para salvar o estado da IA
        fclose(arquivo);
    } else {
        printf("Erro ao salvar o estado da conversa.\n");
    }
}

void buscar_aprendizado() {
    // Implementação da função para buscar aprendizado pela internet
}

void pesquisar_avaliar_api() {
    // Implementação da função para pesquisar e avaliar APIs relevantes
}

void enviar_notificacao(char* mensagem) {
    // Aqui você pode implementar a lógica para enviar uma notificação para você (por email, mensagem de texto, etc.)
    printf("Notificação enviada: %s\n", mensagem);
}

int integrar_nova_api(char* api_info) {
    char permissao;
    printf("Deseja integrar a API %s? (s/n): ", api_info);
    scanf(" %c", &permissao);
    if (tolower(permissao) == 's') {
        // Aqui você pode adicionar a lógica para integrar a API ao seu sistema
        printf("API %s integrada com sucesso!\n", api_info);
        return 1; // verdadeiro
    } else {
        printf("Integração da API cancelada pelo usuário.\n");
        return 0; // falso
    }
}

void coletar_feedback() {
    char feedback[1000];
    printf("Por favor, forneça seu feedback: ");
    scanf("%*c"); // Consumindo a nova linha deixada pelo scanf anterior
    fgets(feedback, sizeof(feedback), stdin);
    // Aqui você pode adicionar a lógica para processar e registrar o feedback do usuário
    printf("Feedback registrado com sucesso!\n");
}

int main() {
    printf("Bem-vindo ao sistema de gerenciamento de arquivos da IA!\n");
    printf("Por favor, escolha uma das opções abaixo:\n");
    printf("Opções:\n");
    printf("- criar_pasta: Criar uma nova pasta\n");
    printf("- listar: Listar arquivos e pastas\n");
    printf("- mover: Mover um arquivo ou pasta\n");
    printf("- deletar: Deletar um arquivo ou pasta\n");
    printf("- limpar: Limpar uma pasta (deletar todos os arquivos e pastas dentro dela)\n");
    printf("- buscar_aprendizado: Buscar ativamente aprendizado pela internet\n");
    printf("- pesquisar_avaliar_api: Pesquisar e avaliar APIs relevantes\n");

    while (1) {
        char comando[50];
        printf("\nDigite o comando desejado ou 'sair' para encerrar: ");
        scanf("%s", comando);
        if (strcmp(comando, "sair") == 0) {
            printf("Até logo!\n");
            break;
        } else if (strcmp(comando, "criar_pasta") == 0) {
            criar_nova_pasta(NULL);
        } else if (strcmp(comando, "listar") == 0) {
            listar_arquivos_e_pastas(NULL);
        } else if (strcmp(comando, "mover") == 0) {
            mover_arquivo_ou_pasta(NULL, NULL);
        } else if (strcmp(comando, "deletar") == 0) {
            deletar_arquivo_ou_pasta(NULL);
        } else if (strcmp(comando, "limpar") == 0) {
            limpar_pasta(NULL);
        } else if (strcmp(comando, "buscar_aprendizado") == 0) {
            buscar_aprendizado();
        } else if (strcmp(comando, "pesquisar_avaliar_api") == 0) {
            pesquisar_avaliar_api();
        } else {
            printf("Comando inválido.\n");
        }
    }

    // Salvar o estado da IA
    salvar_estado();

    return 0;
}
