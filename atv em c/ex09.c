#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int *nrs, i, tamanho;

    // Solicita ao usuário o tamanho do array
    printf("Digite a quantidade de números a serem armazenados: ");
    scanf("%d", &tamanho);

    // Aloca dinamicamente o array
    nrs = (int *)malloc(tamanho * sizeof(int));
    if (nrs == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Entrada dos números
    for (i = 0; i < tamanho; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &nrs[i]);
    }

    // Exibe os números na ordem de entrada
    printf("\nNúmeros na ordem de entrada:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d\t", nrs[i]);
    }
    printf("\n");

    // Exibe os números na ordem inversa
    printf("Números na ordem inversa:\n");
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%d\t", nrs[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(nrs);

    return 0;
}
