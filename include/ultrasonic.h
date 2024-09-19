/*ultrasonic defines*/
#define   TRIG_PIN                39
#define   ECHO_PIN                41
#define   ULTRASONIC_DELAY        50

#define   TRIGGER_POINT           10
#define   SONIC_LOW               2
#define   SONIC_HIGH              10

void initSonicSensor(void);
void triggerMotor(void);