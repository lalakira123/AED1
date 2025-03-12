#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

void particiona(int *v, int e, int d, int p) {
    int pm = e - 1;
    int aux;

    aux = v[d-1];
    v[d-1] = v[p];
    v[p] = aux;

    for(int i = e; i < d; i++) {
        if(v[i] < v[d-1]) {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
    }

    pm++;
    aux = v[pm];
    v[pm] = v[d-1];
    v[d-1] = aux;
}

int main() {
    int n, p, *v;

    scanf("%d", &n);
    scanf("%d", &p);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    particiona(v, 0, n, p);
    printaVetor(v, n);

    return 0;
}