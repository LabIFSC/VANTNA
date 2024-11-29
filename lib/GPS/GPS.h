/**
 * Modelo: GY-NE06MV2
 */
#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define SS_RX_PIN 32
#define SS_TX_PIN 33

TinyGPS gps;
// SoftwareSerial ss(SS_RX_PIN, SS_TX_PIN); // Using Serial 1 instead

class GPS
{
public:
    void setUp()
    {
        Serial.begin(9600);
        Serial1.begin(4800);
    }

    void loop()
    {
        bool newData = false;
        unsigned long chars;
        unsigned short sentences, failed;

        // For one second we parse GPS data and report some key values
        for (unsigned long start = millis(); millis() - start < 1000;)
        {
            while (Serial1.available())
            {
                char c = Serial1.read();
                // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
                if (gps.encode(c)) // Did a new valid sentence come in?
                    newData = true;
            }
        }

        // Teste num of satellites
        // Serial.print(" SAT =");
        // Serial.println(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());

        if (newData) // false
        {
            float flat, flon;
            unsigned long age;
            gps.f_get_position(&flat, &flon, &age);
            Serial.print("LAT=");
            Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
            Serial.print(" LON=");
            Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
            Serial.print(" SAT=");
            Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
            Serial.print(" PREC=");
            Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
        }

        gps.stats(&chars, &sentences, &failed);
        Serial.print(" CHARS=");
        Serial.print(chars);
        Serial.print(" SENTENCES=");
        Serial.print(sentences);
        Serial.print(" CSUM ERR=");
        Serial.println(failed);
        if (chars == 0)
            Serial.println("** No characters received from GPS: check wiring **");
        }
};