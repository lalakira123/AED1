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

int listaVazia(struct tLista *l) {
    return l->primeiro == NULL;
}

void mostrarLista(struct tLista *l) {
    struct tItem *it = primeiro(l);
    while(it != NULL) {
        printf("%d%s", it->chave, it->proximo == NULL ? "\n" : " ");
        it = it->proximo;
    }
}

struct tItem * buscar(struct tLista *l, int chave) {
    struct tItem *it = primeiro(l);
    while(it != NULL && it->chave < chave) {
        it = it->proximo;
    }

    if(it != NULL && it->chave == chave) {
        return it;
    } else {
        return NULL;
    } 
}

void inserir(struct tLista *l, struct tItem *novo) {
    struct tItem *anterior = NULL, *atual = primeiro(l);

    while(atual != NULL && atual->chave < novo->chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual != NULL && atual->chave == novo->chave) return;

    novo->proximo = atual;
    if(anterior != NULL) {
        anterior->proximo = novo;
    } else { 
        l->primeiro = novo;
    }
}

void remover(struct tLista *l, int chave) {
    struct tItem *anterior = NULL, *atual = primeiro(l);

    while(atual != NULL && atual->chave < chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual != NULL && atual->chave == chave) {
        if(anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            l->primeiro = atual->proximo;
        }
    }
}

int main() {
    char opc;
    int chave;
    struct tItem *it;
    struct tLista *l = criarLista();

    while(scanf(" %c", &opc) != EOF) {
        if(opc == 'I' || opc == 'R' || opc == 'B') {
            scanf("%d", &chave);
        }

        switch(opc) {
            case 'I':
                it = criarItem(chave);
                inserir(l, it);
                break;
            
            case 'R':
                remover(l, chave);
                break;

            case 'B':
                it = buscar(l, chave);
                printf("%s\n", it==NULL?"NAO":"SIM");
                break;

            case 'L':
                mostrarLista(l);
                break;
        }
    }

    return 0;
}