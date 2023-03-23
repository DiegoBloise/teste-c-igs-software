#include <stdio.h>


void change_red_color(unsigned int init_color, unsigned int final_color, unsigned int steps) {
    // Extração dos valores dos canais RGBA de init_color e final_color
    unsigned int red_init    = (init_color  >> 16) & 0xFF;
    unsigned int red_final   = (final_color >> 16) & 0xFF;
    unsigned int green_init  = (init_color  >> 8)  & 0xFF;
    unsigned int green_final = (final_color >> 8)  & 0xFF;
    unsigned int blue_init   =  init_color         & 0xFF;
    unsigned int blue_final  =  final_color        & 0xFF;
    unsigned int alpha_init  = (init_color  >> 24) & 0xFF;
    unsigned int alpha_final = (final_color >> 24) & 0xFF;

    // Cálculo do incremento a ser aplicado em cada passo
    float delta_red   = (float)(red_final   - red_init)   / (float)steps;
    float delta_green = (float)(green_final - green_init) / (float)steps;
    float delta_blue  = (float)(blue_final  - blue_init)  / (float)steps;

    // Loop que imprime cada uma das cores intermediárias
    for (unsigned int i = 1; i < steps; i++) {
        unsigned int red   = (unsigned int)(red_init   + i * delta_red);
        unsigned int green = (unsigned int)(green_init + i * delta_green);
        unsigned int blue  = (unsigned int)(blue_init  + i * delta_blue);

        // Criação da cor com os valores RGB e Alpha inalterados
        unsigned int cor_intermediaria = (alpha_init << 24) + (red << 16) + (green << 8) + blue;

        // Impressão da cor intermediária como um valor hexadecimal
        printf("0x%06X\n", cor_intermediaria);
    }

    // Impressão da cor final
    printf("0x%06X\n", final_color);
}


int main(int argc, char const *argv[]) {
    unsigned int init_color  = 0x00001A;
    unsigned int final_color = 0xFF001A;
    unsigned int steps       = 3;

    printf( "cor_inicial = 0x%06X\n"
            "cor_final   = 0x%06X\n"
            "steps       = %d\n\n"
            "output:\n",
            init_color, final_color, steps
    );

    change_red_color(init_color, final_color, steps);

    return 0;
}
