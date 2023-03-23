#include <stdio.h>
#include <string.h>

// Função que converte de algarismos romanos para decimal
int roman_to_decimal(char roman_numeral[]) {
    int decimal_value = 0;
    int previous_value = 0;

    // Loop que analisa cada letra de trás para frente
    for (int i = strlen(roman_numeral)-1; i >= 0; i--) {
        int current_value = 0;

        // Dependendo da letra, é atribuido o valor correspondente em decimal em uma variavel
        switch (roman_numeral[i]) {
            case 'I': current_value = 1; break;
            case 'V': current_value = 5; break;
            case 'X': current_value = 10; break;
            case 'L': current_value = 50; break;
            case 'C': current_value = 100; break;
            case 'D': current_value = 500; break;
            case 'M': current_value = 1000; break;
            default : return -1;
        }

        // E realizado a operação de soma, ou subtração,
        // dependendo do valor anterior, se é menor, ou maior.
        if (current_value < previous_value) {
            decimal_value -= current_value;
        } else {
            decimal_value += current_value;
        }

        // Então o valor anterior é atualizado com o valor atual,
        // e segue para a proxima iteração do loop
        previous_value = current_value;
    }

    return decimal_value;
}


int main(int argc, char const *argv[]) {
    char roman_numeral[20];
    printf("Digite um numero romano: ");
    scanf("%s", roman_numeral);

    int decimal_value = roman_to_decimal(roman_numeral);
    printf("%s = %d\n", roman_numeral, decimal_value);

    return 0;
}
