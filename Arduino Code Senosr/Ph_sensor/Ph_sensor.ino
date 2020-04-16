#define SensorPin 0
long int avgval;
float b;
int buf[10] , temp ;
void setup()
{
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int i;
  avgval=0;
  for(i=0;i<10;i++)
  {
    buf[i]==analogRead(SensorPin);
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
Serial.print(pHValue,2);
delay(2000);
}
