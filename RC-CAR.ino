
// Arduino Bluetooth Controlled RC Car
// Arduino UNO + L298N + HC-05

// Motor Driver Pins
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int ENA = 5;
int ENB = 6;

// Bluetooth Pins
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  stopCar();

  Serial.println("Bluetooth RC Car Ready!");
}

void loop() {
  if (BT.available()) {
    char command = BT.read();

    Serial.println(command);

    switch (command) {
      case 'F':
      case 'f':
        forward();
        break;

      case 'B':
      case 'b':
        backward();
        break;

      case 'L':
      case 'l':
        left();
        break;

      case 'R':
      case 'r':
        right();
        break;

      case 'S':
      case 's':
        stopCar();
        break;
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}