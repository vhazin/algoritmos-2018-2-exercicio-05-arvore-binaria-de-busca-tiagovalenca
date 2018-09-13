#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
  int data;
  struct Elemento *direita;
  struct Elemento *esquerda;
}elemento;

elemento *criarArvore(int data){
  elemento *temp;
  temp = malloc(sizeof(elemento));
  temp -> direita = NULL;
  temp -> esquerda = NULL;
  temp -> data = data;
  return(temp);
}

elemento *addArvore(elemento *elemento, int data){
  
  if(elemento == NULL){
    return(criarArvore(data));
  }
  if(data < elemento->data){
    elemento -> esquerda = addArvore(elemento->esquerda, data);
  }else if(data > elemento->data){
    elemento -> direita = addArvore(elemento->direita, data);
  }

  return(elemento);
}

void emOrdem(elemento *root)
{
    if (root != NULL)
    {
      emOrdem(root->esquerda);
      printf(" %d", root->data);
      emOrdem(root->direita);
    }
}

void pre(elemento *root){
  if (root != NULL){
    printf(" %d", root->data);
    pre(root->esquerda);
    pre(root->direita);
  }
}

void pos(elemento *root){
  if(root != NULL){
    pos(root->esquerda);
    pos(root->direita);
    printf(" %d", root->data);
  }
}

int main(void) {

  int iteracoes;
  int numeros, data;
  elemento *root = NULL;
  scanf("%d", &iteracoes);

  for(int i = 1; i <= iteracoes; i++){
    scanf("%d", &numeros);
    elemento *temp = root;
    root = NULL;
    free(temp);

    for(int j = 1; j <= numeros; j++){
      scanf("%d", &data);
      root = addArvore(root, data);
    }

    printf("Case %d:\n", i);
    printf("Pre.:");
    pre(root);
    printf("\n");
    printf("In..:");
    emOrdem(root);
    printf("\n");
    printf("Post:");
    pos(root);
    printf("\n\n");
  }

  return 0;
}
