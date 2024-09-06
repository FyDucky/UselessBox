#include <Arduino.h>
#include <Servo.h>
#include <motors.h>
#include <switch.h>

/*init servo objects*/
Servo motorBox;  
Servo switchBox;
Servo lidBox;


void moveBoxMotor(void);
void moveLidMotor(void);

/**
 * @brief return randomly 1 or 2 
 * 
 * @return int : random number
 */
int randomValue(void) {
  int randomNumber = random(1, 3);  
  return randomNumber;
}

/**
 * @brief attaches motors 
 * 
 */
void attachServo(void) {
  motorBox.attach(BOX_MOTOR_PIN);
  switchBox.attach(SWTICH_MOTOR_PIN);
  lidBox.attach(LID_MOTOR_PIN);
}

void moveMotor(void) {
  int select = randomValue();
  if(select == 1) {
    moveBoxMotor();
  }
  else if(select == 2) {
    moveLidMotor();
  }
  else {
    ;
  }
}

//TODO: add correct directions, just a prototype
void moveBoxMotor(void) {
  int pos = 0;
    for (pos = BOX_MOTOR_MIN; pos <= BOX_MOTOR_MAX; pos += BOX_MOTOR_STEPS) { // goes from 0 degrees to 180 degrees
      motorBox.write(pos);                              
      delay(BOX_MOTOR_DELAY);                                   
  }
  for (pos = BOX_MOTOR_MAX; pos >= BOX_MOTOR_MIN; pos -= BOX_MOTOR_STEPS) { // goes from 180 degrees to 0 degrees
      motorBox.write(pos);              
      delay(BOX_MOTOR_DELAY);                       
  }
}

void moveLidMotor(void) {
  int pos = 0;
    for (pos = LID_MOTOR_MIN; pos <= LID_MOTOR_MAX; pos += LID_MOTOR_STEPS) { // goes from 0 degrees to 180 degrees
      lidBox.write(pos);                                  
      delay(LID_MOTOR_DELAY);                                   
  }
  for (pos = LID_MOTOR_MAX; pos >= LID_MOTOR_MIN; pos -= LID_MOTOR_STEPS) { // goes from 180 degrees to 0 degrees            
      lidBox.write(pos); 
      delay(LID_MOTOR_DELAY);                       
  }
}

//TODO: Implement switch behaviour
void switchMotor(int select) {
  int pos = 0;
  if(select == NO_1) {
      switchBox.write(UPPER_LIMIT);                                  
  }                                   
  else if(select == NO_2) {           
      switchBox.write(LOWER_LIMIT);                     
  }
  else {
    ;
  }
  delay(SWITCH_MOTOR_DELAY);
}


