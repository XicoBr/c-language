#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {

    printf("==================================\n");
    printf("          Jogo da forca\n");
    printf("==================================\n");
}


void chuta() {

    char chute;
        
    printf("\n");
    printf("Faça um chute: ");
    scanf(" %c", &chute);
    
    chutes[tentativas] = chute;  // chutes e tentativas são usados em conjunto; enquanto chutes é um array, tentativas é a posição que o chute ocupa dentro do array chutes.
}

int jachutou(char letra) {  // char letra == palavrasecreta[i] da função desenhaforca()
    int achou = 0;

    for (int j = 0; j < tentativas; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }

    }

    return achou;
}


void desenhaforca() {
     printf("Tentativas: %d\n", tentativas);

    for (int i = 0;(unsigned) i < strlen(palavrasecreta); i++) {
        
        
        if (jachutou(palavrasecreta[i]))  { // se a função jachutou() retornar True:
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }           
        

    }
    
    printf("\n");
}

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");  // sprintf(<destination>, <value>)
}


int main() {
    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);

    abertura();
    escolhepalavra();
    
    printf("%s\n", palavrasecreta);


    int acertou = 0, enforcou = 0;  // valores booleanos; 0 - False; 1 - True.
    

    do {
        

        desenhaforca();
        chuta();

        tentativas++;

    } while (!acertou && !enforcou);  // enquanto NÃO enforcou E NÃO acertou.

}