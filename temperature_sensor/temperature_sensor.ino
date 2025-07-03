#include <SimpleDHT.h>
#include "DHT.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int DHTPIN = 8;

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);
SimpleDHT11 dht11(DHTPIN);
void setup(){
    Serial.begin(9600);
    lcd.begin(16,2);
}
void loop(){
    int temp = dht.readTemperature();
    lcd.setCursor(2,0);
    lcd.println(temp          );
    lcd.print(" C");
    delay(1000);
        }
