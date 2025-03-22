#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLista {
    char **itens;
    int tamanho;
    int quantidade;
};

struct tLista criarLista(int n) {
    struct tLista l;
    l.itens = (char**)malloc(n * sizeof(char*));
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
    for (int i = 0; i < l.quantidade; i++) {
        printf("%s%s", l.itens[i], i == l.quantidade - 1 ? "\n" : " ");
    }
}

int buscaLista(struct tLista l, char *chave) {
    for (int i = 0; i < l.quantidade; i++) {
        if (strcmp(l.itens[i], chave) == 0) {
            return i;
        }
    }
    return -1;
}

void inserirLista(struct tLista *l, char *chave) {
    if (!listaCheia(*l)) {
        int i, j;
        char *novaChave = strdup(chave);

        for (i = 0; i < l->quantidade && strcmp(l->itens[i], chave) < 0; i++);
        for (j = l->quantidade; j > i; j--) {
            l->itens[j] = l->itens[j - 1];
        }

        l->itens[i] = novaChave;
        l->quantidade++;
    }
}

void removerItem(struct tLista *l, int iChave) {
    if (!listaVazia(*l) && iChave != -1) {
        free(l->itens[iChave]);
        for (int i = iChave; i < l->quantidade; i++) {
            l->itens[i] = l->itens[i + 1];
        }
        l->quantidade--;
    }
}

int main() {
    int n, iChave;
    char chave[101], opc;
    struct tLista l;

    scanf("%d", &n);
    l = criarLista(n);

    while (scanf(" %c", &opc) != EOF) {
        if (opc == 'I' || opc == 'B' || opc == 'R') {
            scanf("%100s", chave);
        }

        switch (opc) {
            case 'I':
                if (buscaLista(l, chave) == -1) {
                    inserirLista(&l, chave);
                }
                break;
            case 'R':
                iChave = buscaLista(l, chave);
                if (iChave != -1) {
                    removerItem(&l, iChave);
                }
                break;
            case 'B':
                printf("%s", buscaLista(l, chave) == -1 ? "NAO\n" : "SIM\n");
                break;
            case 'M':
                mostrarLista(l);
                break;
        }
    }
    
    return 0;
}
