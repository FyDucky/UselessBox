#include <Arduino.h>
#include <switch.h>
#include <motors.h>


void initSwitch(void) {
  pinMode(NO_1, INPUT_PULLUP);
  pinMode(NO_2, INPUT_PULLUP);
}

void printStatus(void) {
  bool status_NO1 = digitalRead(NO_1) == LOW;
  bool status_NO2 = digitalRead(NO_2) == LOW;

  if ((status_NO1 == HIGH)) {
    switchMotor(NO_1);
    Serial.println("NO_1");
    delay(SWITCH_DELAY);
  } 
  else if((status_NO2 == HIGH)) {
    switchMotor(NO_2);
    Serial.println("NO_2");
    delay(SWITCH_DELAY);  
  }
  else {
    ;
  }

  delay(1);
}

