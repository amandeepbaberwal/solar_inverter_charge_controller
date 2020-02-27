int RELAY_PIN = 12;
boolean isLoaded = false;
float input_voltage = 0.0;
float temp = 0.0;
float r1=100000.0;
float r2=10000.0;
float maxVolt = 30.5;
float minVolt = 23;
float d = 3000;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}
void calculate(){
  int analog_value = analogRead(A0);
  //Serial.println(analog_value);
  temp = (analog_value * 12.0) / 2450.24;
  input_voltage = temp / (r2/(r1+r2));
}

void loop() {
 calculate();
  if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   }
   if (input_voltage < minVolt) 
   {
      delay(1000);
      calculate();  
        if (input_voltage < minVolt) 
       {
         digitalWrite(RELAY_PIN, HIGH);
       }
   }
   if (input_voltage >= maxVolt) 
   {
      delay(1000);
      calculate(); 
       if (input_voltage >= maxVolt) 
      {
        digitalWrite(RELAY_PIN, LOW);
      }
   }
   Serial.print("v= ");
   Serial.println(input_voltage);
   delay(d);
}
