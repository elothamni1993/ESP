#include <Arduino.h>

const int PIR_PIN = 14;      // PIR sensor pin
const int LED_PIN = 2;       // Built-in LED pin
const int BUZZER_PIN = 15;
// Motion detection variables
bool lastPirState = false;    // Previous PIR state
bool currentPirState = false; // Current PIR state
unsigned long lastDetectionTime = 0;  // Last detection timestamp
const unsigned long COOLDOWN_PERIOD = 2000;  // Cooldown in milliseconds

void playAlertTone() {
  // Play a short beep
  tone(BUZZER_PIN, 2000, 200); // 2000Hz for 200ms
  delay(200);
  noTone(BUZZER_PIN);
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("PIR Motion Sensor with Buzzer initialized");
}

void loop() {
  currentPirState = digitalRead(PIR_PIN);
  unsigned long currentTime = millis();
  
  // Check for rising edge (motion starts) and cooldown period
  if (currentPirState == HIGH && lastPirState == false) {
    if (currentTime - lastDetectionTime >= COOLDOWN_PERIOD) {
      digitalWrite(LED_PIN, HIGH);
      playAlertTone();  // Activate buzzer
      Serial.println("Motion detected!");
      lastDetectionTime = currentTime;
    }
  } else if (currentPirState == LOW) {
    digitalWrite(LED_PIN, LOW);
  }

  lastPirState = currentPirState;
  delay(100);  // Small delay for stability
}
