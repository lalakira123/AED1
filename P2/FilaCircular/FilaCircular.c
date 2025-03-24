#include <stdio.h>
#include <stdlib.h>

struct tFila {
    int *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tFila criarFila(int n) {
    struct tFila f;
    f.itens = (int*)malloc(n * sizeof(int));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;
    return f;
}

int primeiro(struct tFila f) {
    return f.itens[f.inicio];
}

int ultimo(struct tFila f) {
    int iUltimo = f.final - 1;
    if(iUltimo == -1) {
        iUltimo = f.tamanho - 1;
    }
    return f.itens[iUltimo];
}

int filaCheia(struct tFila f) {
    return (f.final + 1) % f.tamanho == f.inicio;
}

int filaVazia(struct tFila f) {
    return f.inicio == f.final;
}

void desenfileirar(struct tFila *f) {
    if(!filaVazia(*f)) {
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}

void enfileirar(struct tFila *f, int item) {
    if(!filaCheia(*f)) {
        f->itens[f->final] = item;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void mostrarFila(struct tFila f) {
    int i;
    for(i=f.inicio; i != f.final; i = (i+1) % f.tamanho) {
        printf("%d%s", f.itens[i], f.itens[i] != ultimo(f)?" ":"\n");
    }
}

int main() {
    int n, item;
    char opc;
    struct tFila f;

    scanf("%d", &n);

    f = criarFila(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%d", &item);
        }

        switch(opc) {
            case 'E':
                enfileirar(&f, item);
                break;

            case 'D':
                if(!filaVazia(f)) {
                    printf("%d\n", primeiro(f));
                }
                desenfileirar(&f);
                break;
        }
    }
}