#include <stdio.h>
#include <stdlib.h>

int printaVetor(int *v, int n) {
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
    return (n/2) - 1;
}

int pai(int iFilho) {
    return (iFilho - 1) / 2;
}

void peneira(int *h, int iPai, int n) {
    int aux, maior = iPai;
    int esq = filhoEsquerda(iPai);
    int dir = filhoDireita(iPai);

    if(dir < n && h[maior] < h[dir]) {
        maior = dir;
    }

    if(esq < n && h[maior] < h[esq]) {
        maior = esq;
    }

    if(maior != iPai) {
        aux = h[maior];
        h[maior] = h[iPai];
        h[iPai] = aux;
        peneira(h, maior, n);
    }
}

void construirHeap(int *h, int n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneira(h, i, n);
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    while(n != 0) {
        v = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        construirHeap(v, n);
        printaVetor(v, n);
        scanf("%d", &n);
    }

    return 0;
}