#include "Coordenada.h"
#include "math.h"
#include "Arduino.h"


Coordenada::Coordenada()
{
  this->latitude=0;
  this->longitude=0;
}

Coordenada::Coordenada(double lat, double lon)
{
  this->latitude=lat;
  this->longitude=lon;
}

double Coordenada::distancia(Coordenada outra)
{
      // Calcula a distância utilizando o Teorema de Pitágoras
      double distancia = sqrt( pow(outra.latitude  - this->latitude , 2) + 
                               pow(outra.longitude - this->longitude, 2));
      return distancia*100000;
}

double Coordenada::calcularAngulo(Coordenada outra) 
{
    // Calcula o ângulo utilizando a função atan2
    double anguloRadianos = atan2(outra.longitude - this->longitude, outra.latitude - this->latitude);
    // Converte o ângulo de radianos para graus
    double anguloGraus = anguloRadianos * (180.0 / PI);
    return anguloGraus;
}

void Coordenada::setLatitude(double lat)
{
  this->latitude=lat;
}
void Coordenada::setLongitude(double lon)
{
  this->longitude=lon;
}

double Coordenada::getLatitude()
{
  return this->latitude;
}

double Coordenada::getLongitude()
{
  return this->longitude;
}

