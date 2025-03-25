#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tItem {
    char nome[102];
};

struct tFila {
    struct tItem *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tItem criarItem(char *item) {
    struct tItem it;
    strcpy(it.nome, item);
    return it;
}

struct tFila criarFila(int n) {
    struct tFila f;
    f.itens = (struct tItem *)malloc(n * sizeof(struct tItem));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;
    return f;
}

int filaVazia(struct tFila f) {
    return f.inicio == f.final;
}

int filaCheia(struct tFila f) {
    return (f.final + 1) % f.tamanho == f.inicio;
}

struct tItem primeiro(struct tFila f) {
    return f.itens[f.inicio];
}

struct tItem ultimo(struct tFila f) {
    int iUltimo = f.final - 1;
    if(iUltimo == -1) {
        iUltimo = f.tamanho - 1;
    }
    return f.itens[iUltimo];
}

void enfileirar(struct tFila *f, struct tItem item) {
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
    for(i=f.inicio; i != f.final; i = (i + 1) % f.tamanho) {
        printf("%s%s", f.itens[i].nome, f.itens[i].nome != ultimo(f).nome?" ":"\n");
    }
}

int main() {
    int n;
    char opc, item[102];
    struct tItem it;
    struct tFila f;

    scanf("%d", &n);

    f = criarFila(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%s", item);
            it = criarItem(item);
        }

        switch(opc) {
            case 'E':
                enfileirar(&f, it);
                break;

            case 'D':
                if(!filaVazia(f)) {
                    printf("%s\n", primeiro(f).nome);
                }
                desenfileirar(&f);
                break;
        }
    }

    return 0;
}
