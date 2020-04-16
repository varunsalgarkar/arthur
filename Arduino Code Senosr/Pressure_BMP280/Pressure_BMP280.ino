//Using I2C 
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
void setup() {
  Serial.begin(9600);
  Serial.println("BMP280 Readings");
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,    
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure()/100); //displaying the Pressure in hPa
    Serial.println(" hPa");
    Serial.println();
    delay(2000);
}
