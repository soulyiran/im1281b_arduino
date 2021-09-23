#include "IM1281B.h"
// use ESP32 Serial2(17(TX2),16(RX2)) port conneect to im1281 sensor
IM1281B im1281(&Serial2, 4800);
void setup()
{
    Serial.begin(9600);
    Serial.println("");
}

void loop()
{
    // updata power data from im1281 sensor
    im1281.update();
    // get Votage, Current data
    // can also get Power, Energy, Power Factor, CO2, Frequence data
    float Votage = im1281.getVotage();
    float Current = im1281.getCurrent();
    Serial.print("Votage:");
    Serial.print(Votage);
    Serial.print("     Current:");
    Serial.println(Current);
    
    delay(5*1000);
}