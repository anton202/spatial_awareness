#include "header.h";

#define MOTOR_SPEED 100
#define DISTANCE_FROM_OBSTICALE 20  // cm

Motor motor1 = defineMotor(11, 12, 13);
Motor motor2 = defineMotor(10, 9, 8);
Motor motor3 = defineMotor(3, 2, 4);
Motor motor4 = defineMotor(6, 5, 7);

SonarSensor sensor1 = defineSonarSensor(A5, A4);
int distance;

void setup() {
  setMotorPins(motor1);
  setMotorPins(motor2);
  setMotorPins(motor3);
  setMotorPins(motor4);

  setMotorSpeed(motor1, MOTOR_SPEED);
  setMotorSpeed(motor2, MOTOR_SPEED);
  setMotorSpeed(motor3, MOTOR_SPEED);
  setMotorSpeed(motor4, MOTOR_SPEED);

  setMotorSpinDirection(motor1, CLOCKWISE);
  setMotorSpinDirection(motor2, CLOCKWISE);
  setMotorSpinDirection(motor3, CLOCKWISE);
  setMotorSpinDirection(motor4, CLOCKWISE);

  setSonarSensor(sensor1);

  Serial.begin(9600);
}

void loop() {

  distance = getDistance(sensor1);
  Serial.print(distance);
  Serial.print("\n");

  if (distance < DISTANCE_FROM_OBSTICALE) {  // 10 cm
    setMotorSpinDirection(motor3, COUNTER_CLOCKWISE);
    setMotorSpinDirection(motor4, COUNTER_CLOCKWISE);

    delay(1000);

    setMotorSpinDirection(motor3, CLOCKWISE);
    setMotorSpinDirection(motor4, CLOCKWISE);
  } else {
    delay(200);
  }
}
