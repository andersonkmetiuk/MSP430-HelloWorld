#include <Arduino.h>

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  // wait for a second
  delay(500);
  // turn the LED off by making the voltage LOW
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
   // wait for a second
  delay(500);
}