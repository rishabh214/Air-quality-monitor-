#include <ThingSpeak.h>

#include <WiFi.h>
#include <WebServer.h>
String apiKey = "ESP8IYNOWSS3Q89R"; // Enter your Write API key from ThingSpeak
const char *ssid = "Rahul"; // replace with your wifi ssid and wpa2 key
const char *pass = "1234xtra3465";
const char* server = "api.thingspeak.com";
const int potPin = 4;
WiFiClient client;
void setup()
{
Serial.begin(115200);
delay(10);
Serial.println("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.print("Got IP: ");  
Serial.println(WiFi.localIP());

}
void loop()
{
float h = analogRead(potPin);
if (isnan(h))
{
Serial.println("Failed to read from MQ-5 sensor!");
return;
}

if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
{
String postStr = apiKey;
postStr += "&field1=";
postStr += String(h/1023*100);
postStr += "r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
Serial.print("Gas Level: ");
Serial.println(h);
//Serial.println(h/1023*100);
Serial.println("Data Send to Thingspeak");
}
client.stop();
Serial.println("Waiting...");

// thingspeak needs minimum 15 sec delay between updates.
delay(15100);
}
