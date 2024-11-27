class Coordenada
{
    int latitude; int longitude;
};

#define MISSAO_MAX_COORDENADAS 10

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

    unsigned int coordenada_atual;
    Coordenada coordenadas[MISSAO_MAX_COORDENADAS];

    Coordenada ponto_de_retorno;
};