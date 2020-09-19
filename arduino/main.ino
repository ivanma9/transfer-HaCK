#include <Servo.h>

//Sensors
#define trigPinFrontLeft 49
#define echoPinFrontLeft 48
#define trigPinFrontRight 2
#define echoPinFrontRight 3
#define trigPinLeft 6
#define echoPinLeft 7
#define trigPinRight 10
#define echoPinRight 11

// L298N control pins
//CONTROL MOTOR 1
#define enableA 7
#define enableB 2

//Motor A
#define motorPin1 6   // Pin 14 of L293
#define motorPin2 5   // Pin 10 of L293
//Motor B
#define motorPin3 4   // Pin  7 of L293
#define motorPin4 3   // Pin  2 of L293

//CONTROL MOTOR 2
#define enable2A 24
#define enable2B 25

//Motor A
#define motor2Pin1 23  // Pin 14 of L293
#define motor2Pin2 22  // Pin 10 of L293
//Motor B
#define motor2Pin3 27   // Pin  7 of L293
#define motor2Pin4 26   // Pin  2 of L293

// LED
#define ledPin 13
//SERVO
#define servoPin 9
// BAUD
#define baud 9600

//Servo myServo;

void setup() {
    /*
    Sensors
    */
    pinMode(trigPinFrontLeft, OUTPUT);
    pinMode(echoPinFrontLeft, INPUT);
    /*
    pinMode(trigPinFrontRight, OUTPUT);
    pinMode(echoPinFrontRight, INPUT);
    
    pinMode(trigPinLeft, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    
    pinMode(trigPinRight, OUTPUT);
    pinMode(echoPinRight, INPUT);
    */
    
    /* 
    LED
    */
    //pinMode(ledPin, OUTPUT);

    // Servo
    //myServo.attach(servoPin);

    /* 
    Motors
    */
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    pinMode(enable2A, OUTPUT);
    pinMode(enable2B, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor2Pin3, OUTPUT);
    pinMode(motor2Pin4, OUTPUT);
    
    //enable
    analogWrite(enableA, 200);
    analogWrite(enableB, 200);

    analogWrite(enable2A, 200);
    analogWrite(enable2B, 200);

    // Serial communication
    Serial.begin(baud);
}

void loop() {
    readSensors();
}
