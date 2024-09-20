/*servo box defines */
#define   BOX_MOTOR_PIN     	    37
#define   BOX_MOTOR_DELAY           5 
#define   BOX_MOTOR_MAX             180
#define   BOX_MOTOR_MIN             0
#define   BOX_MOTOR_STEPS           1

/*servo switch defines*/
#define   SWITCH_MOTOR_PIN     	    43 
#define   SWITCH_MOTOR_INIT_POS     180
#define   SWITCH_MOTOR_MAX_POS      40

/*servo lid defines*/
#define   FLAP_MOTOR_PIN     	    45  
#define   FLAP_MOTOR_INIT_POS       171
#define   FLAP_MOTOR_MAX_POS        120

/*general delay*/
#define   DELAY_1000                1000

/*random number range*/
#define   MIN_RANDOM                1
#define   MAX_RANDOM                4

/*select options*/
#define   MOVE_BOX                  1
#define   MOVE_FLAP                 2

void attachServo(void);
void moveSwitchMotor(void);
void moveFlapMotor(void);
void moveMotor(void);
void moveBoxMotor(void);

