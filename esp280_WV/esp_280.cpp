#include <Arduino.h>
#include <Wire.h>
#include "SPI.h" 
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP280.h"


Adafruit_BMP280 bmp(&Wire); // I2C
/*// SPI 
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
*/
float pressure;        
float temperature;    
int altimeter;         

void setup() {
    Wire.begin(16, 17);
    bmp.begin();        
    Serial.begin(9600);    
    Serial.println("Adafruit BMP280 test:");
    bmp.begin(0x76);
}

void loop() {
    pressure = bmp.readPressure();
    temperature = bmp.readTemperature();
    altimeter = bmp.readAltitude (1050.35); 
    
    Serial.print(F("Pressure: "));
    Serial.print(pressure);
    Serial.print(" Pa");
    Serial.print("\t");
    Serial.print(("Temp: "));
    Serial.print(temperature);
    Serial.print(" oC");
    Serial.print("\t");
    Serial.print("Altimeter: ");
    Serial.print(altimeter); 
    Serial.println(" m");
    
    delay(1000); 
}