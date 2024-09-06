/*servo box defines */
#define   BOX_MOTOR_PIN     	  7
#define   BOX_MOTOR_DELAY         5 
#define   BOX_MOTOR_MAX           180
#define   BOX_MOTOR_MIN           0
#define   BOX_MOTOR_STEPS         1

/*servo switch defines*/
#define   SWITCH_MOTOR_PIN     	  4 
#define   SWITCH_MOTOR_DELAY      5 
#define   SWITCH_MOTOR_MAX        180
#define   SWITCH_MOTOR_MIN        0
#define   SWITCH_MOTOR_STEPS      1

/*switch end positions*/
#define   UPPER_LIMIT             150
#define   LOWER_LIMIT             50

/*servo lid defines*/
#define   LID_MOTOR_PIN     	  3 
#define   LID_MOTOR_DELAY         5 
#define   LID_MOTOR_MAX           180
#define   LID_MOTOR_MIN           0
#define   LID_MOTOR_STEPS         1

void attachServo(void);
void switchMotor(int select);
void moveMotor(void);
