#include <stdio.h> // Biblioteca de comunicação com usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings

int registro() { // Função por cadastrar os usuários no sistema
    // Ínicio de criação de variáveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis

    printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuário
    scanf("%s", cpf); // "%s" refere-se a string

    strcpy(arquivo, cpf); // Reponsável por copiar os valores das strings

    FILE * file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo
    fprintf(file, cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // "a" serve para dizer que estamos atualizando o arquivo
    fprintf(file, ", "); // "Escrevendo uma vírgula no arquivo"
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause"); 
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE * file;
    file = fopen(cpf, "r"); // "r" vai ler o arquivo

    if (file) {
        // fgets: busca o arquivo e vai escrever todos do mesmo na variável conteudo, buscando até 200 char
        while (fgets(conteudo, 200, file) != NULL) { // Enquanto o dado não for nulo, o laço se repetirá
            printf("\nInformações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
    } else {
        printf("Esse CPF não existe\n");
    }

    
    system("pause");

}

int deletar() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE * file;
    file = fopen(cpf, "r"); // Abrindo o arquivo para conferir se ele existe

    if (file) {
        fclose(file); // Fechando o arquivo antes de deletar
        remove(cpf); // Deleta o arquivo que tenha o nome igual da variável cpf
        printf("Usuário removido com sucesso\n");
    } else {
        printf("Esse CPF não existe\n");
    }

    system("pause");
    
}

int invalido() {
    printf("Essa opção não está disponível\n");
    system("pause");
}

int main() { 
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    int opcao = 0; //Definindo a variável como número inteiro
    int laco = 1; //Definindo a variável como número inteiro
    char senha[10] = ""; //Definindo variável de senha
    int comparacao; //Definindo a variável para validar a senha

    printf("### Cartório da EBAC ###\n\n"); //Ínicio do menu
    printf("Login de administrador\n\nDigite a sua senha: ");
    scanf("%s", senha); 

    comparacao = strcmp(senha, "admin"); // Para comparar strings é necessário utilizar a função strcmp()

    if (comparacao == 0) { // O parâmetro é "comparacao == 0" porque se a validação foi verdadeira, vai retornar 0
        for (laco = 1;  laco = 1;) {
            system("cls");

            printf("### Cartório da EBAC ###\n\n"); //Ínicio do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n\n"); //Fim do menu
            printf("Opção: ");

            scanf("%d", &opcao); //Aloca a informação digitada pelo usuário na variável opcao

            system("cls"); //Deleta todas as informações do terminal

            switch(opcao) { //Ínicio da seleção do menu
                case 1: 
                    registro(); // Chamada de funções
                    break;
                case 2:
                    consulta();
                    break;
                case 3:
                    deletar();
                    break;
                case 4:
                    printf("Finalizando o sistema...");
                    return 0;
                    break;
                default:
                    invalido();
                    break;
            } //Fim da seleção
        }
    } else {
        printf("\nSenha incorreta");
    }
}
