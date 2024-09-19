#include <Arduino.h>
#include <switch.h>
#include <motors.h>

/**
 * @brief init the switch and its pins
 * 
 */
void initSwitch(void) {
  pinMode(NO_1, INPUT_PULLUP);
  pinMode(NO_2, INPUT_PULLUP);
}

/**
 * @brief Get the Switch Status object
 * 
 */
void getSwitchStatus(void) {
  /*write init status*/
  bool status_NO1 = digitalRead(NO_1) == LOW;
  //bool status_NO2 = digitalRead(NO_2) == LOW;

  /*motor moves to upper limit*/
  if ((status_NO1 == HIGH)) {
    switchMotor(NO_1);
    delay(SWITCH_DELAY);
  }
  else {
    ;
  }
}

