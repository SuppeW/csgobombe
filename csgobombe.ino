#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};

byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {9,8,7,6};

Keypad keypad = Keypad(makeKeymap(keys),rowPins, colPins, ROWS, COLS);

const int RED = 46;
const int YELLOW = 42;
const int GREEN = 44;
const int ABSWITCH = 40;
const int BUZZER = 36;


int BOMBTIMER = 1000;
int CLOCK = 0;
String CODEINPUT = "";

String BOMBCODE = "7355608";
String BDAYCODE = "090896";
String LEETCODE = "1337";
String LISACODE = "1";
String BOMBSITE = "A";


int TOLATESOUND = 2200;
int TIMERSOUND = 2564;

const int C3 = 130;
const int C3m = 138;
const int D3 = 146;
const int D3m = 155;
const int E3 = 164;
const int F3 = 174;
const int F3m = 185;
const int G3 = 196;
const int G3m = 207;
const int a3 = 220;
const int A3m = 233;
const int B3 = 246;

const int C4 = 261;
const int C4m = 277;
const int D4 = 293;
const int D4m = 311;
const int E4 = 329;
const int F4 = 349;
const int F4m = 370;
const int G4 = 392;
const int G4m = 415;
const int a4 = 440;
const int A4m = 466;
const int B4 = 493;

const int C5 = 523;
const int C5m = 554;
const int D5 = 587;
const int D5m = 622;
const int E5 = 659;
const int F5 = 698;
const int F5m = 739;
const int G5 = 783;
const int G5m = 830;
const int a5 = 880;
const int A5m = 932;
const int B5 = 987;


const int C6 = 1046;
const int C6m = 1108;
const int D6 = 1174;
const int D6m = 1244;
const int E6 = 1318;
const int F6 = 1396;

const int rs = 52, en = 50, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(ABSWITCH, INPUT); 
  pinMode(BUZZER, OUTPUT);
  digitalWrite(GREEN, HIGH);

  lcd.begin(16, 2);
}

void loop() {
  if(digitalRead(ABSWITCH) == HIGH){
    BOMBSITE = "A";
    lcd.setCursor(15,2);
    lcd.print("A");
    TIMERSOUND = 2564;
  }else{
    BOMBSITE = "B";
    lcd.setCursor(15,2);
    lcd.print("B");
    TIMERSOUND = 2146;
  }
  
  lcd.setCursor(0,0);
  
  char key = keypad.getKey();
  
  if (key){
    if(key == 'C'){
      CODEINPUT = "";
      lcd.print(CODEINPUT);
      lcd.clear();
      Serial.println(CODEINPUT);
    }else if(key == '1'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,C5,100);
    }else if(key == '2'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,D5,100);
    }else if(key == '3'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,E5,100);
    }else if(key == '4'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,F5,100);
    }else if(key == '5'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,G5,100);
    }else if(key == '6'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,a5,100);
    }else if(key == '7'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,B5,100);
    }else if(key == '8'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,C6,100);
    }else if(key == '9'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,D6,100);
    }else if(key == '0'){
      CODEINPUT = CODEINPUT+key;
      lcd.print(CODEINPUT);
      Serial.println(CODEINPUT);
      tone(BUZZER,E6,100);
    }else if(key == '*'){
      if(CODEINPUT == BOMBCODE){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("BOMB PLANTED");
      digitalWrite(GREEN, LOW);
      
      for(CLOCK; CLOCK < 100; CLOCK++){
        tone(BUZZER,TIMERSOUND,100);
        digitalWrite(YELLOW, HIGH);
        delay((BOMBTIMER-(CLOCK*10))/2);
        digitalWrite(YELLOW, LOW);
        delay((BOMBTIMER-(CLOCK*10))/2);
        lcd.setCursor(0,1);
        lcd.print(CLOCK);
        if(CLOCK == 98){
          
          digitalWrite(YELLOW, LOW);
          digitalWrite(RED, HIGH);
          tone(BUZZER,TIMERSOUND,2000);
          
          for(int i=0;i<20;i++){
            delay(50);
            digitalWrite(RED, LOW);
            delay(50);
            digitalWrite(RED, HIGH);
          }
        }
      }
      }else if(CODEINPUT == BDAYCODE){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Creator: Anders 'Suppe' Woien");
        while(true){
          lcd.autoscroll();
          lcd.print(" ");
          delay(350);
        }
      }else if(CODEINPUT == LEETCODE){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("BOOBIES");
      }else if(CODEINPUT == LISACODE){
        tone(BUZZER, E6, 300);
        delay(400);
        tone(BUZZER, D6m, 300);
        delay(400);
        tone(BUZZER, E6, 300);
        delay(400);
        tone(BUZZER, D6m, 300);
        delay(400);
        tone(BUZZER, E6, 300);
        delay(400);
        tone(BUZZER, B5, 300);
        delay(400);
        tone(BUZZER, D6, 300);
        delay(400);
        tone(BUZZER, C6, 300);
        delay(400);
        tone(BUZZER, a5, 300);
        delay(400);
        
        tone(BUZZER, a3, 300);
        delay(400);
        tone(BUZZER, E4, 300);
        delay(400);
        tone(BUZZER, a4, 300);
        delay(400);
        tone(BUZZER, C5, 300);
        delay(400);
        tone(BUZZER, E5, 300);
        delay(400);

        tone(BUZZER, a5, 300);
        delay(400);
        tone(BUZZER, B5, 300);
        delay(400);
        tone(BUZZER, E3, 300);
        delay(400);
        tone(BUZZER, E4, 300);
        delay(400);
        tone(BUZZER, G5m, 300);
        delay(400);
        
      }
    }
  } 
}
