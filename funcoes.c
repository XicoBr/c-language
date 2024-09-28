#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>


void abertura(int multiplicador) {
    printf("Tabuada do %d\n", multiplicador);
}

int main() {
    // configurando vs code para funcionar com acento
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;    

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    int multiplicador;

    printf("Digite o valor da tabuada: ");
    scanf("%d", &multiplicador);

    
    abertura(multiplicador);
    for(int i = 1; i <= 10; i++) {
        int resultado = multiplicador * i;
        printf("%d x %d = %d\n", multiplicador, i, resultado);
    }

    return 0;

}