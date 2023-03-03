
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

