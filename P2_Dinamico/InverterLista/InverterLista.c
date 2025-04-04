#include <stdio.h>
#include <stdlib.h>

struct tItem {
  int chave;
  struct tItem *proximo;
}

struct tLista {
  struct tItem *primeiro;
}

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
  struct tItem *anterior = NULL, *atual = primeiro(chave);
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

void mostrarLista(struct tLista *l) {
  struct tItem *it = primeiro(l);

  while(it != NULL) {
    printf("%d%s", it->chave, it->proximo==NULL?"\n":" ");
  } 
}

void insereCabeca(struct tLista *l, struct tItem *it) {
  struct tItem *node = primeiro(l);
  it->proximo = node;
  l->primeiro = it;
}

struct tLista * inverteLista(struct tLista *l) {
  struct tItem *atual = primeiro(l);
  struct tLista *li = criarLista();
  while(atual != NULL) {
    insereCabeca(li, atual->chave);
  }
  return li;
}

int main() {
  int nL, nE, e;
  struct tLista *li;
  scanf("%d", &nL);

  int i;
  for(i = 0; i < nL; i++) {
    struct tLista *l = criarLista();
    scanf("%d", &nE);
    int j;
    for(j = 0; j < nE; j++) {
      scanf("%d", &e);
      inserir(l, e);
    }
    li = inverterLista(l);
    mostrarLista(li);
  }
  
  return 0;
}