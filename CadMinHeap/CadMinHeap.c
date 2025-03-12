#include <stdio.h>
#include <stdlib.h>

int filhoEsquerda(int iPai) {
    return (2 * iPai) + 1;
}

int filhoDireita(int iPai) {
    return (2 * iPai) + 2;
}

int ultimoPai(int *n) {
    return (*n / 2) - 1;
}

int pai(int iFilho) {
    return (iFilho - 1) / 2;
}

void peneira(int *h, int iPai, int *n) {
    int menor = iPai, aux;
    int esq = filhoEsquerda(iPai);
    int dir = filhoDireita(iPai);

    if(dir < *n && h[dir] < h[menor]) {
        menor = dir;
    }

    if(esq < *n && h[esq] < h[menor]) {
        menor = esq;
    }

    if(menor != iPai) {
        aux = h[iPai];
        h[iPai] = h[menor];
        h[menor] = aux;
        peneira(h, menor, n);
    }
}

void criarHeap(int *h, int *n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneira(h, i, n);
    }
}

void inserirHeap(int *h, int chave, int n, int *qtd) {
    if(*qtd < n) {
        int iNovo = *qtd;
        h[iNovo] = chave;
        (*qtd)++;

        if(h[iNovo] < h[pai(iNovo)]) {
            criarHeap(h, qtd);
        }
    }
}

void removerHeap(int *h, int *qtd) {
    if(*qtd > 0) {
        printf("%d\n", h[0]);

        int aux = h[0];
        h[0] = h[*qtd - 1];
        h[*qtd - 1] = aux;
        (*qtd)--;

        peneira(h, 0, qtd);
    }
}

void printaHeap(int *h, int *n) {
    for(int i = 0; i < *n; i++) {
        if(i == *n -1) {
            printf("%d\n", h[i]);
        } else {
            printf("%d ", h[i]);
        }
    }
}

int main() {
    int qtd = 0, n, *h;
    char opc;
    int chave;

    scanf("%d", &n);

    h = (int*)malloc(n * sizeof(int));

    while(scanf(" %c", &opc) != EOF) {
        switch(opc) {
            case 'I':
                scanf("%d", &chave);
                inserirHeap(h, chave, n, &qtd);
                break;
            case 'M':
                printaHeap(h, &qtd);
                break;
            case 'R':
                removerHeap(h, &qtd);
                break;
        }
    }

    return 0;
}