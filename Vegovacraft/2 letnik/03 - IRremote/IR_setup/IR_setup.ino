#include <IRremote.h>
#define IR_PIN 8
#define MARK_EXCESS_MICROS 20
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN,ENABLE_LED_FEEDBACK);
  Serial.println("Pripravlj za sprejem ir signala");

}

void loop() {
  while(!IrReceiver.decode()){}
    
    if(IrReceiver.decode()){
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume();
        
    }
    if(IrReceiver.decodedIRData.command == 0x8){//44
        Serial.println("stiri");
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
} 
