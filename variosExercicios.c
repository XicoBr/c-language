#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>



int main() {
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);


    // EH PAR

    // for (int i = 2; i <= 50; i++) {
    //     if (i % 2 == 0) {
    //         printf("%d é par.\n", i);
    //     }
    // }


    // SOMANDO NUMEROS
    // int soma = 0;
    // for (int i = 1; i <= 100; i++) {
    //     soma += i;
    // }
    // printf("Soma dos primeiros 100 números: %d\n", soma);

    // TABUADA
    // int numEscolhido;
    // printf("Digite um número para ver a tabuada: ");
    // scanf("%d", &numEscolhido);
    // for (int i = 1; i <= 10; i++) {
    //     printf("%d x %d = %d\n", numEscolhido, i, numEscolhido * i);
    // }


    // CALCULADORA
    // int n1, n2, operacao;
    // int soma, subt, mult, div;


    // printf("Digite o primeiro numero: ");
    // scanf("%d", &n1);
    // printf("Digite o segundo número: ");
    // scanf("%d", &n2);
    // printf("Escolha uma operação\n");
    // printf("1) Soma | 2) Subtração | 3) Multiplicação | 4) Divisão\n");
    // printf("Opção escolhida: ");
    // scanf("%d", &operacao);
    
    // soma = n1 + n2;
    // subt = n1 - n2;
    // mult = n1 * n2;
    // div = n1 / n2;
    
    // switch(operacao) {
    //     case 1:
    //         printf("Resultado da soma: %d\n", soma);
    //         break;
    //     case 2:
    //         printf("Resultado da subtração: %d\n", subt);
    //         break;
    //     case 3:
    //         printf("Resultado da multiplicação: %d\n", mult);
    //         break;
    //     case 4:
    //         if (n2 == 0) {
    //             printf("Não é possível dividir por zero.\n");
    //         } else {
    //             printf("Resultado da divisão: %d\n", div);
    //         }
    //         break;
    //     default:
    //         printf("Opção inválida.\n");
    //         break;
    // }


    // FATORIAL
    // int num, fatorial = 1;
    // printf("Digite um número para calcular seu fatorial: ");
    // scanf("%d", &num);
    // for(int i = 0; i < num; i++) {
    //     fatorial *= (i + 1);
    //     printf("%d! = %d\n", i + 1, fatorial);
    //     Sleep(1000); // Pausa de 1 segundo
    //     //system("cls"); // Limpa a tela


    // }


    // ORDEM CRESCENTE DE NUMEROS

    int numeros[5];
    int maior = 0, menor = 0;
    for(int i = 0; i < 3; i++) {
        printf("Digite o %do. número: ", i + 1);
        scanf("%d", &numeros[i]);
        if(i == 0) {
            maior = numeros[i];
            menor = numeros[i];
        } else if(numeros[i] > maior) {
            maior = numeros[i];
        } else if(numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    


}