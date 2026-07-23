# AlertMate: Wearable IoT Fall Detection System

AlertMate is a wearable IoT-based fall detection system designed to provide real-time emergency assistance for elderly individuals and people at risk of falls. The system detects falls using the Arduino Nano 33 BLE Sense Rev2's built-in 9-DOF IMU sensor, communicates with an Android application via Bluetooth Low Energy (BLE), and sends emergency alerts with the user's GPS location through Firebase Cloud Messaging (FCM).

## Features

- Real-time fall detection using 9-DOF IMU sensor
- EMA (Exponential Moving Average)-based adaptive thresholding
- Bluetooth Low Energy (BLE) communication
- Android companion application
- Firebase Cloud Messaging (FCM) notifications
- GPS location sharing
- Multi-channel emergency alerts
- Low-latency alert delivery (< 3 seconds)

## System Architecture

```
Arduino Nano 33 BLE Sense Rev2
          │
      IMU Sensor
          │
   Fall Detection Algorithm
          │
      BLE Communication
          │
    Android Application
          │
    GPS Location Retrieval
          │
 Firebase Cloud Messaging
          │
 Emergency Contact Notification
```

## Technologies Used

### Hardware

- Arduino Nano 33 BLE Sense Rev2
- 9-DOF IMU Sensor
- Li-ion Battery
- Bluetooth Low Energy (BLE)

### Software

- Arduino IDE
- Android Studio
- Firebase Cloud Messaging (FCM)
- Bluetooth Low Energy (BLE)
- Java/Kotlin
- C++

## Detection Algorithm

The fall detection process consists of:

1. Read accelerometer and gyroscope data.
2. Apply Exponential Moving Average (EMA) filtering.
3. Detect free-fall condition.
4. Detect impact using adaptive thresholds.
5. Verify body orientation.
6. Confirm fall event.
7. Transmit alert to Android application via BLE.
8. Retrieve current GPS location.
9. Send emergency notification through Firebase.

## Performance

| Metric | Value |
|---------|-------|
| Accuracy | **95.2%** |
| Recall | **94.1%** |
| F1-Score | **95.0%** |
| Test Samples | **105** |
| Alert Latency | **< 3 seconds** |

## Repository Structure

```
AlertMate/
│
├── Arduino/
│   ├── AlertMate.ino
│   └── ...
│
├── Android-App/
│   ├── app/
│   ├── gradle/
│   ├── build.gradle
│   ├── settings.gradle
│   └── ...
│
├── Images/
│   ├── Architecture.png
│   ├── Hardware.jpg
│   ├── App1.png
│   └── App2.png
│
├── Docs/
│   ├── Project_Report.pdf
│   ├── Presentation.pdf
│   └── User_Manual.pdf
│
├── LICENSE
└── README.md
```

## Installation

### Arduino

1. Install Arduino IDE.
2. Install the Arduino Nano 33 BLE board package.
3. Install the required libraries.
4. Open the Arduino project.
5. Upload the code to the Arduino Nano 33 BLE Sense Rev2.

### Android

1. Open the Android project in Android Studio.
2. Sync Gradle dependencies.
3. Add your Firebase configuration (`google-services.json`).
4. Build and install the application on an Android device.
5. Pair the application with the Arduino device using BLE.

## Usage

1. Wear the AlertMate device.
2. Connect it to the Android application.
3. The system continuously monitors motion using IMU data.
4. Upon detecting a fall:
   - The Android application receives the BLE alert.
   - GPS location is obtained.
   - Firebase Cloud Messaging sends emergency notifications to registered contacts.

## Results

- Successfully detects falls in real time.
- Provides emergency notifications within **3 seconds**.
- Achieved **95.2% accuracy**, **94.1% recall**, and **95.0% F1-score** on 105 test samples.

## Future Improvements

- Cloud-based health monitoring dashboard
- Smartwatch integration
- Voice assistant integration
- AI-based personalized fall detection
- Indoor location tracking
- Health sensor integration (Heart Rate, SpO₂)

## Publication

This work was accepted as a **Category I Demo** at:

**IEEE CONECCT 2026 (12th IEEE International Conference on Electronics, Computing and Communication Technologies)**

## Authors

**Revanth N**

M.Tech in Data Science & Artificial Intelligence

Indian Institute of Information Technology, Surat

## License

This project is licensed under the MIT License.

---

If you use this project in your research or academic work, please consider giving appropriate credit.
