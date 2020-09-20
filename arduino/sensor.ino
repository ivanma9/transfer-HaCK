float readSensors() {
    long soundTime;
    float objDist_FL, objDist_FR, objDist_L, objDist_R;

    // FRONT LEFT SENSOR
    digitalWrite(trigPinFrontLeft, LOW);
    delayMicroseconds(2);
    // Trigger the sensor
    digitalWrite(trigPinFrontLeft, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFrontLeft, LOW);
    // Read the echoPin, give pulseIn the length of the pulse in microseconds:
    soundTime = pulseIn(echoPinFrontLeft, HIGH);
    // Distance = Speed * Time, Speed of sound = 0.0343 cm/µs
    // Divide by 2 because only the dist to the obj is wanted, not the round trip
    objDist_FL = float(soundTime * 0.0343 / 2);

    // FRONT RIGHT SENSOR
    digitalWrite(trigPinFrontRight, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinFrontRight, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFrontRight, LOW);
    soundTime = pulseIn(echoPinFrontRight, HIGH);
    objDist_FR = float(soundTime * 0.0343 / 2);

    // LEFT SIDE SENSOR
    digitalWrite(trigPinLeft, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinLeft, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinLeft, LOW);
    soundTime = pulseIn(echoPinLeft, HIGH);
    objDist_L = float(soundTime * 0.0343 / 2);

    // RIGHT SIDE SENSOR
    digitalWrite(trigPinRight, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinRight, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinRight, LOW);
    soundTime = pulseIn(echoPinRight, HIGH);
    objDist_R = float(soundTime * 0.0343 / 2);

    if (objDist_FL > 10.00 || objDist_FR > 10.00) {
        goForward();
    }
    else {
        turnRight();
        goForward();
    }

    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    Serial.print(objDist_FL);
    Serial.print(" ");

    Serial.print(objDist_FR);
    Serial.print(" ");
    
    Serial.print(objDist_L);
    Serial.print(" ");

    Serial.println(objDist_R);
}

void goForward() {
  analogWrite(F_ENA, 255);
  analogWrite(F_ENB, 255);
  
  analogWrite(B_ENA, 255);
  analogWrite(B_ENB, 255);
  
  digitalWrite(F_IN1, HIGH);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, HIGH);
  digitalWrite(F_IN4, LOW);
  
  digitalWrite(B_IN1, HIGH);
  digitalWrite(B_IN2, LOW);
  digitalWrite(B_IN3, HIGH);
  digitalWrite(B_IN4, LOW);
}

void turnRight() {
  // WHEELS GO FORWARD ON RIGHT SIDE, BACKWARDS ON LEFT SIDE
  analogWrite(F_ENA, 255);
  analogWrite(F_ENB, 255);
  analogWrite(B_ENA, 255);
  analogWrite(B_ENB, 255);

   digitalWrite(F_IN1, LOW);
   digitalWrite(F_IN2, HIGH);
   digitalWrite(F_IN3, HIGH);
   digitalWrite(F_IN4, LOW);
  
   digitalWrite(B_IN1, HIGH);
   digitalWrite(B_IN2, LOW);
   digitalWrite(B_IN3, LOW);
   digitalWrite(B_IN4, HIGH);

   delay(4940);
}
