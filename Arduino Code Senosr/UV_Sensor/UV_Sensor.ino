int senpin = A0;
int opt_val;
void setup() {
  Serial.begin(9600); // baud rate 9600 bps
  Serial.println("reading the values from sensor");
  delay(2000);
}

void loop() {
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
  int sensorValue = analogRead(0);
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

}
