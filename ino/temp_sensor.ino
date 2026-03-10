// C++ code
//
const int DELAY = 1000;
void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(DELAY);
  Serial.println(-40 + (analogRead(A5) - 20) * 165.0 / 338.0, DEC);
}
