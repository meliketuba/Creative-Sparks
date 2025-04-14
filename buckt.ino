const int touchPin = 2;  // Copper tape connected here
bool touched = false;

void setup() {
  pinMode(touchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH && !touched) {
    touched = true;
    Serial.println("Touch detected!");
    triggerArm();  // Call your custom arm movement function
  }

  if (touchState == LOW) {
    touched = false;
  }

  delay(50);
}

void triggerArm() {
  Serial.println(">>> Arm Triggered <<<");
  // Add your arm movement code here
}