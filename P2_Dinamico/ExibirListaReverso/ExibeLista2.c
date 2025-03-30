#include <stdio.h>
#include <stdlib.h>

struct tItem {
    int chave;
    struct tItem *proximo;
};

struct tLista {
    struct tItem *primeiro;
};

struct tLista * criarLista() {
    struct tLista *l = (struct tLista *)malloc(sizeof(struct tLista));
    if(l != NULL) {
        l->primeiro = NULL;
    }
    return l;
}

struct tItem * criarItem(int chave) {
    struct tItem *it = (struct tItem *)malloc(sizeof(struct tItem));
    if(it != NULL) {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

struct tItem * primeiro(struct tLista *l) {
    return l->primeiro;
}

void mostrarListaReversa(struct tItem *atual) {
    if (atual == NULL) return;
    mostrarListaReversa(atual->proximo);
    printf("%d\n", atual->chave);
}

void mostrarListaInversa(struct tLista *l) {
    mostrarListaReversa(primeiro(l));
}

void insertTail(struct tLista *l, int chave) {
    struct tItem *anterior = NULL, *atual = primeiro(l);
    struct tItem *novo = criarItem(chave);

    while(atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior != NULL) {
        anterior->proximo = novo;
    } else {
        l->primeiro = novo;
    }
}

int main() {
    int nListas, nElem, elem;
    struct tLista *l;

    scanf("%d", &nListas);

    int i;
    for(i = 0; i < nListas; i++) {
        scanf("%d", &nElem);

        l = criarLista();

        int j;
        for(j = 0; j < nElem; j++) {
            scanf("%d", &elem);
            insertTail(l, elem);
        }

        mostrarListaInversa(l);
    }

    return 0;
}