#include <Arduino.h>
#include <motors.h>
#include <ultrasonic.h>

/**
 * @brief init the ultrasonic sensor 
 * 
 */
void initSonicSensor(void) {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

/**
 * @brief Get the Distance object
 * 
 * @return float 
 */
float getDistance(void) {
  float duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(SONIC_LOW);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(SONIC_HIGH);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  delay(ULTRASONIC_DELAY);
  return distance;
}

/**
 * @brief trigger the motor if an object (finger) is close to the sensor
 * 
 */
void triggerMotor(void) {
  float distance = 0;

  distance = getDistance();

  if(distance <= TRIGGER_POINT) {
      moveMotor();
  }
  else {
    ;
  }
  delay(600);
}