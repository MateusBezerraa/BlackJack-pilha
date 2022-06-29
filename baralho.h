#ifndef BARALHO_H

    #include "carta.h"

    #define BARALHO_H

    
    typedef struct baralho_ BARALHO;
    typedef struct node_ NODE;

    BARALHO* baralho_criar();
    void baralho_apagar(BARALHO** baralho);
    int baralho_vazio(BARALHO* baralho);
    int baralho_tamanho(BARALHO* baralho);
    CARTA* baralho_topo(BARALHO* baralho);
    int baralho_empilhar(BARALHO* baralho, CARTA* carta);
    CARTA* baralho_desempilhar(BARALHO* baralho);
    



#endif //BARALHO_H
