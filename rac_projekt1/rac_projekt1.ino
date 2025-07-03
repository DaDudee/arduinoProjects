#include <FastLED.h>
int data = 0;

#define ledpin 8
#define numleds 11   // 293 leds on strip, 380 (bed)
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
        else if(data == 'g'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (0, 255, 0);
                FastLED.show();
                delay(50);
            }
            Serial.println("green ==> on");
        }
        
        else if(data == 'b'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (0, 0, 255);
                FastLED.show();
                delay(50);
            }
            Serial.println("blue ==> on");
        }
        
        else if(data == 'c'){

            FastLED.clear();
            FastLED.show();
            Serial.println("clear");
        }

        else if(data == 'w'){

            for(int i = 0; i < numleds; i++){
                leds[i] = CRGB (255, 255, 255);
                FastLED.show();
                delay(50);
            }
            Serial.println("white ==> on");
        }

        else if(data == '1'){

          for (int j = 0; j < 255; j++) {
          for (int i = 0; i < numleds; i++) {
            leds[i] = CHSV(i - (j * 2), saturation, brightness); 
          }
          FastLED.show();
          delay(25); 
       }
       Serial.println("effect 1");
}
        
    }
//  else{
//    Serial.println("not connected");
//    exit(loop);
//  }
}
