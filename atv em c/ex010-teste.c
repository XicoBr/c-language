#include <stdio.h>
#include <string.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Portuguese");

    int linhas, colunas, tamanhoString, i, j;
    char ***matriz; // aponta para um array de ponteiros, muito util para trabalhar com matrizes
    
    printf("Digite o tamanho máximo de caracteres da string: ");
    scanf("%d", &tamanhoString);

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = (char ***)malloc(linhas * sizeof(char **));


    // alocando memória para as linhas e colunas
    if (matriz == NULL){
        printf("Erro ao alocar memória para as colunas.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        matriz[i] = (char **)malloc(colunas * sizeof(char *));

        for (j = 0; j < colunas; j++) {
            matriz[i][j] = (char *)malloc((tamanhoString + 1) * sizeof(char));
            if (matriz[i][j] == NULL){
                printf("Erro ao alocar memória para as strings.\n");
                return 1;
            }           
        }
    }
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    // Entrada das strings
    printf("Digite as strings para a matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            /*  Usa-se scanf(" ") para que ele consuma e ignore qualquer caractere de espaço em branco antes de fazer a próxima leitura de input, para que não existam resíduos de buffer de entrada(stdin) deixados por operações anteriores. 
                Isso inclui espaços, tabs e caracteres de nova linha.   	*/
            scanf(" ");
            fgets(matriz[i][j], tamanhoString + 1, stdin);
            matriz[i][j][strcspn(matriz[i][j], "\n")] = '\0';  // remove caractere de nova linha
        }
    }

    // Exibindo a matriz
    printf("\nMatriz de Strings:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%s\t", matriz[i][j]);
        }
        printf("\n");
    }
}