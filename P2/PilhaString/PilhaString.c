#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tItem {
    char nome[100];
};

struct tPilha {
    struct tItem *itens;
    int tamanho;
    int topo;
};

struct tItem criarItem(char *nome)
{
    struct tItem it;
    strcpy(it.nome, nome);
    return it;
}

struct tPilha criarPilha(int n) {
    struct tPilha p;
    p.itens = (struct tItem *)malloc(n * sizeof(struct tItem));
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

struct tItem topo(struct tPilha p) {
    return p.itens[p.topo];
}

void mostraBaseTopo(struct tPilha p) {
    int i;
    for(i=0; i <= p.topo; i++) {
        printf("%s%s", p.itens[i].nome, i==p.topo?"\n":" ");
    }
}

void mostraTopoBase(struct tPilha p) {
    int i;
    for(i=p.topo; i >= 0; i--) {
        printf("%s%s", p.itens[i].nome, i==0?"\n":" ");
    }
}

void empilhar(struct tPilha *p, struct tItem item) {
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
    char opc, item[100];
    struct tPilha p;
    struct tItem it;

    scanf("%d", &n);

    p = criarPilha(n);

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'E') {
            scanf("%s", item);
        }

        switch(opc) {
            case 'E':
                empilhar(&p, criarItem(item));
                break;

            case 'D':
                desempilhar(&p);
                break;
            
            case 'T':
                if(!pilhaVazia(p)) {
                    printf("%s\n", topo(p).nome);
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