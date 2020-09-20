/*
 * FRONT 2 Motors
 */
const int trigPin = 49;   // sensor 1
const int echoPin = 48;   // sensor 1
const int trigPin2 = 47;  // sensor 2
const int echoPin2 = 46;  // sensor 2
const int trigPin3 = 45;  // sensor 3
const int echoPin3 = 44;  // sensor 3
const int trigPin4 = 43;  // sensor 4
const int echoPin4 = 42;  // sensor 4
long duration;
long duration2;
long duration3;
long duration4;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  Serial.begin(9600);
}

void loop() {

  //ultrasonic 1  - FL - move
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  double distance = (double) duration * 345 /2/ 1000000;

  Serial.print(distance);
  Serial.print(" ");

  
  //ultrasonic 2 - FR - move
  delayMicroseconds(2);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  double distance2 = (double) duration2 * 345 /2/ 1000000;

  Serial.print(distance2);
  Serial.print(" ");


  //ultrasonic 3  - SL - wall
  delayMicroseconds(2);
    
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration3 = pulseIn(echoPin3, HIGH);
  double distance3 = (double) duration3 * 345 /2/ 1000000;

  Serial.print(distance3);
  Serial.print(" ");


  //ultrasonic 4  - SR - objects
  delayMicroseconds(2);
  
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

  duration4 = pulseIn(echoPin4, HIGH);
  double distance4 = (double) duration4 * 345 /2/ 1000000;

  Serial.println(distance4);
  
  
}
