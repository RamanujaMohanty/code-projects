// C++ code
//
#include <Servo.h>
Servo myServo;
int firstKey = 11;
int secondKey = 12;
int servoCounter = 0;
void setup()
{
  pinMode(firstKey, INPUT_PULLUP);
  pinMode(secondKey, INPUT_PULLUP);
  myServo.attach(13);
}

void loop()
{
  if (servoCounter > 160)
  {
    servoCounter = 159;
  }
  if (servoCounter < 0)
  {
    servoCounter = 1;
  }
  if(digitalRead(firstKey) == LOW)
  {
    myServo.write(++servoCounter);
  }
  else if(digitalRead(secondKey) == LOW)
  {
    myServo.write(--servoCounter);
  }
  delay(100);
}
