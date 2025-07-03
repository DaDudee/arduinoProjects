 #include <Servo.h>

const int motor1 = 9;
const int servo = 10;
Servo myservo;
int data = 0;

#define servo_min 65    //desno
#define servo_nul 86    //center
#define servo_max 118   //levo

void ustavi(){ 
    digitalWrite(motor1, LOW);
    myservo.write(servo_nul);
}

void setup(){
    Serial.begin(9600);
    Serial.println("test");
    
    pinMode(servo, OUTPUT);
    myservo.attach(servo);
    myservo.write(servo_nul);
    analogWrite(motor1, 0);

}

void loop(){

  if(Serial.available() > 0){
    data = Serial.read();

    if(data == '1'){
      analogWrite(motor1, 255);
      Serial.println("on");
    }
    else if(data == '0'){
      analogWrite(motor1, 0);
      Serial.println("on");
    }
  }

}
