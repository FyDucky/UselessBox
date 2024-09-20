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
 * @brief Get the Distance object via ultrasonic measurement
 * 
 * @return float : returns the distance
 */
float getDistance(void) {
  float duration, distance;
  
  /*get ultrasonic signals*/
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(SONIC_LOW);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(SONIC_HIGH);
  digitalWrite(TRIG_PIN, LOW);

  /*calculate the duration*/
  duration = pulseIn(ECHO_PIN, HIGH);

  /*calculate the distance*/
  distance = (duration*.0343)/DIVISOR_DISTANCE;

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

  /*if the trigger point is reached the either the box or the flap motor moves*/
  if(distance <= TRIGGER_POINT) {
      moveMotor();
  }
  /*nothing happens*/
  else {
    ;
  }

  /*delay to prevent that the system is not triggered to often*/
  delay(MEASURE_DELAY);
}