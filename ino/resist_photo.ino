// C++ code
//
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000); // Wait for 1000 millisecond(s)
  // digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  int val = analogRead(A0);
  int percent = ((float)(1017 - val) / (1017 - 344)) * 100;
  Serial.println(percent, DEC);
}
