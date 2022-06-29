#include "carta.h"

typedef struct carta_
{
    char nype[8];
    char simbolo[3];
}CARTA;


CARTA* carta_criar(char *nype, char *simbolo)
{
    CARTA* carta = (CARTA*) malloc(sizeof(CARTA));

    if (carta != NULL)
    {
        strcpy(carta->nype, nype);
        
        if(strcmp(simbolo, "V") == 0 || strcmp(simbolo, "D") == 0 || strcmp(simbolo, "R") == 0)
        {
            strcpy(carta->simbolo, "10");
        }
        else
        {
            strcpy(carta->simbolo, simbolo);
        }
     
        return carta;
    }
    return NULL;
}

CARTA* carta_ler_std_in()
{
    CARTA carta;

    scanf("%8s %2s", carta.nype, carta.simbolo);

    return carta_criar(carta.nype, carta.simbolo);
}

int carta_apagar(CARTA **carta)
{
    if (*carta != NULL)
    {
        free (*carta);
        *carta = NULL;
        return 1;
    }
    return 0;
}

void carta_printar(CARTA *carta)
{
    printf("%s de %s\n", carta->simbolo, carta->nype);
}

int carta_pegar_num(CARTA *carta)
{
    int numero_da_carta = atoi(carta->simbolo);

    return numero_da_carta;
}
