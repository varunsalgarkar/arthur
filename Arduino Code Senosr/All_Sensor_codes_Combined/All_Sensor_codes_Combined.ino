#include <Adafruit_BMP280.h>
#include <DallasTemperature.h>
#include <OneWire.h>

BMP280 bmp;

int phSensorPin = A0;
int MoistSensorPin = A1;
int UVSensorPin = A2;
int MethaneSensorPin = A3;
int ONE_WIRE_BUS = A4;

long int avgval;
float b;
int buf[10] , temp ; //pH sensor

int op_val; //Moist Sensor

float senvolt; // var for sensor voltage
float sres; //sensor resistance
float Methsenval;
float gasval; //Methane Sensor 


int opt_val; //UV sensor

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire
); //Temperature Sensor
void setup() {
   Serial.begin(9600);
   Serial.println("reading the values from sensors");
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,    
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500);

  delay(2000);

}

void loop() {
   //pH Code
  int i;
  int j;
  avgval=0;
  for(i=0;i<10;i++)
  {
    buf[i]==analogRead(phSensorPin);
    delay(10);
  }
  for(i=0;i<9;i++)
  {
   avgval+=buf[i];
  }

float pHValue ;
pHValue = avgval*5/1024/4; // analoag to milivolt
pHValue= 3.5 * pHValue; // milivolt to pH
Serial.print(" pH: ") ;
Serial.print(pHValue,2); //pH code end

//Moisture Sensor
 op_val=analogRead(MoistSensorPin);
  op_val=map(op_val,550,10,0,100); //550 and 10 are readings from dry soil and wet soil respectively
  Serial.print("Moisture : ");
  Serial.print(op_val);
//Moisture Sensor End

 //UV sensor
int stringLength = 0;
 opt_val = analogRead(0);
 Serial.print("UV Radiation :");
String UV = readsensor();
Serial.print(UV);
 Serial.println(opt_val);
 delay(200);
}

String readsensor()
{
  String UVIndex = " 0" ;
  int sensorValue = analogRead(UVSensorPin);
  int voltage = (sensorValue * (5.0 / 1023.0))*1000 ;// Voltage in milivolts
  if(voltage<50)
  {
    UVIndex = "0";
  }else if (voltage>50 && voltage<=227)
  {
    UVIndex = "0";
  }else if (voltage>227 && voltage<=318)
  {
    UVIndex = "1";
  }
  else if (voltage>318 && voltage<=408)
  {
    UVIndex = "2";
  }else if (voltage>408 && voltage<=503)
  {
    UVIndex = "3";
  }
  else if (voltage>503 && voltage<=606)
  {
    UVIndex = "4";
  }else if (voltage>606 && voltage<=696)
  {
    UVIndex = "5";
  }else if (voltage>696 && voltage<=795)
  {
    UVIndex = "6";
  }else if (voltage>795 && voltage<=881)
  {
    UVIndex = "7";
  }
  else if (voltage>881 && voltage<=976)
  {
    UVIndex = "8";
  }
  else if (voltage>976 && voltage<=1079)
  {
    UVIndex = "9";
  }
  else if (voltage>1079 && voltage<=1170)
  {
    UVIndex = "10";
  }else if (voltage>1170)
  {
    UVIndex = "11";
  }
  return UVIndex;
//UV sensor end

//Methane Sensor
int j;
for(j-0;j<200;j++)
{
  Methsenval = Methsenval + analogRead(A0);
}
Methsenval = Methsenval /500 ;
senvolt = Methsenval * (5.0 / 1023) ;  //avg to volts
sres = ((5.0*10.0) / senvolt) - 10; //resistance in air
 gasval = sres  / 4.4 ; 
 Serial.print("Gas Val:");
 Serial.println(gasval);
//Methane Sensor End

 //Pressure Sensor
 Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure()/100); //displaying the Pressure in hPa
    Serial.println(" hPa");
    Serial.println();
 

 //Pressure Sensor End

 //Temperature Sensor
Serial.print(" Tempratures :");
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(A4));
  


 //Temperature Sensor End
delay(2000);
}
