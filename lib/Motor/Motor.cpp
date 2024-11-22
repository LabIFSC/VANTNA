#include <Motor.h>
#include <Arduino.h>

Motor::Motor(int p1, int p2, int e)
    {
        this->p1=p1;
        this->p2=p2;
        this->enable=e;
    }

void Motor::setup()
    {
        pinMode(this->p1, OUTPUT);
        pinMode(this->p2, OUTPUT);
        pinMode(this->enable, OUTPUT);
    }
    
void Motor::gira_horario(int vel)
    {
        digitalWrite(this->p1,HIGH);
        digitalWrite(this->p2,LOW);
        analogWrite(this->enable,vel);
    }

void Motor::gira_antihorario(int vel)
    {
        digitalWrite(this->p1,LOW);
        digitalWrite(this->p2,HIGH);
        analogWrite(this->enable,vel);
    }
