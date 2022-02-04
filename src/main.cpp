#include <Arduino.h>
#include <MeAuriga.h>

MeLineFollower linefollower_9(9);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int sensorState = linefollower_9.readSensors();

  switch (sensorState)
  {
  case S1_IN_S2_IN:
    Serial.println("Sensor 1 and 2 are inside of black line");
    break;
  case S1_IN_S2_OUT:
    Serial.println("Sensor 2 is outside of black line");
    break;
  case S1_OUT_S2_IN:
    Serial.println("Sensor 1 is outside of black line");
    break;
  case S1_OUT_S2_OUT:
    Serial.println("Sensor 1 and 2 are outside of black line");
    break;
  default:
    break;
  }

  delay(200);
}
