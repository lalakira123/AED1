#include <stdio.h>
#include <stdlib.h>

struct tItem {
    char chave;
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

struct tItem * criarItem(char chave) {
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

void inserir(struct tLista *l, struct tItem *novo) {
    struct tItem *anterior = NULL, *atual = primeiro(l);

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

void mostrarLista(struct tLista *l) {
    struct tItem *it = primeiro(l);

    while(it != NULL) {
        printf("%c%s", it->chave, it->proximo == NULL ? "\n" : " ");
        it = it->proximo;
    }
}

int main() {
    char time;
    struct tLista *oitavas = criarLista();
    struct tLista *quartas = criarLista();
    struct tLista *semi = criarLista();
    struct tLista *final = criarLista();
    int valor1, valor2;

    char times[] = "ABCDEFGHIJKLMNOP";
    for (int i = 0; i < 16; i++) {
        inserir(oitavas, criarItem(times[i]));
    }

    struct tItem *it = primeiro(oitavas);
    while(it != NULL) {
      scanf("%d", &valor1);
      scanf("%d", &valor2);

      if(valor1 > valor2) {
        struct tItem *novo = criarItem(it->chave);
        inserir(quartas, novo);
        if(it != NULL) {
          it = it->proximo;
        }
        if(it != NULL) {
          it = it->proximo;
        }

      } else {
        it = it->proximo;
        struct tItem *novo = criarItem(it->chave);
        inserir(quartas, novo);
        if(it != NULL) {
          it = it->proximo;
        }
      }
    }

    it = primeiro(quartas);
    while(it != NULL) {
      scanf("%d", &valor1);
      scanf("%d", &valor2);

      if(valor1 > valor2) {
        struct tItem *novo = criarItem(it->chave);
        inserir(semi, novo);
        if(it != NULL) {
          it = it->proximo;
        }
        if(it != NULL) {
          it = it->proximo;
        }
      } else {
        it = it->proximo;
        struct tItem *novo = criarItem(it->chave);
        inserir(semi, novo);
        if(it != NULL) {
          it = it->proximo;
        }
      }
    }

    it = primeiro(semi);
    while(it != NULL) {
      scanf("%d", &valor1);
      scanf("%d", &valor2);

      if(valor1 > valor2) {
        struct tItem *novo = criarItem(it->chave);
        inserir(final, novo);
        if(it != NULL) {
          it = it->proximo;
        }

        if(it != NULL) {
          it = it->proximo;
        }
      } else {
        it = it->proximo;
        struct tItem *novo = criarItem(it->chave);
        inserir(final, novo);
        if(it != NULL) {
          it = it->proximo;
        }
      }
    }

    it = primeiro(final);
    while(it != NULL) {
      scanf("%d", &valor1);
      scanf("%d", &valor2);

      if(valor1 > valor2) {
        printf("%c\n", it->chave);
        it = NULL;
      } else {
        it = it->proximo;
        printf("%c\n", it->chave);
        it = NULL;
      }
    }

    return 0;
}