
//https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("OLA");  //Escreve na linha 0 coluna 0
  
  lcd.setCursor(0, 1);
  lcd.print("MUNDO"); //Escreve na linha 1 coluna 0
  
  delay(5000);
}
