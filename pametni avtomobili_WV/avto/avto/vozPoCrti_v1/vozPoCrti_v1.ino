/******************************************************/
int pin_tipka = 5;          // digitalni vhod, s pullup uporom
int pin_servo = 8;          // digitalni izhod, servo PWM
int pin_pot_vklop = A1;     // digitalni izhod, vklop potenciometra
int pin_pot_vrednost = A0;  // analogni vhod, vrednost pot. 0...1023
int pin_pogon_smer = 4;     // digitalni izhod, smer voznje, naprej/nazaj
int pin_pogon_moc = 3;      // digitalni izhod, hitrost voznje, PWM
int pin_senzor_vklop = 2;   // digitalni izhod, senz. vklopimo z 0
int pin_senzor_d = A3;      // analogni vhod, 0 -> je odboj (bela), 1023 -> ni odboja (črna)
int pin_senzor_c = A4;
int pin_senzor_l = A5;

// vrednosti za servo (omejimo, da ne zabija in vleče preveč toka)
#define SERVO_MIN 65	//desno
#define SERVO_NUL 86	//center
#define SERVO_MAX 118	//levo

#include <Servo.h>  	// knjižnica za nadzor servo motorjev 
Servo servoSmer; 		  // objekt servoSmer vsebuje funkcije za nadzor

/******************************************************/
/******************************************************/
uint32_t beriPotenciometer() {	     // vrne vrednost 0...1023
  digitalWrite(pin_pot_vklop, 1);	   // vklopi pot.
  uint32_t pot = analogRead(pin_pot_vrednost);
  digitalWrite(pin_pot_vklop, 0);	   // izklopi pot.
  return pot;
}

/******************************************************/
/* globalne spr.
  		velika vrednost => črna podlaga, oz. ni odboja (prevelika razdalja)
  		majhna vrednost => bela podlaga, veliko odboja
*/
uint32_t senzor_l, senzor_c, senzor_d;				//trenutne vrednosti
void beriSenzorje() {
  digitalWrite(pin_senzor_vklop, 0);	        // vklopi senzorje, aktivna 0
  delayMicroseconds(30);

  senzor_l = analogRead(pin_senzor_l);
  senzor_c = analogRead(pin_senzor_c);
  senzor_d = analogRead(pin_senzor_d);

  digitalWrite(pin_senzor_vklop, 1);	        // izklopi senzorje, aktivna 0
}


/******************************************************/
/* Zazna spremembo pina, torej pritisk */
int32_t tipka_prej = 1;
int32_t beriTipko() {
  int32_t tipka_zdaj = digitalRead(pin_tipka);
  int32_t izhod = 0;
  if (tipka_zdaj == 0 && tipka_prej == 1) {
    izhod = 1;
  }
  tipka_prej = tipka_zdaj;
  return izhod;
}

/******************************************************/
void nastaviSmer(int32_t smer) { // -100 (polno levo) ... 0 (center) ... 100 (polno desno)
  smer = min(max(smer, -100), 100);	// popravi, če slučajno ni prava vrednost
  if (smer < 0) {
    smer = map(smer, -100, 0, SERVO_MAX, SERVO_NUL);
  }
  else {
    smer = map(smer, 0, 100, SERVO_NUL, SERVO_MIN);
  }
  servoSmer.write(smer);
}


void nastaviHitrost(int32_t hitrost) {
  /* hitrost: -100 (polno nazaj)... 0 (stop) ... 100 (polno naprej) */
  hitrost = min(max(hitrost, -100), 100);	// popravi, če slučajno ni prava vrednost

  if (hitrost == 0) {	// stop
    digitalWrite(pin_pogon_smer, 1);
    OCR2B = 100;
  }
  else if (hitrost < 0) {	// nazaj
    digitalWrite(pin_pogon_smer, 1);
    OCR2B = 100 - abs(hitrost);
  }
  else {	// naprej
    digitalWrite(pin_pogon_smer, 0);
    OCR2B = abs(hitrost);	// nastavi PWM out
  }
}

void nastaviPWM() {
  /* UNO (atmega328p)
   		timer2: 8 bitni števec
   		omogoča PWM izhod na pinih 3 (kanal B) in 11 (kanalA)

   	vklopi izhodni kanal B
   	izberi "fast PWM" način : top = OCR2A, duty = OCR2B
   	nastavi delilnik na 8_ f_timer = 16MHz/8 = 2MHz
   	OCR2A določa frekvenco: f_B = f_timer / OCR2A = 2MHz/100 = 20 kHz
   	OCR2B določa obratovalni cikel oz. duty cykle: duty = OCR2B/OCR2A
  */
  OCR2B = 50;
  OCR2A = 100;
  TCCR2A = 0x23;
  TCCR2B = 0x0A;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_tipka, INPUT_PULLUP);
  pinMode(pin_servo, OUTPUT);
  pinMode(pin_pot_vklop, OUTPUT);
  pinMode(pin_pot_vrednost, INPUT);
  pinMode(pin_pogon_smer, OUTPUT);
  pinMode(pin_pogon_moc, OUTPUT);
  pinMode(pin_senzor_vklop, OUTPUT);
  pinMode(pin_senzor_d, INPUT);
  pinMode(pin_senzor_c, INPUT);
  pinMode(pin_senzor_l, INPUT);

  /******************************************/
  digitalWrite(pin_servo, 0);
  digitalWrite(pin_pot_vklop, 0);
  digitalWrite(pin_pogon_smer, 0);
  digitalWrite(pin_pogon_moc, 0);
  digitalWrite(pin_senzor_vklop, 1);  // senzorje izklopimo z 1 (5V)

  /*******************************************/

  Serial.begin(9600);
  Serial.println("Pametni avtomobili.");

  /********************************************/
  servoSmer.attach(pin_servo);  // attach funkcija določi pin za servo
  servoSmer.write(SERVO_NUL);
  nastaviPWM();
  nastaviHitrost(0);
}


int prag = 350;
int stanje = 0;
uint32_t zgubljen = 0;
void loop() {
  int tipka = beriTipko();

  if (stanje == 0) {
    nastaviHitrost(0);
    nastaviSmer(0);
    zgubljen = 0;
    if (tipka == 1) {
      stanje = 1;
    }
  }
  else if (stanje == 1) {
    beriSenzorje();
    if (senzor_l > prag && senzor_c < prag && senzor_d < prag) {
      nastaviSmer(100);
      zgubljen = 0;
    }
    else if (senzor_l < prag && senzor_c < prag && senzor_d > prag) {
      nastaviSmer(-100);
      zgubljen = 0;
    }
    else if (senzor_l > prag && senzor_c > prag && senzor_d < prag) {
      nastaviSmer(50);
      zgubljen = 0;
    }
    else if (senzor_l < prag && senzor_c > prag && senzor_d > prag) {
      nastaviSmer(-50);
      zgubljen = 0;
    }
    else if (senzor_l > prag && senzor_c > prag && senzor_d > prag) {
      nastaviSmer(0);
      zgubljen = 0;
    }
    else if (senzor_l > prag && senzor_c < prag && senzor_d > prag) {
      nastaviSmer(50);
      zgubljen = 0;
    }
    else {
      if (zgubljen == 0) {
        zgubljen = millis();
      }
      else{
        if(millis() - zgubljen >= 2000){
          stanje = 0;        
        }
      }
    }

    nastaviHitrost(40);

    if (tipka == 1) {
      stanje = 0;
    }
  }



}
