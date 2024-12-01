#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// estrutura enum para curso

typedef enum
{
    ADS = 1,
    CC,
    CD,
    GTI,
    RC,
    SI
} Curso;

typedef struct {
    char *nome;
    int rgm;
    Curso curso;
} Aluno;

Aluno *cadastro = NULL;
int totalAlunos = 0;

void mostrarCursos() {
    printf("Cursos disponiveis:\n");
    printf("1 - ANalise e Desenvolvimento de Sistemas\n");
    printf("2 - Ciencia da Computacao\n");
    printf("3 - Ciencia de Dados\n");
    printf("4 - Gestao da Tecnologia da Informacao\n");
    printf("5 - Redes de Computadores\n");
    printf("6 - Sistemas Para Internet\n");
}

const char *obterNomeCurso(Curso curso) {
    switch (curso) {
        case ADS: return "Analise e Desenvolvimento de Sistemas";
        case CC: return "Ciencia da Computacao";
        case CD: return "Ciencia de Dados";
        case GTI: return "Gestao da Tecnologia da Informacao";
        case RC: return "Redes de Computadores";
        case SI: return "Sistemas Para Internet";
        default: return "Curso desconhecido";
    }
}

void createAluno() {
    char buffer[1024];
    int rgm, cursoEscolhido;

    printf("\n--- Cadastro de Novo Aluno ---\n");

    printf("Digite o nome do aluno:");
    scanf(" %[^\n]", buffer);

    printf("Digite o RGM do aluno:");
    scanf("%d", &rgm);

    mostrarCursos();
    printf("Escolha o curso pelo numero correspondete:");
    scanf("%d", &cursoEscolhido);

    cadastro = (Aluno *) realloc(cadastro, (totalAlunos + 1) * sizeof(Aluno));

    if (cadastro == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }


    cadastro[totalAlunos].nome = (char *) malloc((strlen(buffer) + 1 ) * sizeof(char));
    strcpy(cadastro[totalAlunos].nome, buffer);
    cadastro[totalAlunos].rgm = rgm;
    cadastro[totalAlunos].curso = cursoEscolhido;

    totalAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
}

void readAlunos() {
    printf("\n---Lista de Alunos---\n");
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Rgm: %d\n", cadastro[i].rgm);
        printf("Curso: %s\n", cadastro[i].curso);
    }
}

void updateAluno() {
    int rgm, cursoEscolhido;
    char buffer[1024];

    printf("\n---Atualizar Cadastro---\n");
    printf("Digite o RGM do aluno a ser atualizado:");
    scanf("%d", &rgm);

    for (int i = 0; i < totalAlunos; i++) {
        if (cadastro[i].rgm == rgm) {
            printf("Aluno encontrado: %s\n", cadastro[i].nome);

            printf("Digite o novo nome do aluno:");
            scanf(" %[^\n]", buffer);
            free(cadastro[i].nome);
            cadastro[i].nome = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(cadastro[i].nome, buffer);


            // Atualiza Curso
        }
    }
}