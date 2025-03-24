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

char* primeiro(struct tFila f) {
    return f.itens[f.inicio].nome;
}

void enfileirar(struct tFila *f, struct tItem item) {
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
    char opc, item[102];
    struct tFila f;
    struct tItem it;

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
                    printf("%s\n", primeiro(f));
                }
                desenfileirar(&f);
                break;
        }
    }

    return 0;
}
