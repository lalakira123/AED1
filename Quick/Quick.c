#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d ", v[i]);
        }
    }
}

int particiona(int *v, int e, int d, int n) {
    int pivo = v[d];
    int pm = (e - 1);

    for(int i = e; i < d; i++) {
        if(v[i] <= pivo) {
            pm++;
            int aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;   
        }
        printaVetor(v, n);
    }

    pm++;
    int aux = v[d];
    v[d] = v[pm];
    v[pm] = aux;
    printaVetor(v, n);

    return pm;
}

void quick(int *v, int e, int d, int n) {
    int pivo;

    if(e < d) {
        pivo = particiona(v, e, d, n);

        quick(v, e, pivo - 1, n);
        quick(v, pivo+1, d, n);    
    }
}

int main() {
    int n, *v;

    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printaVetor(v, n);
    quick(v, 0, n - 1, n);
    printaVetor(v, n);

    return 0;
}