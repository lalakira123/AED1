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

void inserir(struct tLista *l, int chave) {
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

int buscar(struct tLista *l, int chave) {
  struct tItem *it = primeiro(l);

  while(it != NULL && it->chave != chave) {
    it = it->proximo;
  }

  if(it != NULL && it->chave == chave) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int nL, nE, e, nP, valor;

  scanf("%d", &nL);

  int i;
  for(i = 0; i < nL; i++) {
    scanf("%d", &nE);
    struct tLista *l = criarLista();

    int j;
    for(j = 0; j < nE; j++) {
        scanf("%d", &e);
        inserir(l, e);
    }

    scanf("%d", &nP);
    valor = buscar(l, nP);
    printf("%d%s", valor, i==nL-1?"\n":" ");
  }

  return 0;
}