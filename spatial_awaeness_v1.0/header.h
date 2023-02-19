#define CLOCKWISE "clockwise"
#define COUNTER_CLOCKWISE "counterClockwise"

struct Motor {
  int enable_pin;
  int input1_pin;
  int input2_pin;
};

struct SonarSensor {
  int trig;
  int echo;
};

Motor defineMotor(int enable_pin, int input1_pin, int input2_pin);
void setMotorPins(Motor motor);
void setMotorSpinDirection(Motor motor, char* direction);
void setMotorSpeed(Motor motor, int speed);

SonarSensor defineSonarSensor(int trig, int echo);
void setSonarSensor(SonarSensor sensor);
int getDistance(SonarSensor sensor);