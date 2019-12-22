#include <DHTesp.h>

#include <Adafruit_Sensor.h>

#include <dht.h>


#define dht_apin 4 // Analog Pin sensor is connected to
 
dht DHT;

void setup(){
 
  Serial.begin(115200);
  delay(500);//Delay to let system boot
//  pinMode(sensorPin,INPUT);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
     DHT.read11(dht_apin);   
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(3000);//Wait 3 seconds before accessing sensor again.
 
 
}// end loop(
