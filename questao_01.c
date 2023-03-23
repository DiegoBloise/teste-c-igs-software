#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

// Função que inverte uma string
char *strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str) {
        return str;
    }

    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }

    return str;
}


int main(int argc, char const *argv[]) {
    FILE *file;
    char filename[] = "strings_01.txt";

    char buffer[MAX_LENGTH];
    char reversed_str[MAX_LENGTH];

    size_t max_palindrome_len = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", filename);
        return 1;
    } else {
        while (fgets(buffer, MAX_LENGTH, file) != NULL) {
            // Remove o caractere de quebra de linha
            char *c = strchr(buffer, '\n');
            if (c) *c = 0;

            // Copia a string para ser invertida
            strcpy(reversed_str, buffer);
            strrev(reversed_str);

            // Verifica se é um palíndromo e se é maior que o último
            if (strcmp(buffer, reversed_str) == 0 &&
                strlen(buffer) > max_palindrome_len) {
                max_palindrome_len = strlen(reversed_str);
            }
        }
    }

    printf("%zu", max_palindrome_len);

    fclose(file);

    return 0;
}
