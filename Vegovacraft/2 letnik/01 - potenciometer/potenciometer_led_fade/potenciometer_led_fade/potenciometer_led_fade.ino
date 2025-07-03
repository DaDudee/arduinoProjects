// vpravljanje ledice z potenciometrom, ledice se prizigajo, ugasajo
int redled = 8;

void setup(){
    Serial.begin(9600);

    pinMode(redled, OUTPUT);
}

void loop(){
    int time = 1000;
    int pot_variable = 1020;
    int state = analogRead;

    //potenciometer gre do 1023 

    if(state > pot_variable || state < 0){
        state = -state;
    }
}
