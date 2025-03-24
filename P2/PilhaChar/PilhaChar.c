#include <stdio.h>
#include <stdlib.h>

struct tPilha {
    char *itens;
    int tamanho;
    int topo;
};

struct tPilha criarPilha(int n) {
    struct tPilha p;
    p.itens = (char*)malloc(n * sizeof(char));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

int pilhaVazia(struct tPilha p) {
    return p.topo == -1;
}

int pilhaCheia(struct tPilha p) {
    return p.topo == p.tamanho - 1;
}

char topo(struct tPilha p) {
    return p.itens[p.topo];
}

void mostraBaseTopo(struct tPilha p) {
    int i;
    for(i=0; i <= p.topo; i++) {
        printf("%c%s", p.itens[i], i==p.topo?"\n":" ");
    }
}

void mostraTopoBase(struct tPilha p) {
    int i;
    for(i=p.topo; i >= 0; i--) {
        printf("%c%s", p.itens[i], i==0?"\n":" ");
    }
}

void empilhar(struct tPilha *p, char item) {
    if(!pilhaCheia(*p)) {
        p->itens[++p->topo] = item;
    }
}

void desempilhar(struct tPilha *p) {
    if(!pilhaVazia(*p)) {
        p->topo -= 1;
    }
}

int main() {
    int n;
    char opc, item;
    struct tPilha p;

    scanf("%d", &n);

    p = criarPilha(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf(" %c", &item);
        }

        switch(opc) {
            case 'E':
                empilhar(&p, item);
                break;

            case 'D':
                desempilhar(&p);
                break;
            
            case 'T':
                if(!pilhaVazia(p)) {
                    printf("%c\n", topo(p));
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