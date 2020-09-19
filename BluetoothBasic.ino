char Incoming_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    float val = 30.00;
    char cmd = Serial.read();
    if (cmd == 's')
    {
      Serial.println(val);
      delay(100);
    }
  }
}
