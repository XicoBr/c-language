#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Portuguese-Brazil");


    printf("======================================\n");
    printf("   Bem vindo ao Jogo de Adivinhação!\n");
    printf("======================================\n");

    int chute;
    printf("Chuta ae: ");
    scanf("%d", &chute);
    printf("Número escolhido: %d\n", chute);
}