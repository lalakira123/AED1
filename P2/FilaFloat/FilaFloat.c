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
    f.itens = (float *)malloc(n * sizeof(n));
    f.tamanho = n;
    f.inicio = -1;
    f.final = -1;
    return f;
}

int filaVazia(struct tFila f) {
    return f.inicio == -1 && f.final == -1 || f.inicio > f.final;
}

int filaCheia(struct tFila f) {
   return f.final == f.tamanho - 1;
}

float primeiro(struct tFila f) {
    return f.itens[f.inicio];
}

void enfileirar(struct tFila *f, float item) {
    if(!filaCheia(*f)) {
        if(f->inicio == -1) {
            f->inicio++;
        }
        f->itens[++f->final] = item;
    }
}

void desenfileirar(struct tFila *f) {
    if(!filaVazia(*f)) {
        if(f->inicio == f->final) {
            f->inicio = -1;
            f->final = -1;
        } else {
            f->inicio++;
        }
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

