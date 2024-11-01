#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Faculdade Impacta v2"; //Your Network SSID
const char* password = "impacta2021"; //Your Network Password
int val;
int LDRpin = A0; //LDR Pin Connected at A0 Pin

WiFiClient client;
unsigned long myChannelNumber = 2679240; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "G37S3ZXYX7HG5YVL"; //Your Write API Key

void setup()
{

Serial.begin(9600);
delay(10);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);

}

void loop()
{
val = analogRead(LDRpin); //Read Analog values and Store in val variable
Serial.print(val); //Print on Serial Monito
delay(1000);
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
delay(100);

}