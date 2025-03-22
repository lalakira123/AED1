#include <stdio.h>
#include <stdlib.h>

int printaHeap(int *v, int n) {
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d ", v[i]);
        }
    }
}

int filhoEsquerdo(int iPai) {
    return (2 * iPai) + 1;
}

int filhoDireita(int iPai) {
    return (2 * iPai) + 2;
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

void peneirar(int *h, int pai, int n) {
    int menor = pai, aux;
    int esq = filhoEsquerdo(pai);
    int dir = filhoDireita(pai);

    if(dir < n && h[dir] < h[menor]) {
        menor = dir;
    }

    if(esq < n && h[esq] < h[menor]) {
        menor = esq;
    }

    if(menor != pai) {
        aux = h[pai];
        h[pai] = h[menor];
        h[menor] = aux;
        peneirar(h, menor, n);
    }
}

void construirHeap(int *v, int n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneirar(v, i, n);
    }
}

int main() {
    int n, *v;

    while(scanf("%d", &n) && n != 0) {
        v = (int*)malloc(n * sizeof(int));

        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        construirHeap(v, n);

        printaHeap(v, n);
    }

    return 0;
}