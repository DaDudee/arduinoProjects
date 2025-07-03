#include <IRremote.h>
#define IR_PIN 11
#define MARK_EXCESS_MICROS 20 // 20 is recommended for the cheap VS1838 modules

int stevilke[10] = {};
int index = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    IrReceiver.begin(11, ENABLE_LED_FEEDBACK);
    Serial.println("Pripravljen za prejem IR signalov");
}

void loop() {
    // put your main code here, to run repeatedly:
    while(!IrReceiver.decode()){}
    
    if(IrReceiver.decode()){
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume();
        
    }

    if(IrReceiver.decodedIRData.command == 0xC){//0x45
        Serial.println("1");
        stevilke[index] = 1;
        index++;
    }
    else if(IrReceiver.decodedIRData.command == 0x18){//46
        Serial.println("2");
    }
    else if(IrReceiver.decodedIRData.command == 0x5E){//47
        Serial.println("3");
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

    if(index == 9){
        for(int i = 0; i < 10; i++){
            Serial.print(stevilke[i]);
        }
        Serial.println();
        index = 0;
    }
    delay(500);
}
