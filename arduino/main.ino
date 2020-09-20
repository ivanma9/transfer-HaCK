//Sensors
#define trigPinFrontLeft 49
#define echoPinFrontLeft 48
#define trigPinFrontRight 47
#define echoPinFrontRight 46
#define trigPinLeft 45
#define echoPinLeft 44
#define trigPinRight 43
#define echoPinRight 42

// L298N
// Enable front 
#define F_ENA 9
#define F_ENB 8
//FRONT LEFT WHEEL
#define F_IN1 7 //6   // Pin 14 of L293
#define F_IN2 5   // Pin 10 of L293
//FRONT RIGHT WHEEL
#define F_IN3 6 //4   // Pin  7 of L293
#define F_IN4 3   // Pin  2 of L293

// Enable back
#define B_ENA 11
#define B_ENB 12
// BACK LEFT WHEEL
#define B_IN1 23  // Pin 14 of L293
#define B_IN2 22  // Pin 10 of L293
// BACK RIGHT WHEEL
#define B_IN3 27   // Pin  7 of L293
#define B_IN4 26   // Pin  2 of L293

#define baud 9600

void setup() {
    // Sensors
    pinMode(trigPinFrontLeft, OUTPUT);
    pinMode(echoPinFrontLeft, INPUT);

    pinMode(trigPinFrontRight, OUTPUT);
    pinMode(echoPinFrontRight, INPUT);
    
    pinMode(trigPinLeft, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    
    pinMode(trigPinRight, OUTPUT);
    pinMode(echoPinRight, INPUT);

    // Motors
    pinMode(F_ENA, OUTPUT);
    pinMode(F_ENB, OUTPUT);
    pinMode(F_IN1, OUTPUT);
    pinMode(F_IN2, OUTPUT);
    pinMode(F_IN3, OUTPUT);
    pinMode(F_IN4, OUTPUT);
    pinMode(B_ENA, OUTPUT);
    pinMode(B_ENB, OUTPUT);
    pinMode(B_IN1, OUTPUT);
    pinMode(B_IN2, OUTPUT);
    pinMode(B_IN3, OUTPUT);
    pinMode(B_IN4, OUTPUT);

    // Serial communication
    Serial.begin(baud);
}

void loop() {
    readSensors();
}
