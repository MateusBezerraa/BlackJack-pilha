#include "baralho.h"

#define ERRO -300

typedef struct node_     //lista encadeada que contem uma carta e a referencia para a carta anterior (mais perto da base)
{
    CARTA *carta;  
    NODE* anterior;
    
}NODE;


typedef struct baralho_           //struct que guarda o tamanho do baralho e a referencia do ultimo elemento inserido
{
    NODE* topo;
    int tamanho;
}BARALHO;



BARALHO* baralho_criar()
{
    BARALHO* baralho = (BARALHO*) malloc(sizeof(BARALHO));
    if(baralho != NULL)
    {
        baralho->topo = NULL;
        baralho->tamanho = 0;
    }
    return baralho;
}

void baralho_apagar(BARALHO **baralho)
{
    if(((*baralho) != NULL) && (!baralho_vazio(*baralho)))
    {
        NODE* aux;
        while ((*baralho)->topo != NULL)
        {
            aux = (*baralho)->topo;
            (*baralho)->topo = (*baralho)->topo->anterior;
            carta_apagar(&aux->carta);
            aux->anterior = NULL;
            free(aux); 
            aux = NULL;
        }
    }
    free(*baralho);
    *baralho = NULL;
}

int baralho_vazio(BARALHO *baralho)
{
    if(baralho != NULL)
    {
        int ret = baralho->tamanho == 0;
        return ret;
    }
    return ERRO;
}

int baralho_tamanho(BARALHO *baralho)
{
    if(baralho != NULL)
    {
        int ret = baralho->tamanho;
        return ret;
    }
    return ERRO;
}

CARTA* baralho_topo(BARALHO *baralho)
{
    if((baralho != NULL) && (!baralho_vazio(baralho)))
    {
        return (baralho->topo->carta);
    }
    return NULL;
}

int baralho_empilhar(BARALHO *baralho, CARTA *carta)
{
    if(baralho!=NULL)
    {
        NODE* novo = (NODE*) malloc(sizeof(NODE));
        if (novo != NULL)
        {
            novo->carta = carta;
            novo->anterior = baralho->topo;
            baralho->topo = novo;
            baralho->tamanho++;
            return(1);
        }
    }
    return(ERRO);
}

CARTA* baralho_desempilhar(BARALHO *baralho)
{
    if((baralho != NULL) && (!baralho_vazio(baralho)))
    {
        NODE* node = baralho->topo;
        CARTA* carta = baralho->topo->carta;
        baralho->topo = baralho->topo->anterior;
        node->anterior = NULL;
        free(node);
        node = NULL;
        baralho->tamanho--;
        return(carta);
    }
    return(NULL);
}
