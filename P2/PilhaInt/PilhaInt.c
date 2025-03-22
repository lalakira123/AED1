#include <stdio.h>
#include <stdlib.h>

struct tPilha {
    int *itens;
    int tamanho;
    int topo;
};

struct tPilha criarPilha(int n) {
    struct tPilha p;
    p.itens = (int*)malloc(n * sizeof(int));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

int topo(struct tPilha p) {
    return p.itens[p.topo];
}

int pilhaVazia(struct tPilha p) {
    return p.topo == -1;
}

int pilhaCheia(struct tPilha p) {
    return p.topo == p.tamanho - 1;
}

void mostraTopoBase(struct tPilha p) {
    int i;
    for(i = p.topo; i >= 0; i--) {
        printf("%d%s", p.itens[i], i==0?"\n":" ");
    }
}

void mostraBaseTopo(struct tPilha p) {
    int i;
    for(i = 0; i <= p.topo; i++) {
        printf("%d%s", p.itens[i], i==p.topo?"\n":" ");
    }
}

void desempilha(struct tPilha *p) {
    if(!pilhaVazia(*p)) {
        p->topo -= 1;
    }
}

void empilha(struct tPilha *p, int chave) {
    if(!pilhaCheia(*p)) {
        p->itens[++p->topo] = chave;
    }
}

int main() {
    int n, chave, top;
    char opc;
    struct tPilha p;

    scanf("%d", &n);

    p = criarPilha(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%d", &chave);
        }

        switch(opc) {
            case 'E':
                empilha(&p, chave);
                break;

            case 'D':
                desempilha(&p);
                break;
            
            case 'T':
                if(!pilhaVazia(p)) {
                    top = topo(p);
                    printf("%d\n", top);
                }
                break;

            case 'X':
                mostraTopoBase(p);
                break;

            case 'B':
                mostraBaseTopo(p);
                break;
        }
    }

    return 0;
}