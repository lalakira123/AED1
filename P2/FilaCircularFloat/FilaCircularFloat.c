#include <stdio.h>
#include <stdlib.h>

struct tFila {
    float *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tFila criarFila(int n) {
    struct tFila f;
    f.itens = (float*)malloc(n * sizeof(float));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;
    return f;
}

float primeiro(struct tFila f) {
    return f.itens[f.inicio];
}

float ultimo(struct tFila f) {
    int iUltimo = f.final - 1;
    if(iUltimo == -1) {
        iUltimo = f.tamanho - 1;
    }
    return f.itens[iUltimo];
}

int filaVazia(struct tFila f) {
    return f.inicio == f.final;
}   

int filaCheia(struct tFila f) {
    return (f.final + 1) % f.tamanho == f.inicio;
}

void enfileirar(struct tFila *f, float item) {
    if(!filaCheia(*f)) {
        f->itens[f->final] = item;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void desenfileirar(struct tFila *f) {
    if(!filaVazia(*f)) {
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}

void mostrarFila(struct tFila f) {
    int i;
    for(i=f.inicio; i != f.final; i = (i+1) % f.tamanho) {
        printf("%.2f%s", f.itens[i], f.itens[i] != ultimo(f)?" ":"\n");
    }
}

int main() {
    int n;
    float item;
    char opc;
    struct tFila f;

    scanf("%d", &n);

    f = criarFila(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%f", &item);
        }

        switch(opc) {
            case 'E':
                enfileirar(&f, item);
                break;

            case 'D':
                if(!filaVazia(f)) {
                    printf("%.2f\n", primeiro(f));
                }
                desenfileirar(&f);
                break;
        }
    }

    return 0;
}