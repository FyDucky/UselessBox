#include <Arduino.h>
#include <Servo.h>
#include <motors.h>
#include <switch.h>

/*init servo objects*/
Servo boxMotor;  
Servo switchMotor;
Servo flapMotor;

/**
 * @brief return randomly 1,2 or 3
 * 
 * @return int : random number
 */
int randomValue(void) {
  /*get random number*/
  int randomNumber = random(MIN_RANDOM,MAX_RANDOM);  
  return randomNumber;
}

/**
 * @brief attaches motors to use them and init the switch and lid-motor positions
 * 
 */
void attachServo(void) {
  /*attach motor that moves the box*/
  boxMotor.attach(BOX_MOTOR_PIN);

  /*attach motor that pulls back the switch and set it's init position*/
  switchMotor.attach(SWITCH_MOTOR_PIN);
  switchMotor.write(SWITCH_MOTOR_INIT_POS);
  /*delay to secure the position*/
  delay(DELAY_1000);

  /*attach motor that lowers the switch and set it's init position*/
  flapMotor.attach(FLAP_MOTOR_PIN);
  flapMotor.write(FLAP_MOTOR_INIT_POS); 
  delay(DELAY_1000);        
}

/**
 * @brief moves either the switch or the box motor
 * 
 */
void moveMotor(void) {
  /*get random value*/
  int select = randomValue();
  /*box moves if random value = 1*/
  if(select == MOVE_BOX) {
    moveBoxMotor();
  }
  /*switch is pushed down if random value = 2*/
  else if(select == MOVE_FLAP) {
    moveFlapMotor();
  }
  /*nothing happens*/
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
  /*go from 0 to 180 degrees*/
  for (pos = BOX_MOTOR_MIN; pos <= BOX_MOTOR_MAX; pos += BOX_MOTOR_STEPS) { 
    boxMotor.write(pos);                              
    delay(BOX_MOTOR_DELAY);                                   
  }
  /*go from 180 to 0 degrees*/
  for (pos = BOX_MOTOR_MAX; pos >= BOX_MOTOR_MIN; pos -= BOX_MOTOR_STEPS) {
    boxMotor.write(pos);              
    delay(BOX_MOTOR_DELAY);                       
  }
}

/**
 * @brief moves the lid motor
 * 
 */
void moveFlapMotor(void) {
  /*lid is lowered to 120 degrees*/
  flapMotor.write(FLAP_MOTOR_MAX_POS);   
  delay(DELAY_1000);
  /*motor moves back to */         
  flapMotor.write(FLAP_MOTOR_INIT_POS);   
}

/**
 * @brief motor pulls back the switch in init position
 * 
 */
void moveSwitchMotor(void) {
  /*motor moves to pull the switch back*/
  switchMotor.write(SWITCH_MOTOR_MAX_POS);
  delay(DELAY_1000);
  /*switch is in init position*/
  switchMotor.write(SWITCH_MOTOR_INIT_POS);
}


