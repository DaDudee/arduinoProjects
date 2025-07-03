#define PRVI 13
#define DRUGI 12
#define TRETJI 11
#define CETRTI 10

bool dig[16][8] = {
// a  b  c  d  e  f  g  dp
  {1, 1, 1, 1, 1, 1, 0, 0},   //digit 0
  {0, 1, 1, 0, 0, 0, 0, 0},   //digit 1
  {1, 1, 0, 1, 1, 0, 1, 0},   //digit 2
  {1, 1, 1, 1, 0, 0, 1, 0},   //digit 3
  {0, 1, 1, 0, 0, 1, 1, 0},   //digit 4
  {1, 0, 1, 1, 0, 1, 1, 0},   //digit 5
  {1, 0, 1, 1, 1, 1, 1, 0},   //digit 6
  {1, 1, 1, 0, 0, 0, 0, 0},   //digit 7
  {1, 1, 1, 1, 1, 1, 1, 0},   //digit 8
  {1, 1, 1, 1, 0, 1, 1, 0},   //digit 9
  {1, 1, 1, 0, 1, 1, 1, 0},   //digit A
  {0, 0, 1, 1, 1, 1, 1, 0},   //digit B
  {1, 0, 0, 1, 1, 1, 0, 0},   //digit C
  {0, 1, 1, 1, 1, 0, 1, 0},   //digit D
  {1, 0, 0, 1, 1, 1, 1, 0},   //digit E
  {1, 0, 0, 0, 1, 1, 1, 0}    //digit F
  
};



// funkcija pokaže številko n na segmentu ki ga povemo z digit
void stevilka(int n, int digit){
    digitalWrite(digit, HIGH);
    
    digitalWrite(2, dig[n][0]);   // A = 2
    digitalWrite(3, dig[n][1]);   // B = 3
    digitalWrite(4, dig[n][2]);   // C = 4
    digitalWrite(5, dig[n][3]);   // D = 5
    digitalWrite(6, dig[n][4]);   // E = 6
    digitalWrite(7, dig[n][5]);   // F = 7
    digitalWrite(8, dig[n][6]);   // G = 8
    digitalWrite(9, dig[n][7]);   // DP = 9
    
    digitalWrite(digit, LOW);
    delay(5);
    digitalWrite(digit, HIGH);
    
    
}

int stari_a;
int stari_b;

void setup() {
    for (int i = 2; i < 9; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    for (int i = 10; i < 14; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    

}

int st = 0;

byte cifre[4] = {1, 2, 3, 4};

long int reset_je_bil_ob = 0;

void loop() {
    int a = !digitalRead(A0);
    int b = !digitalRead(A1);

    //če je novi a enak staremu se ni zgodilo nič, tipka ni bila ne dvignjena ne spuščena
    //če sta pa različna IN je bil gumb prej spuščen spremenimo vklopljenost 
    if(a != stari_a && stari_a == 0){
        reset_je_bil_ob = millis();
    }

    
    //millis() vrne število milisekund od zadnjega reseta
    int sek = (millis() - reset_je_bil_ob)/10;
    //najprej potrebujemo enice
    cifre[3] = sek % 10;
    
    //sedaj iščemo desetice
    cifre[2] = (sek % 100)/10;

    //stotice
    cifre[1] = (sek % 1000)/100;

    //tisocice
    cifre[0] = (sek % 10000)/1000;

    
    stevilka(cifre[0], PRVI);
    stevilka(cifre[1], DRUGI);
    stevilka(cifre[2], TRETJI);
    stevilka(cifre[3], CETRTI);
    //millis() vrne število milisekund od zadnjega reseta
    st = (millis()/1000)%16;
}
