#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

// int main() {

//     // configurando vs code para funcionar com acento
//     setlocale(LC_ALL, "Portuguese-Brazil");
//     UINT CPAGE_UTF8 = 65001;    

//     // Define codificação como sendo UTF-8
//     SetConsoleOutputCP(CPAGE_UTF8);

//     int c = 10;
//     int d = 50;
//     int* ponteiro;  // ponteiro é criado com o asterisco junto de seu tipo;
//     ponteiro = &d;  // atribuímos o mesmo endereço de memória da variável d ao ponteiro.
    
//     printf("Endereço de memória da variável C: %d\n", &c);  // ao utilizarmos o & em uma variável, estamos pedindo para imprimir o endereço de memória que aquela variável ocupa.
//     printf("===================================\n");
//     printf("Endereço da variável Ponteiro: %d\nEndereço da variável D: %d\n", ponteiro, &d);  // usamos apenas o nome do ponteiro para mostrarmos o endereço de memória;
//     printf("Valor da variável ponteiro: %d\nValor da variável D: %d\n", *ponteiro, d);  // usamos asterisco no nome do ponteiro para mostrar o valor que está dentro do endereço;



//     return 0;

// }


int main() {

    // configurando vs code para funcionar com acento
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;    

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);

    int numeros[3];

    int* ponteiro = numeros;

    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    for(int i = 0; i < 3; i++) {
        printf("Variavel: %d\n", numeros[i]);

        printf("Ponteiro: %d", *(ponteiro + i));  // *ponteiro é usado para acessar a posiçao de um array
        
        printf("\n");
    }


    return 0;

}