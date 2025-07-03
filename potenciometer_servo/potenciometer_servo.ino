#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>

#define redpin 5
#define greenpin 6
#define bluepin 7
#define IR_PIN 8
#define MARK_EXCESS_MICROS 20 // 20 is recommended for the cheap VS1838 modules
Servo myservo;
int var = 0;

void setup(){
    Serial.begin(9600);
    IrReceiver.begin(IR_PIN,ENABLE_LED_FEEDBACK);
    Serial.println("pripravljen na sprejemanje IR sinalov");

    pinMode(redpin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    myservo.attach(9);
    myservo.write(0);
}

void clear_led(){
    for (int i = 5; i < 8; i++){
        digitalWrite(i, LOW);
    }
}

void loop(){
    while(!IrReceiver.decode()){}
    
    if(IrReceiver.decode()){
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume();
        
    }
    if(IrReceiver.decodedIRData.command == 0x47){
        digitalWrite(redpin, HIGH);
        Serial.println("red led ==> on");
    }
    else if(IrReceiver.decodedIRData.command == 0x43){
        digitalWrite(greenpin, HIGH);
        Serial.println("green led ==> on");
    }
    else if(IrReceiver.decodedIRData.command == 0x9){
        digitalWrite(bluepin, HIGH);
        Serial.println("blue led=> on");
    }
    else if(IrReceiver.decodedIRData.command == 0x15){
        for(var = 0; var <= 360; var++){
          myservo.write(var);
        }
    }
    else if(IrReceiver.decodedIRData.command == 0x7){
      int newvar = myservo.read();
      myservo.write(newvar);
    }
    else if(IrReceiver.decodedIRData.command == 0x16){
        clear_led();
        Serial.println("clear");
    }
    else if(IrReceiver.decodedIRData.command == 0x4A){
        myservo.write(0);
        Serial.println("servo ==> 0");
    }
    delay(500);

}
