#include <stdio.h>
#include <stdlib.h>

// Armazena um nodo
typedef struct nodo {
    int valor;
    struct nodo* prox;
} Nodo;

/** Armazena os controles da lista */
typedef struct {
    Nodo* cabeca;
    Nodo* cauda;
    int tamanho;
} Lista;

/** Inicializa uma nova lista */
Lista* novaLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->tamanho = 0;
    return lista;
}

/** Adiciona um novo valor no final da lista */
void adiciona(Lista* lista, int valor) {
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->prox = NULL;

    if (lista->cabeca == NULL) {
        // Lista vazia
        lista->cabeca = nodo;
    } else {
        // Faz a cauda atual apontar para o novo nodo
        lista->cauda->prox = nodo;
    }

    //Atualiza a cauda e aumenta o tamanho
    lista->cauda = nodo;
    lista->tamanho++;
}

int main() {
    Lista* lista = novaLista();
    adiciona(lista, 10);
    adiciona(lista, 20);
    adiciona(lista, 30);
    printf("A lista tem %d elementos\n", lista->tamanho);

    Nodo* nodo = lista->cabeca;
    printf("Elementos:\n");
    while (nodo != NULL) {
        printf("* %d\n", nodo->valor);
        nodo = nodo->prox;
    }

    nodo = lista->cabeca;
    
    while (nodo != NULL)
    {
      Nodo* prox = nodo->prox;
      free(nodo);
      nodo = prox;
    }

    return 0;
}
