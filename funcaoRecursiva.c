#include <stdio.h>
#include <math.h>


int factorial(int i) {
    
    if (i <= 1) {
        return 1;
    }
    return i * factorial(i - 1);
}

int main() {
    int a = 5;
    int f = factorial(a);

    printf("O fatorial de %d eh: %d\n", a, f);
    return 0;
}