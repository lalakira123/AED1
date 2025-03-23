#include <stdio.h>
#include <stdlib.h>

struct tPilha {
    float *itens;
    int tamanho;
    int topo;
};

struct tPilha criarPilha(int n) {
    struct tPilha p;
    p.itens = (float*)malloc(n * sizeof(float));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

int pilhaVazia(struct tPilha p) {
    return p.topo == -1;
}

int pilhaCheia(struct tPilha p) {
    return p.topo == p.tamanho-1;
}

void mostraBaseTopo(struct tPilha p) {
    int i;
    for(i=0; i<=p.topo; i++){
        if(p.itens[i] == (int)p.itens[i]) {
            printf("%d%s", (int)p.itens[i], i==p.topo?"\n":" ");
        } else {
            printf("%.1f%s", p.itens[i], i==p.topo?"\n":" ");
        }
    }
}

void mostraTopoBase(struct tPilha p) {
    int i;
    for(i=p.topo; i >= 0; i--) {
        if(p.itens[i] == (int)p.itens[i]) {
            printf("%d%s", (int)p.itens[i], i==0?"\n":" ");
        } else {
            printf("%.1f%s", p.itens[i], i==0?"\n":" ");
        }
    }
}

float mostraTopo(struct tPilha p) {
    return p.itens[p.topo];
}

void empilha(struct tPilha *p, float item) {
    if(!pilhaCheia(*p)) {
        p->itens[++p->topo] = item;
    }
}

void desempilha(struct tPilha *p) {
    if(!pilhaVazia(*p)) {
        p->topo--;
    }
}

int main() {
    int n;
    float item;
    char opc;
    struct tPilha p;

    scanf("%d", &n);

    p = criarPilha(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%f", &item);
        }

        switch(opc) {
            case 'E':
                empilha(&p, item);
                break;
            
            case 'D':
                desempilha(&p);
                break;
            
            case 'T':
                if(!pilhaVazia(p)) {
                    if(mostraTopo(p) == (int)mostraTopo(p)) {
                        printf("%d\n", (int)mostraTopo(p));
                    } else {
                        printf("%.1f\n", mostraTopo(p));
                    }
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
