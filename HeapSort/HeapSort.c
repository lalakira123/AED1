#include <stdio.h>
#include <stdlib.h>

int filhoDireita(int iPai) {
    return (2 * iPai) + 2;
}

int filhoEsquerda(int iPai) {
    return (2 * iPai) + 1;
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

int pai(int iFilho) {
    return (iFilho - 1) / 2;
}

void peneirar(int *h, int iPai, int n) {
    int aux, maior = iPai;
    int dir = filhoDireita(iPai);
    int esq = filhoEsquerda(iPai);

    if(dir < n && h[maior] < h[dir]) {
        maior = dir;
    }

    if(esq < n && h[maior] < h[esq]) {
        maior = esq;
    }

    if(maior != iPai) {
        aux = h[iPai];
        h[iPai] = h[maior];
        h[maior] = aux;
        peneirar(h, maior, n);
    }
}

void construirHeap(int *h, int n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneirar(h, i, n);
    }
}

void removerMax(int *h, int n) {
    int rem = h[0];
    h[0] = h[n - 1];
    h[n - 1] = rem;
}

void mostrarVetor(int *v, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d%s", v[i], i<n-1?" ":"\n");
    }
}

void heapSort(int *h, int n) {
    construirHeap(h, n);
    mostrarVetor(h, n);
    for(int i = n; i > 0; i--) {
        removerMax(h, i);
        peneirar(h, 0, i - 1);
        mostrarVetor(h, i - 1);
    }
}

int main()
{
    int *v, n, i;

    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

    mostrarVetor(v, n);
    heapSort(v, n);
    mostrarVetor(v, n);

    return 0;
}