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
  switchBox.write(180);
  delay(1000);
  lidBox.attach(LID_MOTOR_PIN);
  lidBox.write(175); 
  delay(1000);        
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
    //moveBoxMotor();
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
  static bool moved = false;  // Flag, um zu prüfen, ob der Servo bereits bewegt wurde
  
  //if (!moved) {
    lidBox.write(100);   // Servo auf 200 Grad bewegen
    delay(1000);          // Warte eine Sekunde, um die Bewegung abzuschließen
    lidBox.write(175);   // Servo auf 100 Grad zurückstellen
    moved = true;         // Flag setzen, dass der Servo bewegt wurde
  //}
}

/**
 * @brief behaviour of the motor depending on the switch
 * 
 * @param select : position of the switch
 */
void switchMotor(int select) {

      switchBox.write(40);
      delay(1000);
      switchBox.write(180);

  //delay(SWITCH_MOTOR_DELAY);
}


