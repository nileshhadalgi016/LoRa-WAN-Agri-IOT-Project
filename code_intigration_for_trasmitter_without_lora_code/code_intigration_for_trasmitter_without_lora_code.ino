



#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to

//moist
int sensor_pin = A1;
int output_value ;

//ldr
int ldr_sensor_pin = A2;
int ldr_value ;

dht DHT;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:


// moist

 output_value= analogRead(sensor_pin);

   //output_value = map(output_value,550,0,0,100);

   Serial.print("Mositure : ");

   Serial.print(output_value);
   
// ldr 

ldr_value = analogRead(ldr_sensor_pin);
Serial.print("LDR : ");
Serial.println(ldr_value);



//dht

 DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

    delay(2000);

}
