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

volatile int collision;
int totalCollisions = 0;

void setup() {
  setMotorPins(right_motors);
  setMotorPins(left_motors);

  setMotorSpeed(right_motors, NORMAL_SPEED);
  setMotorSpeed(left_motors, NORMAL_SPEED);

  setMotorSpinDirection(right_motors, CLOCKWISE);
  setMotorSpinDirection(left_motors, CLOCKWISE);

  setSonarSensor(sensor1);

  // sonar sensor power pin
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);


  //lcd screen setup
  pinMode(12, OUTPUT);     // power
  digitalWrite(12, HIGH);  // power
  lcd.begin(16, 2);

  Serial.begin(9600);

  // collision sensor
  pinMode(2, INPUT);

  attachInterrupt(digitalPinToInterrupt(2), collisionISR, RISING);
}

void loop() {

  //Serial.print(digitalRead(9));
  distance = getDistance(sensor1);
  // collision = digitalRead(9);

  if (collision > 0) {
    collision = 0;
    setMotorSpinDirection(left_motors, COUNTER_CLOCKWISE);
    setMotorSpinDirection(right_motors, COUNTER_CLOCKWISE);
    delay(500);
    setMotorSpinDirection(right_motors, CLOCKWISE);
    delay(500);
    setMotorSpinDirection(left_motors, CLOCKWISE);
  }



  //distance = getDistance(sensor1);
  // Serial.print(distance);
  //Serial.print("\n");

  //LCD DEBUGING
  lcd.clear();
  lcd.print(distance);
  if (distance > 99) {
    lcd.setCursor(4, 0);
  } else {
    lcd.setCursor(3, 0);
  }

  lcd.print("cm");

  lcd.setCursor(0, 1);
  lcd.print("Total coli:");
  lcd.setCursor(12, 1);
  lcd.print(totalCollisions);

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

// Delay doesent work inside an interupt
// also not sure about structs

void collisionISR() {
  collision++;
  totalCollisions++;
}
