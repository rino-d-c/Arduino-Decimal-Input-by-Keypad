/* Sketch by Rino DC MicroPWR */

#include <LiquidCrystal.h>
#include <Keypad.h>


LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);

const byte baris = 4;
const byte kolom = 3;
char keys[baris][kolom] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},
};

byte rowPins[baris] = {0, 1, 2, 3};
byte colPins[kolom] = {4, 5 , 8};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, baris, kolom);

double sementara;
double bilangan;
double desimal;
String bulString;
String desString;
byte pangkat = 0;
boolean inputDec = false;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BILANGAN BULAT");
  lcd.setCursor(0, 1);
  lcd.print(bilangan, 0);
}



void loop() {
  char key = keypad.getKey();

  if (key)
  {


    if ((key != '*') && (key != '#') && (inputDec == false))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BILANGAN BULAT");

      bulString += (key);
      bilangan = bulString.toInt();

      lcd.setCursor(0, 1);
      lcd.print(bilangan, pangkat);
    }


    if (key == '*' && inputDec == false)
    {
      inputDec = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BILANGAN DESIMAL");
      lcd.setCursor(0, 1);
      lcd.print(bilangan, 0);
      lcd.print(".");
      while (inputDec = true)
      {
        char key = keypad.getKey();
        if (key)
        {
          if ((key != '*') && (key != '#'))
          {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("BILANGAN DESIMAL");
            lcd.setCursor(0, 1);
            pangkat++;

            desString += (key);
            desimal = desString.toInt();
            desimal = desimal / pow(10, pangkat);
            sementara = bilangan + desimal;
            lcd.setCursor(0, 1);
            lcd.print(sementara, pangkat);
          }

          if (key == '#')
          {
            sementara = bilangan + desimal;
            bilangan = sementara;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("BILANGAN AKHIR");
            lcd.setCursor(0, 1);
            lcd.print(bilangan, pangkat);
            break;
          }
        }
      }
    }


    if (key == '#')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BILANGAN AKHIR");
      lcd.setCursor(0, 1);
      lcd.print(bilangan, pangkat);
    }
  }
}

