#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void funcaoA (int pt_ptL, int ptLista, int L) {
    printf("Dentro da funcaoA:\n");
    printf("&pt_ptL = %p (endereço de pt_ptL na funcaoA)\n", (void)&pt_ptL);
    printf("pt_ptL = %p (endereço de pl)\n", (void)pt_ptL);
    printf("pt_ptL = %p (endereço alocado por pl)\n", (void)pt_ptL);
    printf("pt_ptL = %d (valor armazenado no endereço apontado por pl)\n", *pt_ptL);

    printf("&ptLista = %p (endereço do ponteiro ptLista na funcaoA)\n", (void)&ptLista);
    printf("ptLista = %p (endereço alocado por pl)\n", (void)ptLista);
    printf("ptLista = %d (valor armazenado no endereço apontado por ptLista)\n", ptLista);

    printf("&L = %p (endereço de L na funcaoA)\n", (void)&L);
    printf("L = %d (valor de L passado para a funcaoA)\n\n", L);
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    int l = 77777;
    int pl = (int) malloc (sizeof(int));

    pl = l;

    printf("Dentro da main:\n");
    printf("&l = %p (endereço de l)\n", (void)&l);
    printf("l = %d (valor de l)\n", l);

    printf("&pl = %p (endereço de pl)\n", (void)&pl);
    printf("pl = %p (endereço alocado por malloc)\n", (void)pl);
    printf("pl = %d (valor armazenado no endereço apontado por pl)\n\n",pl);

    funcaoA(&pl, pl, l);

    free(pl);  // Libera a memória alocada
    return 0;
}