#include <Arduino.h>
#include <FastLED.h>

#define ledpin 5
#define lednum 19
#define brightness 255
int sound_sensor = A0;
int data = 0;

CRGB leds[lednum];

void setup(){
    FastLED.addLeds<WS2812, ledpin, GRB>(leds, lednum);
    Serial.begin(9600);
    FastLED.clear();
    FastLED.show();
}

void loop(){
    data = Serial.read();
    Serial.println(data);

}