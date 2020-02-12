/*
* Arduino LCD Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
const String QUEUE_SPACE = "      ";
void setup() { 
  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display 
  for (int i = 0; i < 3; i++) {
    const int ANIMATE_DELAY = 100;
    lcd.clear();
    delay(ANIMATE_DELAY);
    lcd.print(QUEUE_SPACE);
    animate("....", ANIMATE_DELAY);
    delay(ANIMATE_DELAY);
  }
  lcd.clear();
  switch (random(1,18)) {
    case 1:
    case 3:
    case 4:
    case 10:
    case 7:
    case 8:
    case 6:
      lcd.print("      Yes!");
      break;
    case 12:
    case 11:
    case 13:
    case 16:
    case 17: 
      lcd.print("     Maybe.");
      break;
    default:
      lcd.print("      No..");
      break;
  }
}

void loop() {
  
}


void animate(String text, int d) {
  for (int i = 0; i < text.length(); i++) {
    lcd.print(text.substring(i, i+1));
    delay(d);
  }
}
