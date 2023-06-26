#include <WiFi.h>
#include "ThingSpeak.h"


const char* ssid = "xxxxx";   // your network SSID (name) 
const char* password = "xxxxx";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "xxxxx";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000; 
//In this case, I am publishing readings every 30 seconds (30000 milliseconds). 

// Variable to hold temperature readings
float temperatureC;


float pH; 
float flow;

void setup() {
  Serial.begin(115200);  //Initialize serial
 
 
  WiFi.mode(WIFI_STA);   //Set the ESP32 as a Wi-Fi station
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  if ((millis() - lastTime) > timerDelay) { 
    // millis() Returns the number of milliseconds passed since the Arduino board began running
   //the current program.This number will overflow (go back to zero), after approximately 50 days.
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      
      Serial.print("Attempting to connect");
      
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      
      Serial.println("\nConnected.");
    }

    // Get a new temperature reading
    temperatureC = 76;
    Serial.print("Temperature (ºC): ");
    Serial.println(temperatureC);

    flow = 14;
    Serial.print("flow(cfs):");
    Serial.println(flow);

    pH=6.5;
    Serial.print("pH :");
    Serial.println(pH);
    
    
    ThingSpeak.setField(1,temperatureC);
    ThingSpeak.setField(2,flow);
    ThingSpeak.setField(3,pH);

    //This function returns the code 200 if it has succeeded in publishing the readings.
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
