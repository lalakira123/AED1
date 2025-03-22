#include <stdio.h>
#include <stdlib.h>

struct tLista {
    char *itens;
    int tamanho;
    int quantidade;
};

struct tLista criarLista(int n) {
    struct tLista l;
    l.itens = (char*)malloc(n * sizeof(char));
    l.tamanho = n;
    l.quantidade = 0;
    return l;
};

int listaVazia(struct tLista l) {
    return l.quantidade == 0;
}

int listaCheia(struct tLista l) {
    return l.quantidade == l.tamanho;
}

void mostrarLista(struct tLista l) {
    int i;
    for(i = 0; i < l.quantidade; i++) {
        printf("%c%s", l.itens[i], i==l.quantidade-1?"\n":" ");
    }
}

int buscaLista(struct tLista l, char chave) {
    int i;
    for(int i = 0; i < l.quantidade; i++) {
        if(l.itens[i] == chave) {
            return i;
        }
    }

    return -1;
}

void inserirLista(struct tLista *l, char chave) {
    int i, j;
    if(!listaCheia(*l)) {
        for(i=0; l->itens[i] < chave && i < l->quantidade; i++);
        for(j=l->quantidade - 1; j >= i; j--) {
            l->itens[j+1] = l->itens[j];
        }
        l->itens[i] = chave;
        l->quantidade += 1;
    }
}

void removerLista(struct tLista *l, int iChave) {
    int i;
    if(!listaVazia(*l) && iChave != -1) {
        for(i = iChave; i < l->quantidade; i++) {
            l->itens[i] = l->itens[i+1];
        }
        l->quantidade -= 1;
    }
} 

int main() {
    char opc, chave;
    int iChave, n;
    struct tLista l;

    scanf("%d", &n);

    l = criarLista(n);

    while(scanf(" %c", &opc) != EOF) {

        if(opc == 'I' || opc == 'B' || opc == 'R') {
            scanf(" %c", &chave);
        }

        switch(opc) {
            case 'I':
                if(listaVazia(l)) {
                    inserirLista(&l, chave);
                } else if(buscaLista(l, chave) == -1) {
                    inserirLista(&l, chave);
                }
                break;
            
            case 'R':
                removerLista(&l, buscaLista(l, chave));
                break;
            
            case 'B':
                iChave = buscaLista(l, chave);
                printf("%s", iChave==-1?"NAO\n":"SIM\n");
                break;

            case 'M':
                mostrarLista(l);
                break;
        }
    }

    return 0;
}