#include <stdio.h>
#include <stdlib.h>

struct tItem {
  int chave;
  struct tItem *anterior;
};

struct tPilha {
  struct tItem *topo;
};

struct tItem * criarItem(int chave) {
  struct tItem *it = (struct tItem *)malloc(sizeof(struct tItem));
  if(it != NULL) {
    it->chave = chave;
    it->anterior = NULL;
  }
  return it;
}

struct tPilha * criarPilha() {
  struct tPilha *p = (struct tPilha *)malloc(sizeof(struct tPilha));
  if(p != NULL) {
    p->topo = NULL;
  }
  return p;
}

int pilhaVazia(struct tPilha *p) {
  return p->topo == NULL;
}

struct tItem * topo(struct tPilha *p) {
  return p->topo;
}

void mostrarPilha(struct tPilha *p) {
  struct tItem *t = topo(p);

  while(t != NULL) {
    printf("%d%s", t->chave, t->anterior==NULL?"\n":" ");
    t = t->anterior;
  }
}

void inserirPilha(struct tPilha *p, int chave) {
  struct tItem *novo = criarItem(chave);

  novo->anterior = p->topo;
  p->topo = novo;
}

struct tItem * removerPilha(struct tPilha *p) {
  struct tItem *it = topo(p);

  if(!pilhaVazia(p)) {
    p->topo = it->anterior;
    it->anterior = NULL;
  }

  return it;
}

int main() {
  int valor;
  char opc;
  struct tItem *itRem;
  struct tPilha *p = criarPilha();

  while(scanf(" %c", &opc) != EOF) {
    if(opc == 'E') {
      scanf("%d", &valor);
    }

    switch(opc) {
      case 'E':
        inserirPilha(p, valor); 
        break;

      case 'D':
        itRem = removerPilha(p);
        if(itRem != NULL) {
          printf("[%d]\n", itRem->chave);
        }
        break;

      case 'M':
        mostrarPilha(p);
        break;
    }
  }

  return 0;
}

