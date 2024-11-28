#include "Coordenada.h"

#define MISSAO_MAX_COORDENADAS 16 // 0~255

enum MISSAO_STATUS
{
    PARADA,
    EXECUTANDO,
    FINALIZADA,
    RETORNO
};

class Missao
{
    MISSAO_STATUS status;

    unsigned char coordenada_atual_idx;
    unsigned char n_coordenadas;

    Coordenada coordenadas[MISSAO_MAX_COORDENADAS];
    Coordenada ponto_de_retorno;

    void SetCoordenada(Coordenada coord)
    {
        if(coordenada_atual_idx + 1 > n_coordenadas) // Não pode inserir mais coordenadas
            return;

        coordenada_atual_idx++;
        coordenadas[coordenada_atual_idx] = coord;
    }

    const Coordenada& GetAtualCoordenada()
    {
        return coordenadas[coordenada_atual_idx]; // TODO: Verificar por NULL
    }

    const Coordenada& GetProximaCoordenada()
    {
        if (coordenada_atual_idx + 1 > n_coordenadas) // Não há mais coordenadas
            return;

        return coordenadas[coordenada_atual_idx + 1];
    }
};