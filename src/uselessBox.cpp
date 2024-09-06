#include <Arduino.h>
#include <motors.h>
#include <switch.h>
#include <ultrasonic.h>

#define   RANDOM_INIT_PIN         0

/**
 * @brief sets up peripherals, is only called once
 * 
 */
void setup() {
  /*attaches motors*/
  attachServo();
  initSonicSensor();
  /*init random mechanism */
  randomSeed(analogRead(RANDOM_INIT_PIN));
  /*inits the switch*/
  initSwitch();
}

/**
 * @brief runs in a loop
 * 
 */
void loop() {
  /*triggers motor if sensor is triggered */
  triggerMotor();
  /*just for debugging*/
  getSwitchStatus();
}
