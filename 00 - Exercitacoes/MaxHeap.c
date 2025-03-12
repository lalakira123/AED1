#include <stdio.h>
#include <stdlib.h>

int printaVetor(int *v, int n) {
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

int pai(int iF) {
    return (iF - 1) / 2;
}

void peneira(int *h, int iP, int n) {
    int maior = iP;
    int esq = filhoE(iP);
    int dir = filhoD(iP);
    int aux;

    if(dir < n && h[dir] > h[maior]) {
        maior = dir;
    }

    
    if(esq < n && h[esq] > h[maior]) {
        maior = esq;
    }

    if(maior != iP) {
        aux = h[maior];
        h[maior] = h[iP];
        h[iP] = aux;
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