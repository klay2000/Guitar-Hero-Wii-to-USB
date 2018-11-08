#include <Joystick.h>

int DEADBAND = 25;

void setup() {
  
  Joystick.begin();

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  Serial.begin(9600);

}

void loop() {

  for(int i = 2; i <= 8; i++){
    if(!digitalRead(i)) Joystick.pressButton(i);
    else Joystick.releaseButton(i);
  }
  if(!digitalRead(12)) Joystick.pressButton(12);
  else Joystick.releaseButton(12);
  if(!digitalRead(13)) Joystick.pressButton(13);
  else Joystick.releaseButton(13);

  int x = (analogRead(A2)-73)*0.491;
  int y = (analogRead(A1)-99)*0.487;
  int z = (analogRead(A0)-280)*0.678;

  x -= 127;
  y -= 127;
  z -= 127;

  x = constrain(x, -127, 127);
  y = constrain(y, -127, 127);
  z = constrain(z, -127, 127);
  
  if(abs(x) < DEADBAND)x = 0;
  if(abs(y) < DEADBAND)y = 0;
  if(abs(z) < DEADBAND)z = 0;

  Joystick.setXAxis(x);
  Joystick.setYAxis(y);
  Joystick.setZAxis(z);
  
}
