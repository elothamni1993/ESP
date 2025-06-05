#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// === Identifiants Wi-Fi ===
const char* ssid = "otmane";
const char* password = "1234560*";

// === Telegram Bot ===
String botToken = "your bot token";
String chatID = "idchat";

// === Broches ===
const int pirPin = 15;   // PIR OUT → GPIO15
const int ledPin = 2;    // LED → GPIO2 (LED interne de l'ESP32)

// === Variables de détection ===
bool motionDetected = false;
unsigned long lastTrigger = 0;
unsigned long cooldown = 10000; // 10 secondes de pause entre alertes

// === Fonction d'envoi de message Telegram ===
void sendTelegramMessage(const String& message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage";
    String payload = "chat_id=" + chatID + "&text=" + message;

    http.begin(url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int responseCode = http.POST(payload);
    http.end();

    if (responseCode == 200) {
      Serial.println("[Telegram] Message envoyé avec succès.");
    } else {
      Serial.printf("[Telegram] Échec d'envoi. Code HTTP: %d\n", responseCode);
    }
  } else {
    Serial.println("[WiFi] Non connecté.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connexion Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("[WiFi] Connexion en cours");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n[WiFi] Connecté avec succès !");
}

void loop() {
  int pirValue = digitalRead(pirPin);

  if (pirValue == HIGH && !motionDetected && (millis() - lastTrigger > cooldown)) {
    motionDetected = true;
    lastTrigger = millis();

    digitalWrite(ledPin, HIGH);
    Serial.println("[PIR] Mouvement détecté !");
    sendTelegramMessage("🚨 Mouvement détecté !");
  }

  if (pirValue == LOW && motionDetected) {
    motionDetected = false;
    digitalWrite(ledPin, LOW);
    Serial.println("[PIR] Zone redevenue calme.");
  }

  delay(200);
}
