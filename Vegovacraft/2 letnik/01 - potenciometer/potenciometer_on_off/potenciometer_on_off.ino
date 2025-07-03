// vpravljanje ledice z potenciometrom, ledice se prizigajo, ugasajo
int redled = 8;
int yellowled = 9;
int greenled = 10;

void setup(){
    Serial.begin(9600);

    pinMode(redled, OUTPUT);
    pinMode(yellowled, OUTPUT);
    pinMode(greenled, OUTPUT);
}

void loop(){
    int time = 1000;
    int pot_variable = 1023;
    int state = analogRead;

    //potenciometer gre do 1023 

    if(state > pot_variable / 2){
        digitalWrite(redled, HIGH);
        digitalWrite(yellowled, HIGH);
        digitalWrite(greenled, HIGH);
    }
    else{
        digitalWrite(redled, HIGH);
        digitalWrite(yellowled, HIGH);
        digitalWrite(greenled, HIGH);
    }

}
