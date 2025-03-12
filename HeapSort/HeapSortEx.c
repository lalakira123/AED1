#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i =0 ; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

int filhoDireita(int iPai) {
    return (2 * iPai) + 2;
}

int filhoEsquerda(int iPai) {
    return (2 * iPai) + 1;
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

void peneira(int *h, int iPai, int n) {
    int maior = iPai;
    int esq = filhoEsquerda(iPai);
    int dir = filhoDireita(iPai);

    if(dir < n && h[maior] < h[dir]) {
        maior = dir;
    }

    if(esq < n && h[maior] < h[esq]) {
        maior = esq;
    }

    if(maior != iPai) {
        int aux = h[iPai];
        h[iPai] = h[maior];
        h[maior] = aux;
        peneira(h, maior, n);
    }
}

void construirHeap(int *h, int n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneira(h, i, n);
    }
}

void removeMax(int *h, int n) {
    int rem = h[0];
    h[0] = h[n-1];
    h[n-1] = rem;
}

void heapSort(int *h, int n) {
    construirHeap(h, n);

    for(int i = n; i > 0; i--) {
        removeMax(h, i);
        peneira(h, 0, i - 1);
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