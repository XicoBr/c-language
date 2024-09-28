#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include "jogoDaForca.h"  // criado em outro documento, temos a assinatura de todas as funções que serão utilizadas no programa. Agora, as funções podem ser colocadas em qualquer posição, sem apresentar erros de compilação. Como é um arquivo criado e está no mesmo diretório do programa, utilizamos aspas ao invés dos sinais de maior e menor.




// Variaveis Globais
// usadas por todas as funções do programa, não é necessário passá-la para a função principal.
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;
int acertou = 0;
// valores booleanos;



// sprintf imprime em um array de chars; 
// lembrar que strings em C tem um caractere especial que identifica o fim de uma String: \0, entao, ao passarmos uma string para uma variável, também estamos adicionando esse caractere ao final da string.
int letraExiste(char letra) {
    // verificando letra a letra da palavra secreta e vendo se encontramos o chute aqui
    for(int j = 0; j < strlen(palavraSecreta); j++) {
        if (letra == palavraSecreta[j]) {
            return 1;
        }
    }

    return 0;  
}

int chutesErrados() {
    // criando variavel para contar os erros do jogador
    int erros = 0;
    
    // loop em todos os chutes dados
    for (int i = 0; i < chutesDados; i++) {
       if (!letraExiste(chutes[i])) {
            erros++;
       } 

       
    }

    return erros;
}

int enforcou() {
    

    return chutesErrados() >= 5;
}

int ganhou() {
    // faz a verificação de todas os chutes dados na plavra secreta.
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if(!jaChutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}

void abertura() {  // sintaxe de uma função em C;
    printf("/***********************/\n");
    printf("   Jogo da Forca\n");
    printf("/***********************/\n");

}

void chuta() {
    char chute;
        
    printf("Informe uma letra: ");
    scanf(" %c", &chute);  // colocamos um espaço antes da variável, pois o scanf, ao ler um caractere único, considera um enter como caractere, uma vez que o mesmo fica de buffer(armazenado temporariamente). Ele se perde quando digitamos uma letra e um enter, que entende como dois valores, e não um.

    if (letraExiste(chute)) {
        printf("Acertou! A palavra tem a letra %c\n\n", chute);
    } else {
        printf("Errou! A palavra não tem a letra %c\n\n", chute);
    }

    chutes[chutesDados] = chute;
    chutesDados++;   
    
}

int jaChutou(char letra) {
// o void, numa função, significa que não precisamos retornar nada a quem a chamou. No caso abaixo, precisamos retornar um valor;
    
    int achou = 0;
    
    for(int j = 0; j < chutesDados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(){
    int erros = chutesErrados();
    
    printf("  -------       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
                (erros >= 1 ? '_' : ' '),
                (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
                (erros >= 2 ? '|' : ' '),
                (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c    \n", (erros >= 4 ? '/' : ' '),
                (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int index = 0; index < strlen(palavraSecreta); index++) {

        if(jaChutou(palavraSecreta[index])) {
            printf("%c ", palavraSecreta[index]);
        } else {
            printf("_ ");
        }
    
    }        
    printf("\n");
    
}


void escolhePalavra() {
    
    FILE* f = fopen("C:\\Users\\diego\\OneDrive\\Documentos\\Cursoemvideo\\Estudos\\c language\\c-language\\palavras.txt", "r+");  // declaração de ponteiro do tipo FILE*

    // f = fopen("palavras.txt", "r");  // usando a função fopen() para abrir o arquivo do disco.


    if (f == 0) {
        printf("Banco de Dados de palavras não disponível.\n");
        exit(1); // exit(1) significa que o program se encerrou de maneira inesperada(ocorreu algum erro, por exemplo.). Se fosse exit(0), o programa se encerraria conforme esperado.
    }
    
    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);  // a função fscanf() trabalha com ponteiro
    

    // gera numero aleatorio
    srand(time(0));
    int randomico = rand() % qtdPalavras;

    // lê do arquivo até chegar na linha desejada
    for (int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);  // fechando o arquivo para não ficar aberto em caso de erro durante a execução do programa.
}

void adicionaPalavras() {
    char quer;

    printf("Quer adicionar uma nova palavra ao jogo? [S/N]");
    scanf(" %c", &quer);

    if (quer == 'S' || quer == 's') {
        char novaPalavra[TAMANHO_PALAVRA];

        printf("Informe a nova palavra: ");
        scanf("%s", novaPalavra);
    
        FILE* f;

        f = fopen("C:\\Users\\diego\\OneDrive\\Documentos\\Cursoemvideo\\Estudos\\c language\\c-language\\palavras.txt", "a");  // abre o arquivo para adicionar novas palavras
        if (f == 0) {
            printf("Banco de Dados de palavras não disponível.\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET); // fseek() é usado para "setar" a posição inicial desejada. Recebe 3 parâmetros: o arquivo, quantos bytes deve andar para esquerda ou direita e de onde deve começar a andar do começo do arquivo, da posição corrente ou do final.
        fprintf(f, "%d", qtd); //

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);
    
        fclose(f);
    
    }
}


int main() {

    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);

    
    
    
    

    abertura();  // quando o código é executado e a máquina encontra uma chamada de função (no caso, abertura()), o computador "suspende" a execução do main() e executa a chamada. Após finalizá-la, ele continua o processo de int main();
    escolhePalavra(); // 

    do {        
        
        desenhaForca(); //
        chuta();
        
    } while(!ganhou() && !enforcou());  // enquanto as duas condições forem falsas, o programa continua sendo executado.

    if (ganhou()) {       

        printf("       -----------      \n");
        printf("      '._==_==_=_.'     \n");
        printf("       .-\\:     /-.    \n");
        printf("      | (|:.    |) |    \n");
        printf("       '-|:.    |-'     \n");
        printf("       \\::.     /      \n");
        printf("        '::.   .'       \n");
        printf("         '::..'         \n");
        printf("          )  (          \n");
        printf("        -.'  '.-        \n");
        printf("      '---------'      \n\n");
        printf("Parabéns, você ganhou!!\n\n");
    } else {
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    
    }
    
}