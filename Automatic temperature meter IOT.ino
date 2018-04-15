#include<DHT.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const char*ssid="freewifi";
const char*password="freepassword";
WiFiClient client;
unsigned long myChannelNumber=292823;
const char * myWriteAPIKey="R1WCCO1BIDCJ8ATQ";
uint8_t temperature,humidity,k=0,l=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dht.begin();
delay(10);
Serial.println();
Serial.println();
Serial.print("Connecting to");
Serial.println(ssid);
WiFi.begin(ssid,password);
while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print("[.");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
static boolean data_state = false;
temperature=dht.readTemperature();
humidity=dht.readHumidity();
Serial.print(temperature);
Serial.println("C");
Serial.print("Humidity value is:");
Serial.print(humidity);
Serial.println("%");
if(temperature<255){
  k=temperature;
}
if(humidity<255){
  l=humidity;
}
if(data_state){
  ThingSpeak.writeField(myChannelNumber, 1,k,myWriteAPIKey);
data_state=false;
}
else{
  ThingSpeak.writeField(myChannelNumber,2,l,myWriteAPIKey);
  data_state=true;
}
delay(30000);
}
