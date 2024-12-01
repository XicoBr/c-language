#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Escreva um programa em C, com alocação de memória totalmente dinâmica, para armazenar strings em uma matriz. Você deve capturar do teclado o tamanho da maior string a ser armazenada e as dimensões da matriz. Por exemplo, a maior string terá 124 caracteres e a matriz será de 4x5. */



int main() {
    int linhas, colunas, tamanhoString, i, j;
    char ***matriz; // Ponteiro triplo para armazenar as strings na matriz

    // Entrada das dimensões e do tamanho máximo da string
    printf("Digite o tamanho máximo de cada string: ");
    scanf("%d", &tamanhoString);

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Alocação dinâmica para a matriz
    matriz = (char ***)malloc(linhas * sizeof(char **));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        matriz[i] = (char **)malloc(colunas * sizeof(char *));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas.\n");
            return 1;
        }
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = (char *)malloc((tamanhoString + 1) * sizeof(char)); // +1 para o caractere nulo
            if (matriz[i][j] == NULL) {
                printf("Erro ao alocar memória para as strings.\n");
                return 1;
            }
        }
    }

    // Entrada das strings
    printf("Digite as strings para a matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf(" ");
            fgets(matriz[i][j], tamanhoString + 1, stdin);
            matriz[i][j][strcspn(matriz[i][j], "\n")] = '\0'; // Remove o caractere de nova linha
        }
    }

    // Exibição da matriz
    printf("\nMatriz de strings:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%s\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
