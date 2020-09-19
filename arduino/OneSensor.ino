#define trigPin 2
#define echoPin 3

long sound_time;
float obj_distance;

void setup() {
    // Inputs, outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  
    //Serial communication, 9600 baud:
    Serial.begin(9600);
}

void loop() {
    // Clear the trigPin for accurate readings
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  
    // Trigger the sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Read the echoPin, give pulseIn the length of the pulse in microseconds:
    sound_time = pulseIn(echoPin, HIGH);
  
    // Distance = Speed * Time
    // Speed of sound = 343 m/s = 0.0343 cm/µs
    // Divide by 2 because only the dist to the obj is wanted, not the round trip
    obj_distance = float(sound_time * 0.0343 / 2);
  
    // Print the distance on the Serial Monitor (Ctrl+Shift+M):
    Serial.print("Distance = ");
    Serial.print(obj_distance);
    Serial.println(" cm");

    // Delay so data isn't collected too fast
    delay(100);
}
