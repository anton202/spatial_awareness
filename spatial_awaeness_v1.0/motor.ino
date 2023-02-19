// #define CLOCKWISE "clockwise"
// #define COUNTER_CLOCKWISE "counterClockwise"

// struct Motor {
//   int enable_pin;
//   int input1_pin;
//   int input2_pin;
// }


Motor defineMotor(int enable_pin, int input1_pin, int input2_pin) {
  Motor mtr = { enable_pin, input1_pin, input2_pin };
  return mtr;
}

void setMotorPins(Motor motor) {
  pinMode(motor.enable_pin, OUTPUT);
  pinMode(motor.input1_pin, OUTPUT);
  pinMode(motor.input2_pin, OUTPUT);

  // digitalWrite(motor.enable_pin, HIGH);
}

void setMotorSpinDirection(Motor motor, char* direction) {

  if (strcmp(direction, CLOCKWISE) == 0) {
    digitalWrite(motor.input1_pin, HIGH);
    digitalWrite(motor.input2_pin, LOW);
  } else if (strcmp(direction, COUNTER_CLOCKWISE) == 0) {
    digitalWrite(motor.input1_pin, LOW);
    digitalWrite(motor.input2_pin, HIGH);
  }
}

void setMotorSpeed(Motor motor, int speed) {
  analogWrite(motor.enable_pin, speed);
}
