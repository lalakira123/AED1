#include <stdio.h>
#include <stdlib.h>

void printaHeap(int *h, int *qtd) {
    for(int i = 0; i < *qtd; i++) {
        if(i == *qtd - 1) {
            printf("%d\n", h[i]);
        } else {
            printf("%d ", h[i]);
        }
    }
}

int filhoEsquerdo(int iPai) {
    return (2 * iPai) + 1;
}

int filhoDireito(int iPai) {
    return (2 * iPai) + 2;
}

int pai(int iFilho) {
    return (iFilho - 1) / 2;
}

int ultimoPai(int *n) {
    return (*n / 2) - 1;
}

void peneira(int *h, int pai, int *n) {
    int maior = pai, aux;
    int esq = filhoEsquerdo(pai);
    int dir = filhoDireito(pai);

    if(dir < *n && h[dir] > h[maior]) {
        maior = dir;
    }

    if(esq < *n && h[esq] > h[maior]) {
        maior = esq;
    }

    if(maior != pai) {
        aux = h[pai];
        h[pai] = h[maior];
        h[maior] = aux;
        peneira(h, maior, n);
    }
}

void construirHeap(int *h, int *n) {
    for(int i = ultimoPai(n); i >= 0; i--) {
        peneira(h, i, n);
    }
}

void inserirHeap(int *h, int chave, int *qtd, int n) {
    if(*qtd < n) {
        int iNovo = *qtd;
        h[iNovo] = chave;
        (*qtd)++;

        if(h[iNovo] > h[pai(iNovo)]) {
            construirHeap(h, qtd);
        }
    }
}

void removeMaximo(int *h, int *qtd) {
    if(*qtd > 0) {    
        printf("%d\n", h[0]);
        int rem = h[0];
        h[0] = h[*qtd - 1];
        h[*qtd - 1] = rem;
        (*qtd)--;
        peneira(h, 0, qtd);
    }
}

int main() {
    int qtd = 0, n, *h, num;
    char comando;

    scanf("%d", &n);

    h = (int*)malloc(n * sizeof(int));
    
    while(scanf(" %c", &comando) != EOF) {
        switch(comando) {
            case 'I': {
                scanf("%d", &num);
                inserirHeap(h, num, &qtd, n);
                break;
            }
        
            case 'M':
                printaHeap(h, &qtd);
                break;
        
            case 'R':
                removeMaximo(h, &qtd);
                break;
        
            default:
                break;
        }
    } 

    return 0;
}