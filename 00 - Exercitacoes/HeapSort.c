#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i =0 ; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

int filhoD(int iP) {
    return (2 * iP) + 2;
}

int filhoE(int iP) {
    return (2 * iP) + 1;
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

void peneirar(int *h, int iP, int n) {
    int maior = iP;
    int esq = filhoE(iP);
    int dir = filhoD(iP);
    int aux;

    if(dir < n && h[maior] < h[dir]) {
        maior = dir;
    }

    if(esq < n && h[maior] < h[esq]) {
        maior = esq;
    }

    if(maior != iP) {
        aux = h[iP];
        h[iP] = h[maior];
        h[maior] = aux;
        peneirar(h, maior, n);
    }
}

void construirHeap(int *h, int n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneirar(h, i, n);
    }
}

void removeMax(int *h, int n) {
    int rem = h[n - 1];
    h[n - 1] = h[0];
    h[0] = rem;
}

void heapSort(int *h, int n) {
    construirHeap(h, n);

    for(int i = n; i > 0; i--) {
        removeMax(h, i);
        peneirar(h, 0, i - 1);
    }
}

int main() {
    int n, *v;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    heapSort(v, n);

    printaVetor(v, n);

    return 0;
}