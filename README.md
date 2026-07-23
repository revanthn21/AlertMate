# AlertMate: A Low-Cost Wearable IoT Fall Detection System

AlertMate is a wearable IoT-based fall detection system designed to provide real-time emergency assistance for elderly individuals, physically challenged users, and people involved in high-risk activities. The system performs on-device fall detection using the Arduino Nano 33 BLE Sense Rev2 and communicates with an Android application via Bluetooth Low Energy (BLE). When a fall is detected, the mobile application retrieves the user's GPS location and sends real-time emergency alerts to caregivers using Firebase Cloud Messaging (FCM).

## Features

- Wearable real-time fall detection
- On-device inference using adaptive thresholding
- Exponential Moving Average (EMA) based signal smoothing
- Bluetooth Low Energy (BLE) communication
- Android patient and caretaker applications
- Firebase Realtime Database integration
- Firebase Cloud Messaging (FCM) notifications
- GPS location tracking
- User confirmation mechanism to reduce false alarms
- Manual SOS emergency button

---

## System Architecture

```
Wearable Device
(Arduino Nano 33 BLE Sense Rev2)
            │
      IMU Sensor (BMI270)
            │
    Fall Detection Algorithm
            │
      Bluetooth Low Energy
            │
     Android Patient App
            │
 GPS + Firebase Realtime Database
            │
Firebase Cloud Messaging (FCM)
            │
 Android Caretaker App
```

---

## Technology Stack

### Hardware

- Arduino Nano 33 BLE Sense Rev2
- BMI270 IMU
- TP4056 Charging Module
- 3.7V Li-Po Battery

### Software

- Arduino IDE
- Android Studio
- Firebase Realtime Database
- Firebase Cloud Messaging
- Android (Java/Kotlin)

### Communication

- Bluetooth Low Energy (BLE)

---

## Detection Algorithm

The wearable continuously collects accelerometer and gyroscope readings from the BMI270 IMU.

The detection pipeline consists of:

1. Read IMU sensor data
2. Compute resultant acceleration
3. Apply Exponential Moving Average (EMA)
4. Calculate adaptive thresholds
5. Detect free-fall
6. Detect impact
7. Validate rapid transition
8. Check orientation and post-fall inactivity
9. Send BLE alert to Android application
10. Retrieve GPS location
11. Push emergency notification using Firebase

---

## Mobile Application

### Patient Application

- BLE device connection
- Real-time fall status
- GPS location retrieval
- "I'm Safe" confirmation
- Manual SOS button

### Caretaker Application

- Real-time notifications
- Patient status monitoring
- Live GPS location
- Alert history

---

## Performance

| Metric | Value |
|---------|------:|
| Accuracy | 95.2% |
| Recall | 94.1% |
| F1 Score | 95.0% |
| Alert Latency | < 3 seconds |

The adaptive threshold algorithm successfully distinguishes fall events from normal daily activities while maintaining a low false alarm rate. :contentReference[oaicite:1]{index=1}

---

## Repository Structure

```
AlertMate/
│
├── Arduino/
│   ├── AlertMate.ino
│   └── README.md
│
├── Android-App/
│   ├── app/
│   ├── gradle/
│   ├── build.gradle
│   ├── settings.gradle
│   └── ...
│
├── Images/
│   ├── architecture.png
│   ├── patient_dashboard.png
│   ├── caretaker_dashboard.png
│   ├── location_screen.png
│   └── hardware.jpg
│
├── Docs/
│   ├── AlertMate_Paper.pdf
│   └── Presentation.pdf
│
├── README.md
└── LICENSE
```

---

## Installation

### Arduino Firmware

1. Install Arduino IDE.
2. Install the Arduino Nano 33 BLE board package.
3. Install the required libraries.
4. Upload the firmware to the Arduino Nano 33 BLE Sense Rev2.

### Android Application

1. Open the Android project in Android Studio.
2. Add your `google-services.json` file.
3. Sync Gradle.
4. Build and install the application.
5. Pair the wearable device using BLE.

---

## How It Works

1. The wearable continuously monitors motion using the BMI270 IMU.
2. Sensor data is filtered using EMA.
3. Adaptive thresholds identify free-fall and impact events.
4. When a fall is confirmed, the wearable sends an alert via BLE.
5. The Android app retrieves the user's GPS location.
6. Firebase stores the event and triggers FCM notifications.
7. The caretaker receives an instant alert with the patient's location.
8. The patient can confirm they are safe or manually trigger an SOS alert.

---

## Future Improvements

- TinyML-based fall detection
- Smartwatch integration
- Health monitoring sensors (Heart Rate, SpO₂)
- Indoor positioning support
- Cloud analytics dashboard
- Personalized adaptive threshold learning

---

## Publication

**AlertMate: A Low-Cost, Wearable IoT Locket With On-Device Inference For Reliable Fall Detection In Vulnerable Users With Multi-Channel Alerts**

Accepted as a **Category I Demo** at:

**IEEE CONECCT 2026 – 12th IEEE International Conference on Electronics, Computing and Communication Technologies.** :contentReference[oaicite:2]{index=2}

---

## Authors

- Revanth N
- Nitin Kumar Mishra
- Aditya Kharde
- Rakesh Kumar Nayak
- Sejal Rathod
- Dr. Kaustubh Dhondge

Indian Institute of Information Technology Surat

---

## License

This project is licensed under the MIT License.
