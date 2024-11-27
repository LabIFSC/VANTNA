#define BUSSOLA_ANGULO_CORRECAO 0 // 0 ~ 359

class Bussola
{
    public:
        int direcao;
        int direcao_ant;
        int direcao_delta;

        int periodo_ms;

    private:
        // amostragem da bussula

        /** 
         * Calcula o delta da direção
         */
        void processar();
};