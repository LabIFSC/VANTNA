#pragma once

class Coordenada
{
    private:
        double latitude; 
        double longitude;
    public:
        Coordenada();
        Coordenada(double lat, double lon);
        double distancia(Coordenada x);
        double calcularAngulo(Coordenada x);
        void setLatitude(double lat);
        void setLongitude(double lon);
        double getLatitude();
        double getLongitude();
};

