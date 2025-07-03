#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

int water_pin = A0;
int variable = 0;

void setup(){
    lcd.begin(16,2);
    lcd.setCursor(2,0);
    lcd.println("water level:        ");
} 
void loop(){

  variable = analogRead(water_pin);

  if(variable <= 100){
    lcd.setCursor(2, 1);
    lcd.println("     ///        ");
  }
  else if(variable > 100 && variable <= 200){
    lcd.setCursor(2, 1);
    lcd.println("     low       ");
  }
  else if(variable > 200 && variable <=300){
    lcd.setCursor(2, 1);
    lcd.println("    medium       ");
  } 
  else if(variable > 300){
    lcd.setCursor(2, 1);
    lcd.println("      high       ");
  }
  delay(1000);
}
