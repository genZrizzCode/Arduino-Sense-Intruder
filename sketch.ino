const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11; // Your LED is on Pin 11

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Set Pin 11 as Output
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distanceCm = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  if (distanceCm > 0 && distanceCm <= 30) {
    Serial.println("Intruder Detected!!!");
    digitalWrite(ledPin, HIGH);
    delay(700);
    digitalWrite(ledPin, LOW);
    delay(350);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
