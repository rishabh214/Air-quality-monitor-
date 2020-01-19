void setup() {
  Serial.begin(115200); //Baud rate 
  pinMode(34,INPUT);
}
 
void loop() { 
  float sensor_volt; //Define variable for sensor voltage 
  float RS_air; //Define variable for sensor resistance
  float R0; //Define variable for R0
  float sensorValue=0.0; //Define variable for analog readings 
  Serial.print("Sensor Reading = ");
  Serial.println(analogRead(34));
  
  for(int x = 0 ; x < 500 ; x++) //Start for loop 
  {
    sensorValue = sensorValue + analogRead(34); //Add analog values of sensor 500 times 
  }
  sensorValue = sensorValue/500.0; //Take average of readings
  Serial.print("Average = ");
  Serial.println(sensorValue);
  sensor_volt = sensorValue*(5.0/4095.0); //Convert average to voltage 
  RS_air = ((5.0*10.0)/sensor_volt)-10.0; //Calculate RS in fresh air 
  R0 = RS_air/3.7; //Calculate R0 
  Serial.println(sensorValue);

  Serial.print("sensor_volt");
  Serial.println(sensor_volt);
  Serial.print("RS_air");
  Serial.println(RS_air);

  Serial.print("R0 = "); //Display "R0"
  Serial.println(R0); //Display value of R0 
  delay(2000); //Wait 1 second    ////r0=11.14  sensor value= 750
 
}
