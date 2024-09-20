/*ultrasonic defines*/
#define   TRIG_PIN                  39
#define   ECHO_PIN                  41
#define   ULTRASONIC_DELAY          50

/*measure parameters*/
#define   TRIGGER_POINT             10
#define   SONIC_LOW                 2
#define   SONIC_HIGH                10
#define   DIVISOR_DISTANCE          2

/*measure delay*/
#define   MEASURE_DELAY             600

void initSonicSensor(void);
void triggerMotor(void);