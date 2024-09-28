#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

// #define NUMERO_TENTATIVAS 3 // constante usada no código

// int main() {
//     // configurando vs code para funcionar com acento
//     setlocale(LC_ALL, "Portuguese-Brazil");
//     UINT CPAGE_UTF8 = 65001;    

//     // Define codificação como sendo UTF-8
//     SetConsoleOutputCP(CPAGE_UTF8);

//     printf("======================================\n");
//     printf("   Bem vindo ao Jogo de Adivinhação!\n");
//     printf("======================================\n");

//     int chute, numeroSecreto = 42;

//     for (int index = 1; index <= NUMERO_TENTATIVAS; index++) {
//         printf("%d/3 tentativas\n", index);
//         printf("Chuta ae: ");
//         scanf("%d", &chute);
//         printf("Número escolhido: %d\n", chute);
        
//         if (chute < 0) {
//             printf("Erro! Escolha apenas números positivos!\n");
//             index--;
//             continue; // diz ao laço para ir para a próxima iteração, sem executar o restante de código dentro de seu bloco de origem (no caso, o primeiro for)
//         }

//         int acertou = chute == numeroSecreto; // recebe um valor booleano. É int pois o valor recebe 0 para False e 1 para True
//         int maior = chute > numeroSecreto;
//         int menor = chute < numeroSecreto; 

//     // Primeira forma de montagem
// /* 
//         if (acertou) {
//             printf("Parabéns, você acertou!\n");
//             break;
//         } else if (maior) { //
//             printf("Errou! O número secreto é menor que %d\n", chute);
//         } else {
//             printf("Errou! O número secreto é maior que %d\n", chute);
//         } */

//     // Segunda forma de montagem
//         if (acertou) {
//             printf("Parabéns, você acertou!\n");
//             break;
//         }
//         if (maior) {
//             printf("Errou! O número secreto é menor que %d\n", chute);
//         }
//         if (menor) {
//             printf("Errou! O número secreto é maior que %d\n", chute);
//         }

//     }
    
//     printf("Obrigado por jogar!\n");
//     return 0; // indica que a função main() retornou um valor inteiro, e 0 é o valor padrão de sucesso para o programa
// }


// TERCEIRA FORMA USANDO WHILE
int main() {

    setlocale(LC_ALL, "Portuguese-Brazil");
    UINT CPAGE_UTF8 = 65001;   
    SetConsoleOutputCP(CPAGE_UTF8);

    int segundos = time(0); // para gerarmos um número secreto aleatorio, utilizamos a função time(0) que retorna o número de segundos desde 1 de janeiro de 1970
    srand(segundos); // utilizamos a função srand() para gerar um número aleatório de semente para a função rand()
    
    int numeroGrande = rand();  // n1 recebe um número aleatório usando a função rand()

    



    int numeroSecreto = numeroGrande % 100;  // resto de divisão de segundos gerados aleatoriamente
    int chute;
    int ganhou = 0; // ganhou = 0 tem valor booleano, uma vez que servirá como verificador de condição
    double pontos = 1000;
    int acertou = 0;
    

    printf("======================================\n");
    printf("   Bem vindo ao Jogo de Adivinhação!\n");
    printf("======================================\n");

    // CRIANDO NÍVEIS DE DIFICULDADE
    int nivel, totalTentativas;
     

    printf("Qual o nível de dificuldade!\n");
    printf("1) Fácil | 2) Médio | 3) Difícil\n");
    printf("Dificuldade escolhida: ");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1:
            totalTentativas = 15;
            break;
        case 2:
            totalTentativas = 10;
            break;
        case 3:
            totalTentativas = 5;
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            return 0;
    }


    for (int i = 1; i <= totalTentativas; i++) {        
        printf("\nTentativas: %d/%d.\n", i, totalTentativas);
        printf("\nFaça a sua %da. jogada: ", i);
        scanf("%d", &chute);

        if (chute < 0) {
            printf("\nErro! Escolha um número positivo!\n");
            printf("=========================================\n");
            i--;
            continue;
        }
        printf("\nSeu %do. chute foi %d.\n", i, chute);

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;



        if (acertou) {          
            printf("=========================================\n");
            break;
        } else if (maior) {
            printf("\nErrou! O número secreto é menor que %d.\n", chute);
            printf("=========================================\n");
        } else {
            printf("\nErrou! O número secreto é maior que %d.\n", chute);
            printf("=========================================\n");
        }
        int pntPrdds = abs(chute - numeroSecreto) / 2.0; 
        
        
        // abs retorna o valor absoluto do número, que é sempre positivo. 
        // colocarmos 2.0 ao invés de 2 garante que a operação seja feita com números flutuantes. A essa técnica chamamos de Casting, quando alteramos o tipo de uma variável para outra de menor ou maior escopo.
        // outra maneira de usar o Casting seria alterar o tipo das duas operações, assim:
        // double pontosPerdidos = (double)(chute - numeroSecreto) / (double)2;

        pontos = pontos - pntPrdds;
        

    }

    if (chute == numeroSecreto) {
        printf("\nParabéns, você acertou! O número é %d.\n", numeroSecreto);
        printf("\nPontuação final: %.2f\n", pontos);
    } else {
        printf("\nVocê perdeu! O número secreto é %d.\n", numeroSecreto);
    }

    printf("Obrigado por jogar!\n");
    return 0; //
}