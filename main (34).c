#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da Árvore AVL
struct no {
    int info; // informação armazenada
    struct no *esq; // subárvore esquerda
    struct no *dir; // subárvore direita
    int fb; // fator de balanceamento
};

// Definição do tipo arvoreAVL como um ponteiro para a estrutura do nó
typedef struct no* arvoreAVL;

// Função para criar um novo nó
struct no* criarNo(int chave) {
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->info = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->fb = 0;
    return novo;
}

// Função para realizar a rotação simples à esquerda
arvoreAVL rotacaoEsquerda(arvoreAVL r) {
    arvoreAVL u = r->dir;
    arvoreAVL t2 = u->esq;
    u->esq = r;
    r->dir = t2;
    return u;
}

// Função para realizar a rotação simples à direita
arvoreAVL rotacaoDireita(arvoreAVL r) {
    arvoreAVL u = r->esq;
    arvoreAVL t2 = u->dir;
    u->dir = r;
    r->esq = t2;
    return u;
}

// Função para calcular a altura da árvore
int altura(arvoreAVL r) {
    if (r == NULL) return 0;
    int esq = altura(r->esq);
    int dir = altura(r->dir);
    return 1 + (esq > dir ? esq : dir);
}

// Função para calcular o fator de balanceamento de um nó
int calcularFB(arvoreAVL r) {
    if (r == NULL) return 0;
    return altura(r->esq) - altura(r->dir);
}

// Função para inserir um nó na árvore AVL
arvoreAVL inserir(arvoreAVL raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->info) {
        raiz->esq = inserir(raiz->esq, chave);
    } else if (chave > raiz->info) {
        raiz->dir = inserir(raiz->dir, chave);
    } else {
        // Chave já existe na árvore
        return raiz;
    }

    // Atualiza o fator de balanceamento do nó atual
    raiz->fb = calcularFB(raiz);

    // Realiza as rotações necessárias para manter a árvore AVL balanceada
    if (raiz->fb > 1 && chave < raiz->esq->info) {
        return rotacaoDireita(raiz);
    }
    if (raiz->fb < -1 && chave > raiz->dir->info) {
        return rotacaoEsquerda(raiz);
    }
    if (raiz->fb > 1 && chave > raiz->esq->info) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }
    if (raiz->fb < -1 && chave < raiz->dir->info) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para imprimir a árvore em pré-ordem
void imprimirInOrdem(arvoreAVL r) {
    if (r != NULL) {
        imprimirInOrdem(r->esq);
        printf("%d ", r->info);
        imprimirInOrdem(r->dir);
    }
}

// Função principal
int main() {
    arvoreAVL raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);

    printf("Árvore AVL em in-ordem: ");
    imprimirInOrdem(raiz);
    printf("\n");

    return 0;
}
