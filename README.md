# 📦 ESP32 PIR Motion Detector with Telegram Alert

This project uses an **ESP32**, a **PIR motion sensor**, and **Telegram Bot API** to detect movement and send real-time alerts directly to your Telegram account.

---

## 🎯 Features

- ✅ Detects motion using a PIR sensor  
- ✅ Sends instant alert messages via Telegram  
- ✅ Activates the onboard LED during motion  
- ✅ Cooldown delay between alerts to prevent spam  
- ✅ Fully wireless and IoT-ready  

---
## 🧰 Hardware Required
![WhatsApp Image 2025-06-05 à 11 25 12_c00e352e](https://github.com/user-attachments/assets/e81b4fc4-325e-4448-9f7d-c8ea88c7d737)

| Component                         | Quantity   |
|----------------------------------|------------|
| ESP32 Dev Board                  | 1          |
| PIR Sensor (HC-SR501 or similar) | 1          |
| LED (optional, or use built-in)  | 1          |
| Jumper Wires                     | As needed  |
| Breadboard                       | (optional) |

---

## 🔌 Wiring Diagram

### PIR Sensor

| PIR Pin | ESP32 Pin |
|---------|-----------|
| VCC     | 3.3V or 5V |
| GND     | GND       |
| OUT     | GPIO 15   |

### LED

| LED Pin | ESP32 Pin |
|---------|-----------|
| +       | GPIO 2    |
| -       | GND       |

---

## ⚙️ How It Works

1. ESP32 connects to your Wi-Fi  
2. It listens for motion from the PIR sensor  
3. When motion is detected:
   - 🚨 A message like “**Mouvement détecté !**” is sent to Telegram
   - 💡 LED is turned ON  
4. After 10 seconds, it allows the next alert

---

## 📲 Telegram Setup
![image](https://github.com/user-attachments/assets/5e52f2ef-6c55-4774-b267-9a5b3725c9bf)

1. Create a bot using [@BotFather](https://t.me/BotFather)
2. Get your **bot token**
3. Start the bot and send it a message like `/start`
4. Visit the following URL to get your `chat_id`:
