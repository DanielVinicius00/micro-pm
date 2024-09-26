#include <stdio.h>
#include <string.h>    // Para strcmp

// Protótipos de funções
int search_package(const char* package_name);
void read_options(const char* input, const char* package_name); // Corrigido aqui
void package_not_found(const char* name);

// Função para procurar o pacote em etc/sources.list
int search_package(const char* package_name){
    // Aqui você implementaria a lógica de procurar o pacote em /etc/sources.list
    // Simulação de busca de pacote
    if (strcmp(package_name, "example-package") == 0) {
        return 1;  // Pacote encontrado
    }
    return 0;      // Pacote não encontrado
}

// Ler a entrada do usuário
void read_options(const char* input, const char* package_name){
    if (strcmp(input, "-i") == 0 || strcmp(input, "install") == 0) {
        if (search_package(package_name)) {
            printf("Pacote %s encontrado e será instalado.\n", package_name);
            // Chame a função de instalação aqui
        } else {
            package_not_found(package_name);
        }
    } else {
        printf("Opção inválida: %s\n", input);
    }
}

// Função de erro: pacote não encontrado
void package_not_found(const char* name){
    printf("Pacote %s não encontrado!\n", name);
}

int main() {
    char input[50];
    char package_name[50];

    // Simulando a leitura da entrada do usuário
    scanf("%s", input);
    printf("Digite o nome do pacote: ");
    scanf("%s", package_name);

    // Ler as opções e processar o comando
    read_options(input, package_name);

    return 0;
}
