#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de uma lista encadeada
typedef struct Node {
    int value;
    struct Node* next;
} Node;


// Função para criar um novo nó
Node* create_node(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}


// Função para adicionar um novo nó em ordem crescente
void insert_node(Node** head, int value) {
    Node* node = create_node(value);
    if (*head == NULL || value < (*head)->value) {
        node->next = *head;
        *head = node;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}


// Função para realizar o merge de duas listas encadeadas em ordem crescente
Node* merge_lists(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->value < l2->value) {
        l1->next = merge_lists(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_lists(l1, l2->next);
        return l2;
    }
}


// Função para realizar o merge de uma lista encadeada em ordem crescente
Node* merge_klists(Node** lists, int k) {
    Node* result = lists[0];
    for (int i = 1; i < k; i++) {
        result = merge_lists(result, lists[i]);
    }
    return result;
}


// Função que lê a lista no formato [[1,3,8],[1,3,6],[8,9]]
// Transforma a lista em um array de listas encadeadas
Node** read_lists(int* k) {
    char input[1000];
    printf("listas = ");
    fgets(input, 1000, stdin);

    char* token = strtok(input, "[], \n");
    Node** lists = NULL;
    *k = 0;
    while (token != NULL) {
        if (*k == 0) {
            lists = (Node**) malloc(sizeof(Node*) * 1);
        } else {
            lists = (Node**) realloc(lists, sizeof(Node*) * (*k + 1));
        }

        lists[*k] = NULL;
        int j = 0;

        while (token != NULL && token[0] != '[' && token[0] != ']') {
            insert_node(&lists[*k], atoi(token));
            j++;
            token = strtok(NULL, "[], \n");
        }

        (*k)++;
        token = strtok(NULL, "[],\n");
    }

    return lists;
}


// Função para imprimir os elementos de uma lista
void print_list(Node* head) {
    printf("[");
    while (head) {
        printf("%d", head->value);
        head = head->next;
        if (head) printf(", ");
    }
    printf("]\n");
}


int main(int argc, char const *argv[]) {
    int k = 0;

    // Lê a lista no formato [[1,3,8],[1,3,6],[8,9]]
    Node** lists = read_lists(&k);

    // Realiza o merge das listas e imprime o resultado
    Node* merged_list = merge_klists(lists, k);
    print_list(merged_list);

    // Libera a memória alocada para as listas encadeadas
    for (int i = 0; i < k; i++) {
        Node* current = lists[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(lists);

    return 0;
}
