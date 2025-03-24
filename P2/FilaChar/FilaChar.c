#include <stdio.h>
#include <stdlib.h>

struct tFila {
    char *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tFila criarFila(int n) {
    struct tFila f;
    f.itens = (char *)malloc(n * sizeof(char));
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

char primeiro(struct tFila f) {
    return f.itens[f.inicio];
}

void enfileirar(struct tFila *f, char item) {
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
    char opc, item;
    struct tFila f;

    scanf("%d", &n);

    f = criarFila(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf(" %c", &item);
        }

        switch(opc) {
            case 'E':
                enfileirar(&f, item);
                break;

            case 'D':
                if(!filaVazia(f)) {
                    printf("%c\n", primeiro(f));
                }
                desenfileirar(&f);
                break;
        }
    }

    return 0;
}
