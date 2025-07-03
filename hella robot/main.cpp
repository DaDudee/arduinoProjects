#include <Arduino.h>
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int variable = 0;

void setup(){

    Serial.begin(9600);
    myservo1.attach(5);
    myservo2.attach(6);
    myservo3.attach(7);
    myservo4.attach(8);

}

void loop(){

    if(Serial.available() > 0){
        variable = Serial.read();

        if(variable = 1-20){
            myservo1.write(20);
            Serial.println("1 ==> 20°");
        }
        else if(variable = 2-20){
            myservo2.write(20);
            Serial.println("2 ==> 20°");
        }
        else if(variable = 3-20){
            myservo3.write(20);
            Serial.println("3 ==> 20°");
        }
        else if(variable = 4-20){
            myservo4.write(20);
            Serial.println("4 ==> 20°");
        }
    }

    else{
        Serial.println("Connection lost!");
    }

}