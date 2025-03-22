#include <stdio.h>
#include <stdlib.h>

void printaHeap(int *v, int n) {
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d ", v[i]);
        }
    }
}

int filhoEsquerda(int iPai){
    return (2 * iPai) + 1;
}

int filhoDireita(int iPai){
    return (2 * iPai) + 2;
}

int ultimoPai(int tamanhoArray) {
    return (tamanhoArray / 2) - 1;
}

void peneirar(int *v, int p, int n) {
    int maior = p, aux;
    int esq = filhoEsquerda(p);
    int dir = filhoDireita(p);
    
    if(dir < n && v[dir] > v[maior]) {
        maior = dir;
    }
    
    if(esq < n && v[esq] > v[maior]) {
        maior = esq;
    }


    if(maior != p) {
        aux = v[maior];
        v[maior] = v[p];
        v[p] = aux;
        peneirar(v, maior, n);
    }
}

void construirHeap(int *v, int n) {
    for(int i = ultimoPai(n); i >= 0; i--){
        peneirar(v, i, n);
    }
}

int main(){
    int n, *v;

    scanf("%d", &n);

    while(n != 0) {
        
        v = (int*)malloc(n * sizeof(int));

        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        construirHeap(v, n);
        printaHeap(v, n);

        free(v);

        scanf("%d", &n);
    }

    return 0;
}