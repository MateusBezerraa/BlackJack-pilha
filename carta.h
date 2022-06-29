#ifndef CARTA_H

    #define CARTA_H

    typedef struct carta_ CARTA;

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    CARTA* carta_criar(char *nype, char *simbolo);
    CARTA* carta_ler_std_in();
    int carta_apagar(CARTA **carta);
    void carta_printar(CARTA *carta);
    int carta_pegar_num(CARTA *carta);

#endif //CARTA_H
