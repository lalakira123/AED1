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

  l->quantidade++;
}

int buscar(struct tLista *l, int chave) {
  struct tItem *it = primeiro(l);
  int count = 0;
  chave = l->quantidade - chave;
  while(it != NULL && count != chave) {
    it = it->proximo;
    count++;
  }

  if(it != NULL) {
    return it->chave;
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
    printf("%d\n", valor);
  }

  return 0;
}