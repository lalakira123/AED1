#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d ", v[i]);
        }
    }
}

void ordenaBubble(int *v, int n) {
    int count = 0;

    printaVetor(v, n);

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                count = count + 1;

                printaVetor(v, n);
            }
        }
    }

    printaVetor(v, n);
    printf("Trocas: %d\n", count);
}

int main() {
    int n, *v;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    ordenaBubble(v, n);

    return 0;
}