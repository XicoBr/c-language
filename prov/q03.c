#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
void funcao_1 (int x, int y) {
    x = y;
    y += x;
    x *= 2;
   
}

void funcao_2(int * x, int * y) {
    x = y;
    *y += *x;
    *x *= 2;
    
}

int main() {
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);

    int x, y;
    printf("Digite o valor 45: ");
    scanf("%d", &x);
    printf("Digite o valor -10: ");
    scanf("%d", &y);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    funcao_1(x, y);
    printf("Funcao 1: x = %d\t y = %d\n", x, y);
    funcao_2(&x, &y);
    printf("Funcao 2: x = %d\t y = %d\n", x, y);
}