#include <SPI.h>
#include <LoRa.h>
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
//moist
int sensor_pin = A1;
int output_value ;

//ldr
int ldr_sensor_pin = A2;
int ldr_value ;

dht DHT;


int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  
  Serial.print("Sending packet: ");
  Serial.println(counter);

// moist

 output_value= analogRead(sensor_pin);

   //output_value = map(output_value,550,0,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   LoRa.beginPacket();
   LoRa.print("Mositure : ");
   LoRa.print(output_value);
   Serial.print("  ");
   
// ldr 
ldr_value = analogRead(ldr_sensor_pin);
Serial.print("LDR : "); 
Serial.print(ldr_value);
Serial.print("  ");
LoRa.print("LDR : ");
LoRa.print(ldr_value);
LoRa.print("  ");


//dht DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("% ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    

    LoRa.print("Current humidity = ");
    LoRa.print(DHT.humidity);
    LoRa.print("% ");
    LoRa.print("temperature = ");
    LoRa.print(DHT.temperature);
    LoRa.print("C  ");


  // send packet
 
  LoRa.print("hello ");
  LoRa.print(counter);
 LoRa.endPacket();

  counter++;

  delay(5000);
}
