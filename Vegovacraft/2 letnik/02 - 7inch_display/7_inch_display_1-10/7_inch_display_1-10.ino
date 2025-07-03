int pini_zaslona[] = {2,3,4,5,6,7,8};

void pocisti_zaslon(){
 for(int i = 0; i < 8; i++){
    digitalWrite(pini_zaslona[i], LOW);
  }
 }

void setup() {
  // put your setup code here, to run once:

  for(int i = 0; i < 8; i++){
    pinMode(pini_zaslona[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 0
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH); 
  digitalWrite(pini_zaslona[4], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[1], HIGH); // 1
  digitalWrite(pini_zaslona[2], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 2
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[3], HIGH);
  digitalWrite(pini_zaslona[4], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 3
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[1], HIGH); // 4
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 5
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 6
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH);
  digitalWrite(pini_zaslona[4], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 7
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[2], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 8
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH); 
  digitalWrite(pini_zaslona[4], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
  pocisti_zaslon();
  digitalWrite(pini_zaslona[0], HIGH); // 9
  digitalWrite(pini_zaslona[1], HIGH);
  digitalWrite(pini_zaslona[2], HIGH);
  digitalWrite(pini_zaslona[3], HIGH);
  digitalWrite(pini_zaslona[5], HIGH);
  digitalWrite(pini_zaslona[6], HIGH);
  delay(1000);
}
