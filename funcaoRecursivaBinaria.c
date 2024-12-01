#include <stdio.h>

/* PARA ESTE EXEMPLO DE BUSCA BINÁRIA, OS NÚMEROS PRECISAM ESTAR ORDENADOS EM ORDEM CRESCENTE */

int bSearch(int array[], int start, int end, int element){
    // condicao base para continuar a funcao
    if (end >= start) {
        // define a posicao do elemento central 
        int mid = start + (end - start) / 2;
        
        // imprime a posicao do elemento central(debug apenas)
        printf("Mid = %d\n", mid);
        
        // se o elemento central for igual ao elemento procurado, retorna a posicao
        if (array[mid] == element) {
            return mid;
        

        // se o elemento central for menor que o elemento procurado, procura na metade esquerda
            if (array[mid] > element) {
                return bSearch(array, start, mid - 1, element);            
        
        // se o elemento central for maior que o elemento procurado, procura na metade direita
            } else {
                return bSearch(array, mid + 1, end, element);
            }
        }
    return -1;  // retorna caso elemento nao encontrado
    }
}

int main(void) {
    int array[] = {5, 12, 23, 45, 49, 67, 71, 77, 82};
    int n = sizeof(array) / sizeof(array[0]);  // tamanho do array
    int element = 11;
    int index = bSearch(array, 0, n - 1, element);


    if (index == -1) {
        printf("Error: element %d not found\n", element);
        
    } else {
        printf("Element %d found at index %d\n", element, index);
    }
    return 0;
}