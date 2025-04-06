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

int filaVazia(struct tFila *f) {
  return f->primeiro == NULL && f->ultimo == NULL;
}

struct tItem * primeiro(struct tFila *f) {
  return f->primeiro;
}

struct tItem * ultimo(struct tFila *f) {
  return f->ultimo;
}

void mostrarFila(struct tFila *f) {
  struct tItem *it = primeiro(f);

  while(it != NULL) {
    printf("%d%s", it->chave, it->proximo==NULL?"\n":" ");
    it = it->proximo;
  }
}

void inserirFila(struct tFila *f, int chave) {
  struct tItem *novo = criarItem(chave);

  if(filaVazia(f)) {
    f->primeiro = novo;
  } else {
    f->ultimo->proximo = novo;
  }

  f->ultimo = novo;
}

struct tItem * removerFila(struct tFila *f) {
  struct tItem *it = primeiro(f);

  if(!filaVazia(f)) {
    f->primeiro = it->proximo;
    if(f->primeiro == NULL) {
      f->ultimo = NULL;
    }
    it->proximo = NULL;
  }

  return it;
}

int main() {
  int valor;
  char opc;
  struct tItem *itRem;
  struct tFila *f = criarFila();

  while(scanf(" %c", &opc) != EOF) {
    if(opc == 'E') {
      scanf("%d", &valor);
    }

    switch(opc) {
      case 'E':
        inserirFila(f, valor); 
        break;

      case 'D':
        if(!filaVazia(f)) {
          itRem = removerFila(f);
          printf("<%d>\n", itRem->chave);
        }
        break;

      case 'M':
        mostrarFila(f);
        break;
    }
  }

  return 0;
}