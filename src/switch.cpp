#include <Arduino.h>
#include <switch.h>
#include <motors.h>

/**
 * @brief init the switch and its used pin
 * 
 */
void initSwitch(void) {
  pinMode(NO_1, INPUT_PULLUP);
}

/**
 * @brief Get the Switch Status object
 * 
 */
void getSwitchStatus(void) {
  /*write init status of the switch*/
  bool status_NO1 = digitalRead(NO_1) == LOW;
  /*motor moves to upper limit if the switch was triggered*/
  if ((status_NO1 == HIGH)) {
    moveSwitchMotor();
    delay(SWITCH_DELAY);
  }
  /*nothing happens*/
  else {
    ;
  }
}

