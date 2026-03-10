// C++ code
//
#include <Servo.h>
Servo myServo;
void setup()
{
  myServo.attach(13);
}

void loop()
{
  for (int ii = 10; ii < 160; ++ii)
  {
    myServo.write(ii);
    delay(10);
  }
  for (int jj = 160; jj > 10; --jj)
  {
    myServo.write(jj);
    delay(10);
  }
}
