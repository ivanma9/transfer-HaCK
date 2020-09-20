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

    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    Serial.print("Front left distance = ");
    Serial.print(objDist_FL);
    Serial.println(" cm");

    Serial.print("Front right distance = ");
    Serial.print(objDist_FR);
    Serial.println(" cm");

    Serial.print("Left side distance = ");
    Serial.print(objDist_L);
    Serial.println(" cm");

    Serial.print("Right side distance = ");
    Serial.print(objDist_R);
    Serial.println(" cm");

    Serial.print("\n\n\n");

    // Delay so data isn't printed too fast
    delay(5000);
}

void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on front motor A
  analogWrite(F_ENA, 200);
  analogWrite(F_ENB, 200);
  
  digitalWrite(F_IN1, HIGH);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, HIGH);
  digitalWrite(F_IN4, LOW);

  analogWrite(B_ENA, 200);
  analogWrite(B_ENB, 200);
  
  digitalWrite(B_IN1, HIGH);
  digitalWrite(B_IN2, LOW);
  digitalWrite(B_IN3, HIGH);
  digitalWrite(B_IN4, LOW);
 
  delay(2000);
  
  // now change motor directions
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, HIGH);  
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, HIGH); 
  delay(2000);

  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, HIGH);  
  digitalWrite(B_IN3, LOW);
  digitalWrite(B_IN4, HIGH); 
  delay(2000);
  
  // now turn off motors
  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, LOW);  
  digitalWrite(B_IN3, LOW);
  digitalWrite(B_IN4, LOW);
  
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, LOW);  
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, LOW);
}

void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, HIGH);  
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, HIGH); 

  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, HIGH);  
  digitalWrite(B_IN3, LOW);
  digitalWrite(B_IN4, HIGH); 
  
  // accelerate from zero to maximum speed
 for (int i = 0; i < 256; i++) { 
    analogWrite(F_ENA, i); 
    analogWrite(F_ENB, i); 
    analogWrite(B_ENA, i); 
    analogWrite(B_ENB, i);
    delay(20); 
  } 
  // decelerate from maximum speed to zero 
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(F_ENA, i);
    analogWrite(F_ENB, i);
    analogWrite(B_ENA, i); 
    analogWrite(B_ENB, i);
    delay(20);
  } 

  // now turn off motors
  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, LOW);  
  digitalWrite(B_IN3, LOW);
  digitalWrite(B_IN4, LOW);
  
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, LOW);  
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, LOW);
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
  // ALL WHEELS GO FORWARD, BUT AT DIFFERENT SPEEDS
  digitalWrite(F_IN1, HIGH);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, HIGH);
  digitalWrite(F_IN4, LOW);
  
  digitalWrite(B_IN1, HIGH);
  digitalWrite(B_IN2, LOW);
  digitalWrite(B_IN3, HIGH);
  digitalWrite(B_IN4, LOW); 

  // Keep the left side wheels at the max speed
  analogWrite(F_ENA, 255);
  analogWrite(B_ENA, 255);
  
  // Accelerate the right side wheels from 128 to maximum speed
  for (int i = 128; i < 256; i++) {  
     analogWrite(F_ENB, i); 
     analogWrite(B_ENB, i);
  }

  delay(2000);

  // CLOCKWISE/COUNTER-CLOCKWISE AT THE SAME SPEED
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
}
