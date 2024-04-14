## Implementação de uma Árvore AVL em C

Este programa implementa uma Árvore AVL em linguagem C, uma estrutura de dados que mantém a sua altura balanceada para garantir operações eficientes de busca, inserção e remoção. Através de rotações simples e duplas, o programa mantém a árvore balanceada após cada inserção de nó, garantindo que o fator de balanceamento de cada nó seja mantido dentro dos limites definidos. Além disso, o código inclui uma função para imprimir a árvore em ordem, permitindo a visualização das chaves em ordem crescente.

### Funcionalidades Implementadas

- **Inserção de Nós**: A inserção de novos nós na Árvore AVL é realizada de forma a manter o balanceamento da árvore após cada inserção. Isso é alcançado por meio de rotações simples e duplas conforme necessário para ajustar o fator de balanceamento dos nós.
  
- **Remoção de Nós**: A remoção de nós da Árvore AVL também é implementada para manter o balanceamento da estrutura. Após a remoção de um nó, verifica-se e ajusta-se o balanceamento da árvore conforme necessário.

- **Rotações**: O programa inclui funções para realizar rotações simples (à esquerda e à direita) e rotações duplas (combinando rotações simples) quando necessário para balancear a árvore.

- **Impressão em Ordem**: Uma função é implementada para imprimir os nós da árvore em ordem (in-ordem), o que permite visualizar as chaves da árvore em ordem crescente.

### Utilização da Implementação

Para utilizar esta implementação da Árvore AVL em seu programa, você pode seguir os seguintes passos:

1. **Incluir o Código na Seção do seu Projeto**: Copie e cole o código da implementação da Árvore AVL na seção do seu projeto em C.

2. **Inserir e Manipular Nós na Árvore**: Utilize as funções disponíveis para inserir nós na árvore, remover nós da árvore e realizar outras operações de manipulação.

3. **Imprimir a Árvore em Ordem**: Utilize a função de impressão em ordem para visualizar as chaves da árvore em ordem crescente.

### Exemplo de Uso

Aqui está um exemplo simplificado de como você pode usar esta implementação da Árvore AVL em seu programa:

```c
#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da Árvore AVL
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Funções para manipulação da Árvore AVL
void insert(Node **root, int key);
void remove(Node **root, int key);
void printInOrder(Node *root);

// Função principal para demonstração
int main() {
    Node *root = NULL;

    // Inserção de alguns nós na árvore
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);

    // Impressão dos nós em ordem (ordem crescente das chaves)
    printf("Árvore AVL em ordem crescente: ");
    printInOrder(root);
    printf("\n");

    return 0;
}
```

Neste exemplo simplificado, nós inserimos alguns valores na Árvore AVL e então imprimimos os nós em ordem crescente utilizando a função `printInOrder`. Você pode expandir este exemplo adicionando mais operações e manipulações na árvore conforme necessário para o seu projeto.

Esta implementação serve como base para estruturas de dados mais complexas e pode ser adaptada e estendida de acordo com os requisitos específicos do seu programa.
