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

void mostrarLista(struct tLista *l) {
    struct tItem *it = primeiro(l);
    while(it != NULL) {
        printf("%d%s", it->chave, it->proximo == NULL ? "\n" : " ");
        it = it->proximo;
    }
}

void insertHead(struct tLista *l, int chave) {
    struct tItem *node = primeiro(l);
    struct tItem *it = criarItem(chave);
    
    it->proximo = node;
    l->primeiro = it;
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
            insertHead(l, elem);
        }

        mostrarLista(l);
    }

    return 0;
}