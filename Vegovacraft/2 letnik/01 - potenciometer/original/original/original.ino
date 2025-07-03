// servo kontroliramo z potenciometrom
#include <Servo.h>
Servo myservo;
int stanje = 0;
int poten = A0;

void setup(){
    Serial.begin(9600);
    myservo.attach(11);
    pinMode(poten, INPUT);
}

void loop(){ 
  
    for(int i=0; i<1000; i++){
      stanje = analogRead(A0);
      myservo.write(stanje);
      Serial.println(stanje);
      delay(20);
    }
}
