#include <IRremote.h>

#define redpin 5
#define greenpin 6
#define bluepin 7
#define IR_PIN 8
#define MARK_EXCESS_MICROS 20 // 20 is recommended for the cheap VS1838 modules

void setup(){
    Serial.begin(9600);
    IrReceiver.begin(IR_PIN,ENABLE_LED_FEEDBACK);
    Serial.println("pripravljen na sprejemanje IR sinalov");

    pinMode(redpin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
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
    if(IrReceiver.decodedIRData.command == 0xC){//0x45
        digitalWrite(redpin, HIGH);
        Serial.println("1 ==> red led");
    }
    else if(IrReceiver.decodedIRData.command == 0x18){//46
        digitalWrite(bluepin, HIGH);
        Serial.println("2 ==> blue led");
    }
    else if(IrReceiver.decodedIRData.command == 0x5E){//47
        clear_led();
        Serial.println("clear");
    }
    else if(IrReceiver.decodedIRData.command == 0x8){//44
        Serial.println("4");
    }
    else if(IrReceiver.decodedIRData.command == 0x1C){//40
        Serial.println("5");
    }
    else if(IrReceiver.decodedIRData.command == 0x5A){//43
        Serial.println("6");
    }
    else if(IrReceiver.decodedIRData.command == 0x42){//7
        Serial.println("7");
    }
    else if(IrReceiver.decodedIRData.command == 0x52){//15
        Serial.println("8");
    }
    else if(IrReceiver.decodedIRData.command == 0x4A){//9
        Serial.println("9");
    }
    delay(500);

}
