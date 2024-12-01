#include <stdio.h>
#include <string.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int i, tamanho, *ptr_nmr;
    
    printf("Digite o total de numeros a serem armazenados: ");
    scanf("%d", &tamanho);

    ptr_nmr = (int*) malloc(tamanho * sizeof(int));


    printf("Tamanho do array: %d\n", tamanho);

    printf("Array na ordem normal: \n");
    for (i = 0; i < tamanho; i++) {
        printf("Digite o %do. numero: ", i + 1);
        scanf("%d", &ptr_nmr[i]);
    }
    printf("\n");

    printf("Array na ordem inversa: \n");
    for (i = tamanho - 1; i >= 0; i --) {
        printf("%d \n", ptr_nmr[i]);
    }
    
    printf("\n");
    printf("Tamanho do ponteiro: %zu\n", sizeof(ptr_nmr) * tamanho);
    free(ptr_nmr);
    return 0;
}   




