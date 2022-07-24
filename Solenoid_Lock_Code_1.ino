#include <Keypad.h>

char * password = "3489";

int position = 0;


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS]= 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7,6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int Lock = 5;

void LockedPosition(int locked)
  {
    if(locked)
    {
      digitalWrite(Lock,LOW);
    }
    else
    {
      digitalWrite(Lock,HIGH);
    }
  }


void setup() 
{
  pinMode(Lock, OUTPUT);
  LockedPosition(true);
}

void loop()
{
  char key = keypad.getKey();
  
  if(key=='*' || key=='A')
  {
    position = 0;
    LockedPosition(true);
  }

  if(key == password[position])
  {
    position++;
  }
  
  if(position == 4)
  {
    LockedPosition(false);
  }
  delay(100);
}
