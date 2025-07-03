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
  {0, 0, 1, 1, 1, 1, 1, 0},    //digit B
  {1, 0, 0, 1, 1, 1, 0, 0},   //digit C
  {0, 1, 1, 1, 1, 0, 1, 0},   //digit D
  {1, 0, 0, 1, 1, 1, 1, 0},   //digit E
  {1, 0, 0, 0, 1, 1, 1, 0}   //digit F
  
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

void setup() {
    for (int i = 2; i < 14; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    

}

int st = 0;

void loop() {
    stevilka(st, PRVI);
    //millis() vrne število milisekund od zadnjega reseta
    st = (millis()/1000)%16;
}
