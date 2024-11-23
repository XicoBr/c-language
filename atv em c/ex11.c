#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do ENUM para os cursos
typedef enum {
    ADS = 1,
    CC,
    CD,
    GTI,
    RC,
    SI
} Curso;

// Estrutura para armazenar os dados de cada aluno
typedef struct {
    char *nome; // Nome completo (alocado dinamicamente)
    int rgm;    // RGM
    Curso curso; // Curso (ENUM)
} Aluno;

// Variáveis globais para o cadastro de alunos
Aluno *cadastro = NULL;
int totalAlunos = 0;

// Funções auxiliares
void mostrarCursos() {
    printf("Cursos disponíveis:\n");
    printf("1 - Análise e Desenvolvimento de Sistemas\n");
    printf("2 - Ciência da Computação\n");
    printf("3 - Ciência de Dados\n");
    printf("4 - Gestão da Tecnologia da Informação\n");
    printf("5 - Redes de Computadores\n");
    printf("6 - Sistemas Para Internet\n");
}

const char *obterNomeCurso(Curso curso) {
    switch (curso) {
        case ADS: return "Análise e Desenvolvimento de Sistemas";
        case CC: return "Ciência da Computação";
        case CD: return "Ciência de Dados";
        case GTI: return "Gestão da Tecnologia da Informação";
        case RC: return "Redes de Computadores";
        case SI: return "Sistemas Para Internet";
        default: return "Curso desconhecido";
    }
}

// Função para criar um novo aluno
void createAluno() {
    char buffer[1024];
    int rgm, cursoEscolhido;

    printf("\n--- Cadastro de Novo Aluno ---\n");

    // Coleta do nome
    printf("Digite o nome completo do aluno: ");
    scanf(" %[^\n]", buffer);
    
    // Coleta do RGM
    printf("Digite o RGM do aluno: ");
    scanf("%d", &rgm);

    // Exibição dos cursos e coleta do curso escolhido
    mostrarCursos();
    printf("Escolha o curso pelo número correspondente: ");
    scanf("%d", &cursoEscolhido);

    // Aloca mais espaço para o novo aluno
    cadastro = (Aluno *)realloc(cadastro, (totalAlunos + 1) * sizeof(Aluno));
    if (cadastro == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Armazena os dados do novo aluno
    cadastro[totalAlunos].nome = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(cadastro[totalAlunos].nome, buffer);
    cadastro[totalAlunos].rgm = rgm;
    cadastro[totalAlunos].curso = cursoEscolhido;

    totalAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
}

// Função para listar todos os alunos
void readAlunos() {
    printf("\n--- Lista de Alunos ---\n");
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nome: %s\n", cadastro[i].nome);
        printf("  RGM: %d\n", cadastro[i].rgm);
        printf("  Curso: %s\n", obterNomeCurso(cadastro[i].curso));
    }
}

// Função para atualizar os dados de um aluno
void updateAluno() {
    int rgm, cursoEscolhido;
    char buffer[1024];

    printf("\n--- Atualizar Aluno ---\n");
    printf("Digite o RGM do aluno a ser atualizado: ");
    scanf("%d", &rgm);

    for (int i = 0; i < totalAlunos; i++) {
        if (cadastro[i].rgm == rgm) {
            printf("Aluno encontrado: %s\n", cadastro[i].nome);

            // Atualiza o nome
            printf("Digite o novo nome do aluno: ");
            scanf(" %[^\n]", buffer);
            free(cadastro[i].nome); // Libera a memória do nome antigo
            cadastro[i].nome = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(cadastro[i].nome, buffer);

            // Atualiza o curso
            mostrarCursos();
            printf("Escolha o novo curso pelo número correspondente: ");
            scanf("%d", &cursoEscolhido);
            cadastro[i].curso = cursoEscolhido;

            printf("Dados do aluno atualizados com sucesso!\n");
            return;
        }
    }
    printf("Aluno com RGM %d não encontrado.\n", rgm);
}

// Função para excluir um aluno
void deleteAluno() {
    int rgm;

    printf("\n--- Excluir Aluno ---\n");
    printf("Digite o RGM do aluno a ser excluído: ");
    scanf("%d", &rgm);

    for (int i = 0; i < totalAlunos; i++) {
        if (cadastro[i].rgm == rgm) {
            // Libera a memória do nome do aluno
            free(cadastro[i].nome);

            // Remove o aluno do cadastro
            for (int j = i; j < totalAlunos - 1; j++) {
                cadastro[j] = cadastro[j + 1];
            }
            totalAlunos--;
            cadastro = (Aluno *)realloc(cadastro, totalAlunos * sizeof(Aluno));
            printf("Aluno excluído com sucesso!\n");
            return;
        }
    }
    printf("Aluno com RGM %d não encontrado.\n", rgm);
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: createAluno(); break;
            case 2: readAlunos(); break;
            case 3: updateAluno(); break;
            case 4: deleteAluno(); break;
            case 5: printf("Encerrando o programa.\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    // Libera a memória antes de encerrar o programa
    for (int i = 0; i < totalAlunos; i++) {
        free(cadastro[i].nome);
    }
    free(cadastro);

    return 0;
}
