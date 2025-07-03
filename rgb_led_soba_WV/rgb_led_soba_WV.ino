#include <FastLED.h>
int data = 0;

#define ledpin 8
#define numleds 380   // 293 leds on strip, 380 (bed)
#define brightness 255
#define saturation 255
#define LED_TYPE WS2812 

CRGB leds[numleds];

void setup() {
    // put your setup code here, to run once:

    FastLED.addLeds<WS2812, ledpin, GRB>(leds, numleds);
    FastLED.show();
    
    Serial.begin(9600);

}

void loop() {
    // put your main code here, to run repeatedly:

    if(Serial.available() > 0){
        data = Serial.read();

        if(data == 'r'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (255, 0, 0);
                FastLED.show();
                delay(50);
            }
            Serial.println("red ==> on");
        }
        
        else if(data == 'c'){

            FastLED.clear();
            FastLED.show();
            Serial.println("clear");
        }
        
        else if(data == 'y'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (255,255,0);
                FastLED.show();
                delay(50);
            }
            Serial.println("yellow ==> on");
        }

        else if(data == 'o'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (255,140,0);
                FastLED.show();
                delay(50);
            }
            Serial.println("orange ==> on");
        }
    }
        
        
    }
