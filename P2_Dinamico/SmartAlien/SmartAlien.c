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

void mostrarTopoBase(struct tPilha *p) {
    struct tItem *t = topo(p);
  
    while(t != NULL) {
      printf("%d\n", t->chave);
      t = t->anterior;
    }
  }

void mostrarPilhaReversa(struct tItem *atual) {
    if (atual == NULL) return;
    mostrarPilhaReversa(atual->anterior);
    printf("%d\n", atual->chave);
}

void mostrarBaseTopo(struct tPilha *p) {
    mostrarPilhaReversa(topo(p));
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

int divisivelPrimo(int chave, int primo) {
    if(chave % primo == 0) {
        return 1;
    } else {
        return 0;
    }
}

int EhPrimo(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int proximoPrimo(int i) {
    int num = 2;
    int count = 0;
    
    while (count < i) {
        if (EhPrimo(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

void processarRodada(struct tPilha *A, int qtdRodadas, int count) {
    struct tPilha *Apoio = criarPilha();
    struct tPilha *B = criarPilha();

    int primo = proximoPrimo(count);

    while (topo(A) != NULL) {
        struct tItem *it = removerPilha(A);
        if(divisivelPrimo(it->chave, primo)) {
            inserirPilha(B, it->chave);
        } else {
            inserirPilha(Apoio, it->chave);
        }
    }

    mostrarTopoBase(B);

    while(topo(B) != NULL) {
        removerPilha(B);
    }

    if(count == qtdRodadas) {
        mostrarTopoBase(Apoio);

        while(topo(Apoio) != NULL) {
            removerPilha(Apoio);
        }
        return;
    }

    count++;
    return processarRodada(Apoio, qtdRodadas, count);
}

int main() {
  int valor, n, qtdRodadas;
  struct tPilha *A = criarPilha();

  scanf("%d", &n);
  scanf("%d", &qtdRodadas);

  int i;
  for(i = 0; i < n; i++) {
    scanf("%d", &valor);
    inserirPilha(A, valor);
  }

  processarRodada(A, qtdRodadas, 1);

  return 0;
}

