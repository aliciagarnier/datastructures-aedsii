#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;

struct no_ {
  int valor;
  no *prox;
};

no *topo = NULL;
/**
 *
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser inserido.
 * @return 1 caso seja possivel inserir, e 0 caso contrario.
 *
 */
void inserir (int valor) {
  no *novo = malloc(sizeof(no));
  novo->valor = valor;
  novo->prox = topo;
  topo = novo;
}

// TODO: implemente a funcao inserir.
// O cabecalho da funcao nao pode ser alterado.

/**
 *
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser removido.
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel
 * remover.
 */
no *remover() {
  no *removido = NULL;
  if (topo != NULL) { // a lista não está vazia, posso remover.
    removido = topo;
    topo = topo->prox;
  } else {
    printf("Não é possível remover\n");
  }
  return removido;
}
/**

 * @param topo = endereco do no topo.
 */
void escrever() {
  printf("[");
  no *atual = topo;

  while (atual != NULL) {
    printf("%d", atual->valor);
    if (atual->prox != NULL)
      printf(" -> ");

    atual = atual->prox;
  }
  printf("]\n\n");
}

/**
 *
 * @param cabeca = endereco do no cabeça.
 */
void desaloca_lista() {
  while (topo != NULL) {
    no *n = topo;
    topo = topo->prox;
    free(n);
  }
}

/**
 *
 * @return = ponteiro para o no cabeca alocado.
 */
no *aloca_no_cabeca() {
  no *cabeca = malloc(sizeof(no));
  cabeca->prox = NULL;
  return cabeca;
}

int main() {
  no *n;
  int valor = 2;
  int ans = 0;

  do {
    // Opcoes:
    // 0 -> inserir
    // 1 -> remover
    // 2 -> escrever
    // 3 -> sair
    scanf("%d", &ans);

    switch (ans) {
      // inserir
    case 0:
      scanf("%d", &valor);
      inserir(valor);
      break;
      // remover
    case 1:
      n = remover();
      if (n != NULL) { 
          free(n);
      }
      break;
      // escrever
    case 2:
      escrever();
      break;
      // sair
    case 3:
      desaloca_lista();

      break;
    default:

      break;
    }
  } while (ans != 3);

  return (0);
}
