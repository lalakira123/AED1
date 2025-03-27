#include <stdio.h>
#include <stdlib.h>

struct tItem {
    int chave;
    struct tItem *proximo;
};

struct tLista {
    struct tItem *primeiro;
    int quantidade;
};

struct tLista * criarLista() {
    struct tLista *l = (struct tLista *)malloc(sizeof(struct tLista));
    if(l != NULL) {
        l->primeiro = NULL;
        l->quantidade = -1;
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

void insertPosition(struct tLista *l, int chave, int posicao) {
    struct tItem *anterior = NULL, *atual = primeiro(l);
    int count = 0;
    struct tItem *novo = criarItem(chave);

    while(atual != NULL && count != posicao && count - 1 <= l->quantidade) {
        anterior = atual;
        atual = atual->proximo;
        count++;
    }

    novo->proximo = atual;
    if(anterior != NULL) {
        anterior->proximo = novo;
    } else {
        l->primeiro = novo;
    }

    l->quantidade++;
}

int main() {
    int nElem, chave, pos;

    scanf("%d", &nElem);

    struct tLista *l = criarLista();

    int i;
    for(i = 0; i < nElem; i++) {
        scanf("%d", &chave);
        scanf("%d", &pos);

        insertPosition(l, chave, pos);
    }

    mostrarLista(l);

    return 0;
}
