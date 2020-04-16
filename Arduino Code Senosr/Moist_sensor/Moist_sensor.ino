int senpin = A0; 

int op_val; 
void setup() {
  Serial.begin(9600);
  Serial.println("reading the values from sensor");
  delay(2000);
}

void loop() 
{
  op_val=analogRead(senpin);
  op_val=map(op_val,550,10,0,100); //550 and 10 are readings from wet soil and dry soil respectively
  Serial.print("Moisture : ");
  Serial.print(op_val);
  delay(2000);
}
