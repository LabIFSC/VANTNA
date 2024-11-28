#include <Arduino.h>
#include "Bussola.h"
#include <HMC5883L_Simple.h>

Bussola::Bussola()
{
}

// Create a compass
HMC5883L_Simple Compass;

void Bussola::setUp()
{
  Compass.SetDeclination(23, 35, 'E');  
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
}

float Bussola::getAngulo()
{
 return   Compass.GetHeadingDegrees();
}
