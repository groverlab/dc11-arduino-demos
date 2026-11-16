const int sensorPin = 2;  // Sensor OUT pin connected to D2
const int ledPin = 13;    // Built-in Arduino LED

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  // Allow PIR sensors time to stabilize to room temperature
  delay(2000); 
}

void loop() {
  int motionState = digitalRead(sensorPin);

  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}