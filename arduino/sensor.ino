//#include <Servo.h>

//Servo myServo;
//int servoPos = 0;

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

    /*
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
    */
    if (objDist_FL < 10.00) {
        // Turn right
        goRight();
    }
    /*
    else if (objDist_FR < 5.00) {
        // Turn left
        goLeft();
    }
    else {
        goForward();
    }
    */
    /*
    if (objDistance < 4) {
      digitalWrite(ledPin, HIGH);
      if (servoPos <= 90) {
        for (servoPos; servoPos <= 90; servoPos += 1) { // goes from 0 to 180 degrees
          // in steps of 1 degree
          myServo.write(servoPos);// tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
      else {
         if (servoPos != 0) {
            for (servoPos; servoPos >= 0; servoPos -= 1) { // goes from 0 to 180 degrees
            // in steps of 1 degree
            myServo.write(servoPos);// tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
          }
        }
      }
    }
    else
      digitalWrite(ledPin, LOW);
     */

    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    Serial.print("Distance = ");
    Serial.print(objDist_FL);
    Serial.println(" cm");

    // Delay so data isn't collected too fast
    delay(100);
}

void goRight() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    pinMode(enableA, OUTPUT);
    analogWrite(enableA, 200);
    analogWrite(enableB, 0);
    delay(2000); 
}

void goLeft() {
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, HIGH);
    digitalWrite(backLeft, HIGH);
    digitalWrite(backRight, LOW);
}

void goForward() {
    digitalWrite(frontLeft, HIGH);
    digitalWrite(frontRight, HIGH);
    digitalWrite(backLeft, LOW);
    digitalWrite(backRight, LOW);
}
        
