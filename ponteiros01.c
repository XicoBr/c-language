#include <stdio.h>
#include <locale.h>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);

    int var = 42;           // Uma variável inteira
    int *ptr = &var;        // Ponteiro que armazena o endereço de 'var'
    int **ptr_ptr = &ptr;   // Ponteiro para ponteiro que armazena o endereço de 'ptr'

    // Exibindo valores e endereços
    printf("Valor de var: %d\n", var);
    printf("Endereço de var (&var): %p\n", (void*)&var);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("Valor de ptr (endereço de var): %p\n", (void*)ptr);
    printf("Endereço de ptr (&ptr): %p\n", (void*)&ptr);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("Valor de ptr_ptr (endereço de ptr): %p\n", (void*)ptr_ptr);
    printf("Valor apontado por ptr_ptr (*ptr_ptr): %p\n", (void*)*ptr_ptr);
    printf("Valor final apontado por **ptr_ptr: %d\n", **ptr_ptr);

    return 0;
}