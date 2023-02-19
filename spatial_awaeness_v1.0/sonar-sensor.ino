// struct SonarSensor {
//   int trig;
//   int echo;
// }

SonarSensor defineSonarSensor(int trig, int echo) {
  SonarSensor sensor = { trig, echo };
  return sensor;
}

void setSonarSensor(SonarSensor sensor) {
  pinMode(sensor.trig, OUTPUT);
  pinMode(sensor.echo, INPUT);
}

// returns distance in cm
int getDistance(SonarSensor sensor) {
  digitalWrite(sensor.trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor.trig, LOW);

  return pulseIn(sensor.echo, HIGH) / 58;
}


// SonarSensor sensor1 = defineSonarSensor(6, 7);

// void setup() {
//   Serial.begin(9600);
//   setSonarSensor(sensor1);
// }

// void loop() {
//   // put your main code here, to run repeatedly:

//   int duration = distance(sensor1);

//   if (duration >= 38000) {
//     Serial.print("out of range");
//   } else {
//     Serial.print(duration);
//     Serial.print("cm");
//     Serial.print("\n");
//   }
//   delay(500);
// }
