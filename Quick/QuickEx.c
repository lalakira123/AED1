#include <stdio.h>
#include <stdlib.h>

void printVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

int particiona(int *v, int e, int d) {
    int pm = e - 1;
    int aux;

    int i;
    for(i = e; i < d; i++) {
        if(v[i] <= v[d]) {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
    }

    pm++;
    aux = v[pm];
    v[pm] = v[i];
    v[i] = aux;

    return pm;
}

void quick(int *v, int e, int d) {
    int pivo;

    if(e < d) {
        pivo = particiona(v, e, d);
        quick(v, e, pivo - 1);
        quick(v, pivo + 1, d);
    }
}

int main() {
    int n, *v;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    quick(v, 0, n-1);
    printVetor(v, n);

    return 0;
}