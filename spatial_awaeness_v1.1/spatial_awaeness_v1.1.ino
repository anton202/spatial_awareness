#include "header.h";
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A5, A4, A3, A2);

#define NORMAL_SPEED 100
#define MAX_SPEED 255
#define MAX_DISTANCE_FROM_OBSTICALE 20  // cm

Motor right_motors = defineMotor(6, 7, 8);
Motor left_motors = defineMotor(3, 4, 5);


SonarSensor sensor1 = defineSonarSensor(10, 11);
int distance;

void setup() {
  setMotorPins(right_motors);
  setMotorPins(left_motors);

  setMotorSpeed(right_motors, NORMAL_SPEED);
  setMotorSpeed(left_motors, NORMAL_SPEED);

  setMotorSpinDirection(right_motors, CLOCKWISE);
  setMotorSpinDirection(left_motors, CLOCKWISE);

  setSonarSensor(sensor1);

  // sonar sensor power pin
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);


  //lcd screen setup
  pinMode(12, OUTPUT);     // power
  digitalWrite(12, HIGH);  // power
  lcd.begin(16, 2);

  //Serial.begin(9600);
}

void loop() {
  lcd.clear();

  distance = getDistance(sensor1);
  // Serial.print(distance);
  //Serial.print("\n");

  //LCD DEBUGING
  lcd.print(distance);
  if (distance > 99) {
    lcd.setCursor(4, 0);
  } else {
    lcd.setCursor(3, 0);
  }

  lcd.print("cm");
  lcd.setCursor(0, 0);
  // END OF LCD DEBUGING

  if (distance < MAX_DISTANCE_FROM_OBSTICALE) {
    setMotorSpinDirection(left_motors, COUNTER_CLOCKWISE);
    setMotorSpeed(left_motors, 175);
    setMotorSpeed(right_motors, 175);

    //delay(500);

    //setMotorSpinDirection(left_motors, CLOCKWISE);
    //setMotorSpeed(left_motors, MOTOR_SPEED);

  } else {
    setMotorSpinDirection(left_motors, CLOCKWISE);
    setMotorSpeed(left_motors, NORMAL_SPEED);
    setMotorSpeed(right_motors, NORMAL_SPEED);
  }
  delay(60);  // delay for the sonar sensor
}
