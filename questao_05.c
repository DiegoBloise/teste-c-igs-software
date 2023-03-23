#include <stdio.h>
#include <stdlib.h>

#define LINES  3
#define COLUMNS 5


int **create_slot(void) {
    int **slot = (int **) malloc(sizeof(int *) * LINES);

    for (int i = 0; i < LINES; i++) {
        slot[i] = (int *) malloc(sizeof(int) * COLUMNS);

        // Preenche a matriz linha a linha,
        // valores informados separados por espaço ou teclando enter
        printf("Insira os valores da linha %d: ", (i + 1));
        for (int j = 0; j < COLUMNS; j++) {
            scanf("%d", &slot[i][j]);
        }
    }

    return slot;
}


int main(int argc, char const *argv[]) {
    int prize[LINES][COLUMNS] = {
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int **slot = create_slot();
    int matches = 0;

    // Nested Loops que verifica o match, com poucas iterações
    for (int i = 0; i < LINES; i++) {
        if (i == 1 && matches < 2 || i == 2 && matches < 4) break;
        for (int j = 0; j < COLUMNS; j++) {
            matches += slot[i][j] * prize[i][j];
            if (matches == 5) break;
        }
    }

    // Importante ressaltar que o método de verificação ou comparação utilizado
    // pode mudar de acordo com o tipo de "desenho" ou valores da matriz.
    // Para matrizes maiores, uma abordagem mais eficiente seria o uso de ponteiros.

    // Exibir resultado e desalocação da memória
    if (matches == 5) {
        printf("Ganhou!\n");
    } else {
        printf("Nao Ganhou!\n");

        for (int i = 0; i < LINES; i++) {
            free(slot[i]);
        }
        free(slot);
    }

    return 0;
}
