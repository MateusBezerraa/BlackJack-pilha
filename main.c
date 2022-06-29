#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baralho.h"
#include "carta.h"

int main(void)
{

    BARALHO* baralho = baralho_criar();

    int n = 0;
    while(n < 52)
    {
        baralho_empilhar(baralho, carta_ler_std_in());
        n++;    
    }
    
    int resultado = 0;
    while(resultado < 21)
    {
        CARTA* carta = baralho_desempilhar(baralho);
        int num_da_carta = carta_pegar_num(carta);
        resultado += num_da_carta;
    }
        

    if(resultado == 21)
    {
        printf("Ganhou ;)");
    }
    else
    {
        printf("Perdeu :(\nSoma :: %d", resultado);
    }
    baralho_apagar(&baralho);
}
