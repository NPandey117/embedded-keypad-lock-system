#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //setting up LCD
const uint8_t rows=4,cols=4;  //setting up KEYPAD
char KEY[rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
const uint8_t rowPins[rows]={12,11,10,9};
const uint8_t colPins[cols]={8,7,6,5};
Keypad keypad=Keypad(makeKeymap(KEY),rowPins,colPins,rows,cols);
int buzzPin=13; //buzzer
int state=0;
//0->LOCKED, 1->UNLOCKED, 2->RESET_MODE
String PassWord="1234";
int maxPassLen=4;
String input_str="";
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Door LOCK System");
  delay(2000);
  lcd.clear();
}

void loop() {
if(state==0){ //LOCKED
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Door Locked!");
  lcd.setCursor(0,1);
  lcd.print("Enter Code:");
while(input_str.length()<maxPassLen){  //input code
  char key=keypad.getKey();
  if(key){
  input_str+=key;
  lcd.print('*');
  }
}
if(input_str=="####"){        //if reset code then set mode to reset
  lcd.clear();
  lcd.print("Pwd RESET MODE!");
  tone(buzzPin,1500,500);
  delay(2000);
  state=2;
}
else if(input_str!=PassWord){   //if locked mode then set mode to LOCKED
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Error!");
  lcd.setCursor(3,1);
  lcd.print("Door Locked!");
  tone(buzzPin,2000,1000);
  delay(2000);
  state=0;
  input_str="";
}
else{    //door unlocked 
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Door Unlocked!");
  tone(buzzPin,1000,100);
  //delay(2000);
  state=1;
}
}
else if(state==1){ //UNLOCKED
  lcd.setCursor(1,0);
  lcd.print("Door Unlocked!");
  state=1;
}
else{  //RESET_MODE
  lcd.clear();
  lcd.print("Enter New Code:");
  lcd.setCursor(0,1);
  String newCode="";
  while(newCode.length()<maxPassLen){  //input new code
    char key=keypad.getKey();
    if(key){
    newCode+=key;
    lcd.print(key);
    }
  }
  PassWord=newCode;  //reset password
  input_str="";
  state=0;   //reset system
}
}
