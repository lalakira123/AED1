#include <stdio.h>
#include <stdlib.h>

struct tItem {
    struct tItem *proximo;
    struct tItem *anterior;
    int chave;
};

struct tLista {
    struct tItem *primeiro;
    struct tItem *ultimo;
};

struct tItem * criarItem(int chave) {
    struct tItem *it = (struct tItem *)malloc(sizeof(struct tItem));
    if(it != NULL) {
        it->proximo = NULL;
        it->anterior = NULL;
        it->chave = chave;
    }
    return it;
}

struct tLista * criarLista() {
    struct tLista *l = (struct tLista *)malloc(sizeof(struct tLista));
    if(l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct tItem * primeiro(struct tLista *l) {
    return l->primeiro;
}

struct tItem * ultimo(struct tLista *l) {
    return l->ultimo;
}

void mostrarListaInicioFinal(struct tLista *l) {
    struct tItem *it = primeiro(l);

    while(it != NULL) {
        //printf("%d ", it->chave);
        printf("%d%s", it->chave, it->proximo==NULL?"\n":" ");
        it = it->proximo;
    }

    //printf("\n");
}

void mostrarListaFinalInicio(struct tLista *l) {
    struct tItem *it = ultimo(l);

    while(it != NULL) {
        //printf("%d ", it->chave);
        printf("%d%s", it->chave, it->anterior==NULL?"\n":" ");
        it = it->anterior;
    }

    //printf("\n");
}

void inserirItem(struct tLista *l, int chave) {
    struct tItem *anterior = NULL, *atual = primeiro(l);

    while(atual != NULL && atual->chave < chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    //if(atual != NULL && atual->chave == chave) return;

    struct tItem *novo = criarItem(chave);

    // inicio
    if (anterior == NULL) {
        novo->proximo = l->primeiro;
        if (l->primeiro != NULL) {
            l->primeiro->anterior = novo; //nao vazia
        } else {
            l->ultimo = novo; //vazia
        }
        l->primeiro = novo;
    }
    // final
    else if (atual == NULL) {
        anterior->proximo = novo;
        novo->anterior = anterior;
        l->ultimo = novo;
    }
    // meio
    else {
        novo->proximo = atual;
        novo->anterior = anterior;
        anterior->proximo = novo;
        atual->anterior = novo;
    }
}

void removerItem(struct tLista *l, int chave) {
    struct tItem *anterior = NULL, *atual = primeiro(l);

    while (atual != NULL && atual->chave < chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    //if (atual == NULL || atual->chave != chave) return;

    // inicio
    if (anterior == NULL) {
        l->primeiro = atual->proximo;
        if (l->primeiro != NULL) {
            l->primeiro->anterior = NULL;
        } else {
            l->ultimo = NULL; // Lista ficou vazia
        }
    }
    // final
    else if (atual->proximo == NULL) {
        anterior->proximo = NULL;
        l->ultimo = anterior;
    }
    // meio
    else {
        anterior->proximo = atual->proximo;
        atual->proximo->anterior = anterior;
    }

    free(atual);
}

int main() {
    char opc, lst;
    int valor;
    struct tLista *A = criarLista();
    struct tLista *B = criarLista();

    while(scanf(" %c", &opc) != EOF) {

        scanf(" %c", &lst);

        struct tLista *l = NULL;
        if(lst == 'A') l = A;
        else if(lst == 'B') l = B;

        if(opc == 'I' || opc == 'E') {
            scanf("%d", &valor);
            if(valor < 0) continue;
        }

        if (l != NULL) {
            switch(opc) {
                case 'I':
                    inserirItem(l, valor);
                    break;
    
                case 'E':
                    removerItem(l, valor);
                    break;
    
                case 'M':
                    mostrarListaInicioFinal(l);
                    break;
    
                case 'R':
                    mostrarListaFinalInicio(l);
                    break;
            }
        }
    }

    return 0;
}