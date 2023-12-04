#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int flexSensorPin1 = A0;
int flexSensorPin2 = A1;
int flexSensorPin3 = A2;
int flexSensorPin4 = A3;
int threshold = 100; 

SoftwareSerial hc05(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  hc05.begin(9600);
  mpu.initialize();
}

void loop() {
  int flex1 = analogRead(flexSensorPin1);
  int flex2 = analogRead(flexSensorPin2);
  int flex3 = analogRead(flexSensorPin3);
  int flex4 = analogRead(flexSensorPin4);

  int angle = getAngle(); 

  if (flex1 > threshold && flex2 > threshold && flex3 > threshold && flex4 > threshold && angle < 30) {
    hc05.println("Hello Arduino");
    delay(1000);
  }
}

int getAngle() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  float angle = atan(ay / sqrt(ax * ax + az * az)) * (180 / PI);
  return abs(angle);
}
