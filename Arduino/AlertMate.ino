#include <Arduino_BMI270_BMM150.h>
#include <ArduinoBLE.h>

BLEService fallService("180D");
BLEByteCharacteristic fallCharacteristic("2A37", BLERead | BLENotify);

float freeFallThreshold = 0.4;
float impactThreshold = 2.5;
float avgAcc = 1.0;

const float SMOOTHING = 0.05;
const unsigned long FALL_WINDOW = 1000;

bool freeFallDetected = false;
unsigned long freeFallTime = 0;
bool fallReported = false;

void setup() {
  Serial.begin(9600);
  delay(1000);   // Instead of while(!Serial)

  pinMode(LED_BUILTIN, OUTPUT);

  // Startup indication
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  Serial.println("Initializing IMU and BLE...");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  if (!BLE.begin()) {
    Serial.println("BLE initialization failed!");
    while (1);
  }

  BLE.setLocalName("AlertMate_FallSensor");
  BLE.setAdvertisedService(fallService);

  fallService.addCharacteristic(fallCharacteristic);
  BLE.addService(fallService);

  fallCharacteristic.writeValue((byte)0);

  BLE.advertise();

  Serial.println("BLE advertising started");
  Serial.println("Waiting for connections...");
}

void loop() {
  BLE.poll();   // Keep BLE alive

  BLEDevice central = BLE.central();

  if (central) {
    Serial.print("Connected to: ");
    Serial.println(central.address());

    while (central.connected()) {
      BLE.poll();
      detectFallAdaptive();
      delay(100);
    }

    Serial.println("Disconnected");
  }
}

void detectFallAdaptive() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {

    IMU.readAcceleration(x, y, z);

    float totalAcc = sqrt(x * x + y * y + z * z);

    avgAcc = (1 - SMOOTHING) * avgAcc + SMOOTHING * totalAcc;

    freeFallThreshold = avgAcc * 0.3;
    impactThreshold = avgAcc * 2.8;

    // Free Fall Detection
    if (totalAcc < freeFallThreshold && !freeFallDetected) {
      freeFallDetected = true;
      freeFallTime = millis();

      Serial.println("Free fall detected!");
    }

    // Impact Detection
    if (freeFallDetected &&
        totalAcc > impactThreshold &&
        (millis() - freeFallTime) < FALL_WINDOW) {

      Serial.println("Impact detected! Fall confirmed!");

      fallCharacteristic.writeValue((byte)1);

      freeFallDetected = false;
      fallReported = true;
    }

    // Timeout
    if (freeFallDetected &&
        (millis() - freeFallTime) > FALL_WINDOW) {

      freeFallDetected = false;
      Serial.println("Free fall timeout.");
    }

    // Reset to normal
    if (fallReported &&
        totalAcc > 0.8 &&
        totalAcc < 1.2) {

      fallCharacteristic.writeValue((byte)0);

      fallReported = false;

      Serial.println("System reset.");
    }

    Serial.print("Acc: ");
    Serial.print(totalAcc, 2);

    Serial.print(" | FF Th: ");
    Serial.print(freeFallThreshold, 2);

    Serial.print(" | Impact Th: ");
    Serial.println(impactThreshold, 2);
  }
}