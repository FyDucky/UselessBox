#include <Arduino.h>
#include <Servo.h>
#include <motors.h>
#include <switch.h>

/*init servo objects*/
Servo motorBox;  
Servo switchBox;
Servo lidBox;

int switch_flag;


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
 * @brief attaches motors to use them
 * 
 */
void attachServo(void) {
  motorBox.attach(BOX_MOTOR_PIN);
  switchBox.attach(SWITCH_MOTOR_PIN);
  lidBox.attach(LID_MOTOR_PIN);
}

/**
 * @brief moves either the switch or the box motor
 * 
 */
void moveMotor(void) {
  /*get random value*/
  int select = randomValue();
  /*box moves*/
  if(select == SELECT_NO1) {
    moveBoxMotor();
  }
  /*switch is pushed down*/
  else if(select == SELECT_NO2) {
    moveLidMotor();
  }
  else {
    ;
  }
}

/**
 * @brief moves the box motor 
 * 
 */
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

/**
 * @brief moves the lid motor
 * 
 */
//TOD: add correct limits 
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

/**
 * @brief behaviour of the motor depending on the switch
 * 
 * @param select : position of the switch
 */
void switchMotor(int select) {
  if(select == NO_1) {
      switchBox.write(UPPER_LIMIT);
      delay(SWITCH_MOTOR_DELAY);
      switchBox.write(LOWER_LIMIT);
      delay(SWITCH_MOTOR_DELAY);
  }                                   
  else {
    ;
  }
  //delay(SWITCH_MOTOR_DELAY);
}


