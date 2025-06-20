# 🌿 Smart Garden System

An IoT-based garden automation project using ESP32, a soil moisture sensor, and the Blynk Cloud app for real-time monitoring and control of irrigation systems.

## 📌 Features

- 🌱 Real-time soil moisture monitoring
- 🚿 Automatic watering based on moisture threshold
- 📱 Manual control via Blynk mobile app
- 🌐 Wi-Fi-enabled monitoring and alerts

## 🔧 Components Used

- ESP32 Dev Board
- Soil Moisture Sensor
- Relay Module / Pump (optional)
- Jumper Wires, Breadboard
- Blynk IoT App
- Power Supply

## 📸 Screenshots

### Circuit Setup
![Circuit](images/circuit-setup.jpg)

### Blynk App Interface
![Blynk](images/blynk-app-screenshot.png)

## 🔌 Circuit Diagram

> *Include a hand-drawn sketch or Fritzing image here if available.*

## 💻 Code Overview

The Arduino code:
- Connects to Wi-Fi
- Reads soil moisture levels
- Sends data to Blynk
- Activates watering relay if soil is dry

## 📦 Required Libraries

- `WiFi.h`
- `BlynkSimpleEsp32.h`

## 🧪 Setup Instructions

1. Open `smart_garden_code.ino` in Arduino IDE
2. Add your Blynk Auth Token and Wi-Fi credentials
3. Connect hardware as per circuit diagram
4. Upload the code to ESP32
5. Launch Blynk app and monitor/control remotely

## 🚀 Future Improvements

- Integrate weather API for smarter irrigation
- Add OLED display for local display
- Push data to cloud (e.g., Firebase)

## 📜 License

This project is licensed under the [MIT License](LICENSE).

## 👨‍💻 Author

**Subhajit Ghosh**  
B.Tech, Computer Science and Design  
[LinkedIn](https://linkedin.com/in/subhajitghosh) • [GitHub](https://github.com/SubhajitGhosh)
