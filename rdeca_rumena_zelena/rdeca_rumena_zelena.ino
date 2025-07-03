int rdeca = 13;
int rumena = 12;
int zelena = 11;

void setup() {
  // put your setup code here, to run once:
  
pinMode(rdeca, OUTPUT);
pinMode(rumena, OUTPUT);
pinMode(zelena, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(rdeca, HIGH);
delay(200);
digitalWrite(rdeca, LOW);
delay(200);
digitalWrite(rumena, HIGH);
delay(200);
digitalWrite(rumena, LOW);
delay(200);
digitalWrite(zelena, HIGH);
delay(200);
digitalWrite(zelena, LOW);
delay(200);
}
