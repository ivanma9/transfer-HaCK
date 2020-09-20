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

    if (objDist_FL > 10.00 && objDist_FR > 10.00) {
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
    Serial.println(" ");
    
    Serial.print(objDist_L);
    Serial.println(" ");

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
  long soundTime;
  float objDist_FL, objDist_FR;

  // WHEELS GO FORWARD ON RIGHT SIDE, BACKWARDS ON LEFT SIDE
  analogWrite(F_ENA, 255);
  analogWrite(F_ENB, 255);
  analogWrite(B_ENA, 255);
  analogWrite(B_ENB, 255);
  
  while (true) {
    digitalWrite(F_IN1, LOW);
    digitalWrite(F_IN2, HIGH);
    digitalWrite(F_IN3, HIGH);
    digitalWrite(F_IN4, LOW);
  
    digitalWrite(B_IN1, HIGH);
    digitalWrite(B_IN2, LOW);
    digitalWrite(B_IN3, LOW);
    digitalWrite(B_IN4, HIGH);

    digitalWrite(trigPinFrontLeft, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinFrontLeft, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFrontLeft, LOW);
    soundTime = pulseIn(echoPinFrontLeft, HIGH);
    objDist_FL = float(soundTime * 0.0343 / 2);
    /*
    // FRONT RIGHT SENSOR
    digitalWrite(trigPinFrontRight, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinFrontRight, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinFrontRight, LOW);
    soundTime = pulseIn(echoPinFrontRight, HIGH);
    objDist_FR = float(soundTime * 0.0343 / 2);
    */

    if (objDist_FL > 10.00)
      break;
  }
     
    /*
    AcX = Wire.read()<<8|Wire.read(); 
    //AcY = Wire.read()<<8|Wire.read(); 
    AcZ = Wire.read()<<8|Wire.read(); 
    int xAng = map(AcX,minVal,maxVal,-90,90); 
    //int yAng = map(AcY,minVal,maxVal,-90,90); 
    int zAng = map(AcZ,minVal,maxVal,-90,90);

    //x = RAD_TO_DEG * (atan2(-yAng, -zAng)+PI); 
    y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI); 
    //z = RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
    int yAng = map(AcY, minVal, maxVal, -90, 90); 
    y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);

    if (y == 90)
      break;
     */
    /*
    unsigned long timer = 0;
    float timeStep = 0.01;
    float yaw = 0;

    while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
    {
      Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
      delay(500);
    }

    mpu.calibrateGyro();
    mpu.setThreshold(3);

    timer = millis();
    Vector norm = mpu.readNormalizeGyro();
    yaw = yaw + norm.ZAxis * timeStep;
    delay((timeStep*1000) - (millis() - timer));
    if (yaw == 90)
      break;
  }
  */
  //delay(4425);

}
