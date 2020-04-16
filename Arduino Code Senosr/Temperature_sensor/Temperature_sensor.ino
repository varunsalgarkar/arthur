#include <DallasTemperature.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 2 //data wire plugged to pin2 of arduino
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire
);
void setup() 
{
  Serial.begin(9600);
  sensors.begin();
  
}

void loop() 
{
  Serial.print(" Tempratures :");
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  delay(1000);
}
