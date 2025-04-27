#include <stdio.h>
#include <stdlib.h>

int altura(struct tNo* no) {
  int altEsq, altDir; //Qual altura do ramo esquerdo e direito
  if(no != NULL) {
    altEsq = altura(no->esquerda);
    altDir = altura(no->direita);
    return (altEsq > altDir ? altEsq : altDir) + 1;
  }
  return -1;
};

int fatorBalanceamento(struct tNo *no) { //quando chamar certeza que nao ta chamando NULL
  return altura(no->esquerda) - altura(no->direita);
};

void rotacionarEsquerda(struct tNo *no, struct tArvore *t) {
  struct tNo *pai = no->pai, *fDir = no->direita;

  if(pai != NULL) {
    if(pai->esquerda == no) {
      pai->esquerda = fDir;
    } else {
      pai->direita = fDir;
    }
  } else { //rotaciona raiz
    t->raiz = fDir; //no Pai passa a apontar para o imediatamente a direita
  }
  fDir->pai = pai;//no direito passa a apontar para o pai

  no->direita = fDir->esquerda; //Aqui começa a tratar as mudancas no fDir, que terá tratamento no fDir->esquerda
  if(fDir->esquerda != NULL) { //Ou seja, ocorre troca de posicoes. No passa a ser filho de fDir.
    fDir->esquerda->pai = no;
  }
  no->pai = fDir;
  fDir->esquerda = no;
}

void rotacionarDireita(struct tNo *no, struct tArvore *t) {
  struct tNo *pai = no->pai, *fEsq = no->esquerda;

  if(pai != NULL) {
    if(pai->esquerda == no) {
      pai->esquerda = fEsq;
    } else {
      pai->direita = fEsq;
    }
  } else {
    t->raiz = fEsq;
  }
  fEsq->pai = pai;

  no->esquerda = fEsq->direita;
  if(fEsq->direita != NULL) {
    fEsq->direita->pai = no;
  }
  no->pai = fEsq;
  fEsq->direita = no;
}

void balancearAVL(struct tNo *no, struct tArvore *t) {
  if(no != NULL) { //precisa garantir que quando chamar fator de balanceamento precisa garantir que o no nao seja nulo
    if(fatorBalanceamento(no) == -2) { //primeiro rotaciona a direita e depois a esquerda
      if(fatorBalanceamento(no->direita) == 1) {
        rotacionarDireita(no->direita, t);
      }
      rotacionarEsquerda(no, t);
    } else if(fatorBalanceamento(no) == 2) { //caso simetrico
      if(fatorBalanceamento(no->esquerda) == -1) {
        rotacionarEsquerda(no->esquerda, t);
      }
      rotacionarDireita(no, t);
    }

    balancearAVL(no->pai, t);
  }
}

// ao final de inserir utilizar balancearAVL(pai, t);
// ao final da remocao antes do filho->pai = NULL colocar balancearAVL(subs, t); -> precisa chamar o subs, pois ele
// que pode ter causado o desbalanceamento.
// remover um pai de 2 com uma subarvore direita funda , o remover sucessor/antecessor pode causar desbalanceamento na árvore?
// -------------------------------------------------------
//Atividade 3 - Insercao e Remocao da arvore bem feito.
// Nao cai AVL
// Individual
// Dado um no da arvore quero saber altura dele.
// Vai cair igual os dois ultimos exercicios.