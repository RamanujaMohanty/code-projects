// C++ code
//
int redKey = 2;
int blueKey = 3;
int greenKey = 4;
int allKey = 5;
int redPin = 9;
int bluePin = 10;
int greenPin = 11;
int redCount = 0;
int blueCount = 0;
int greenCount = 0;
void setup()
{
  pinMode(redKey, INPUT_PULLUP);
  pinMode(blueKey, INPUT_PULLUP);
  pinMode(greenKey, INPUT_PULLUP);
  pinMode(allKey, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void loop()
{
  if(digitalRead(redKey) == LOW)
  {
    analogWrite(redPin, ++redCount);
  }
  else if(digitalRead(blueKey) == LOW)
  {
    analogWrite(bluePin, ++blueCount);
  }
  else if(digitalRead(greenKey) == LOW)
  {
    analogWrite(greenPin, ++greenCount);
  }
  else if(digitalRead(allKey) == LOW)
  {
    analogWrite(redPin, 0);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 0);
  }
  delay(10);
}
