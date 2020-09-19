//L293D
//enable 
const int enableFrontMotor = 7;
const int enableBackMotor = 2;

//Motor A
const int frontLeft  = 6;  // Pin 14 of L293
const int frontRight  = 5;  // Pin 10 of L293
//Motor B
const int backRight  = 4; // Pin  7 of L293
const int backLeft  = 3;  // Pin  2 of L293

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(enableFrontMotor, OUTPUT);
    pinMode(enableBackMotor, OUTPUT);
    pinMode(frontLeft, OUTPUT);
    pinMode(frontRight, OUTPUT);
    pinMode(backRight, OUTPUT);
    pinMode(backLeft, OUTPUT);
    
    //enable
    analogWrite(enableFrontMotor, 200);
    analogWrite(enableBackMotor, 200);
  
    //Motor Control - Motor A: frontLeft,frontRight & Motor B: backRight,backLeft

    /*
    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(frontLeft, HIGH);
    digitalWrite(frontRight, LOW);
    digitalWrite(backRight, LOW);
    digitalWrite(backLeft, LOW);
    delay(2000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, HIGH);
    digitalWrite(backRight, LOW);
    digitalWrite(backLeft, LOW);
    delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, LOW);
    digitalWrite(backRight, HIGH);
    digitalWrite(backLeft, LOW);
    delay(2000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, LOW);
    digitalWrite(backRight, LOW);
    digitalWrite(backLeft, HIGH);
    delay(2000);    
    */

    // Clockwise movement
    digitalWrite(frontLeft, HIGH);
    digitalWrite(frontRight, LOW);
    digitalWrite(backRight, HIGH);
    digitalWrite(backLeft, LOW);
    delay(2000); 

    // Counter-clockwise movement
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, HIGH);
    digitalWrite(backRight, LOW);
    digitalWrite(backLeft, HIGH);
    delay(2000);

    //And this code will stop motors
    digitalWrite(frontLeft, LOW);
    digitalWrite(frontRight, LOW);
    digitalWrite(backRight, LOW);
    digitalWrite(backLeft, LOW);
}

void loop(){
  

}
