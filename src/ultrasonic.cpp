#include <Arduino.h>
#include <motors.h>
#include <ultrasonic.h>

void initSonicSensor(void) {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistance(void) {
  float duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(SONIC_LOW);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(SONIC_HIGH);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  delay(ULTRASONIC_DELAY);
  return distance;
}

void triggerMotor(void) {
  float distance = 0;

  distance = getDistance();

  if(distance <= TRIGGER_POINT) {
      moveMotor();
  }
  else {
    ;
  }

}