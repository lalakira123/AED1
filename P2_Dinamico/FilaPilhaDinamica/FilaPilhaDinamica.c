#include <stdio.h>
#include <stdlib.h>

struct tItem {
  int chave;
  struct tItem *proximo;
};

struct tFila {
  struct tItem *primeiro;
  struct tItem *ultimo;
};

struct tPilha {
  struct tItem *topo;
};

struct tItem * criarItem(int chave) {
  struct tItem *it = (struct tItem *)malloc(sizeof(struct tItem));
  if(it != NULL) {
    it->chave = chave;
    it->proximo = NULL;
  }
  return it;
}

struct tFila * criarFila() {
  struct tFila *f = (struct tFila *)malloc(sizeof(struct tFila));
  if(f != NULL) {
    f->primeiro = NULL;
    f->ultimo = NULL;
  }
  return f;
}

struct tPilha * criarPilha() {
  struct tPilha *p = (struct tPilha *)malloc(sizeof(struct tPilha));
  if(p != NULL) {
    p->topo = NULL;
  }
  return p;
}

int filaVazia(struct tFila *f) {
  return f->primeiro == NULL && f->ultimo == NULL;
}

struct tItem * primeiro(struct tFila *f) {
  return f->primeiro;
}

struct tItem * ultimo(struct tFila *f) {
  return f->ultimo;
}

struct tItem * topo(struct tPilha *p) {
  return p->topo;
}

void inserirFila(struct tFila *f, int chave) {
  struct tItem *novo = criarItem(chave);

  if(!filaVazia(f)) {
    f->ultimo->proximo = novo;
  } else {
    f->primeiro = novo;
  }

  f->ultimo = novo;
}

void desenfileirar(struct tFila *f) {
  struct tItem *it = primeiro(f);

  if(!filaVazia(f)) {
    f->primeiro = it->proximo;
    if(f->primeiro == NULL) {
      f->ultimo = NULL;
    }
    it->proximo = NULL;
  }
}

void mostrarPilha(struct tPilha *p) {
  struct tItem *t = topo(p);

  while(t != NULL) {
    printf("%d\n", t->chave);
    t = t->proximo;
  }
}

struct tPilha * filaParaPilha(struct tFila *f) {
  struct tItem *it = primeiro(f);
  struct tPilha *p = criarPilha();

  p->topo = it;

  f->primeiro = NULL;
  f->ultimo = NULL;

  return p;
}

int main() {
  char opc;
  int valor;
  struct tFila *f;
  struct tPilha *p;

  f = criarFila();

  while(scanf(" %c", &opc) != EOF) {
    if(opc == 'E') {
      scanf("%d", &valor);
    }

    switch (opc) {
      case 'E':
        inserirFila(f, valor);
        break;

      case 'D':
        desenfileirar(f);
        break;

      case 'P':
        p = filaParaPilha(f);
        break;

      case 'M':
        mostrarPilha(p);
        break;
    }
  } 
}