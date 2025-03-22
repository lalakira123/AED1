#include <stdio.h>
#include <stdlib.h>

struct tLista {
    float *itens;
    int tamanho;
    int quantidade;
};

struct tLista criarListaVazia(int n) {
    struct tLista l;
    l.itens = (float*)malloc(n * sizeof(float));
    l.tamanho = n;
    l.quantidade = 0;
    return l;
}

int listaVazia(struct tLista l) {
    return l.quantidade == 0;
}

int listaCheia(struct tLista l) {
    return l.quantidade == l.tamanho;
}

void mostrarLista(struct tLista l) {
    for(int i = 0; i < l.quantidade; i++) {
        if(l.itens[i] == (int)l.itens[i]) {
            printf("%d%s", (int)l.itens[i], i==l.quantidade-1?"\n":" ");
        } else {
            printf("%.1f%s", l.itens[i], i==l.quantidade-1?"\n":" ");
        }
    }
}

int buscaLista(struct tLista l, float chave) {
    for(int i = 0; i < l.quantidade; i++) {
        if(l.itens[i] == chave) {
            return i;
        }
    }

    return -1;
}

void inserirLista(struct tLista *l, float chave) {
    int i, j;
    if(!listaCheia(*l)) {
        for(i=0; l->itens[i] < chave && i < l->quantidade; i++);
        for(j=l->quantidade-1; j >= i; j--) {
            l->itens[j+1] = l->itens[j];
        }
        l->itens[i] = chave;
        l->quantidade += 1;
    }
}

void removerItemLista(struct tLista *l, int iChave) {
    int i;
    if(!listaVazia(*l) && iChave != -1) {
        for(i=iChave; i < l->quantidade; i++) {
            l->itens[i] = l->itens[i+1];
        }
        l->quantidade -= 1;
    }
}

int main() {
    int n, iChave;
    float chave;
    struct tLista lista;
    char opc;

    scanf("%d", &n);

    lista = criarListaVazia(n);

    while(scanf(" %c", &opc) != EOF) {

        if(opc == 'I' || opc == 'R' || opc == 'B') {
            scanf("%f", &chave);
        }

        switch(opc) {
            case 'I': 
                if(listaVazia(lista)) {
                    inserirLista(&lista, chave);
                } else {
                    if(buscaLista(lista, chave) == -1) {
                        inserirLista(&lista, chave);
                    }
                }
                break;

            case 'R': 
                removerItemLista(&lista, buscaLista(lista, chave));
                break;
                
            case 'B': 
                iChave = buscaLista(lista, chave);
                printf("%s", iChave==-1?"NAO\n":"SIM\n");
                break;

            case 'M': 
                mostrarLista(lista);
                break;
        }
    }

    return 0;
}

