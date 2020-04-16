#define SensorPin A0

void setup() {
Serial.begin(9600);

}

void loop() {
float senvolt; // var for sensor voltage
float sres; //sensor resistance
float senval;
float gasval;
int i;
for(i-0;i<200;i++)
{
  senval = senval + analogRead(A0);
}
senval = senval /500 ;
senvolt = senval * (5.0 / 1023) ;  //avg to volts
sres = ((5.0*10.0) / senvolt) - 10; //resistance in air
 gasval = sres  / 4.4 ; 
 Serial.print("Gas Val:");
 Serial.println(gasval);
 delay(2000);
}
