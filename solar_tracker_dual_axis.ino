#include <Servo.h>

// Define servos
Servo servoX;  // Left-right
Servo servoY;  // Up-down

// LDR pins
int ldrTopLeft = A0;
int ldrTopRight = A1;
int ldrBottomLeft = A2;
int ldrBottomRight = A3;

// Servo positions
int posX = 90;
int posY = 90;

void setup() {
  servoX.attach(9);  // Horizontal axis
  servoY.attach(10); // Vertical axis

  servoX.write(posX);
  servoY.write(posY);

  Serial.begin(9600);
}

void loop() {
  int tl = analogRead(ldrTopLeft);
  int tr = analogRead(ldrTopRight);
  int bl = analogRead(ldrBottomLeft);
  int br = analogRead(ldrBottomRight);

  // Average light for left and right
  int leftLight = (tl + bl) / 2;
  int rightLight = (tr + br) / 2;

  // Average light for top and bottom
  int topLight = (tl + tr) / 2;
  int bottomLight = (bl + br) / 2;

  int diffX = leftLight - rightLight;
  int diffY = topLight - bottomLight;

  // Horizontal movement
  if (abs(diffX) > 50) {
    if (diffX > 0 && posX < 180) posX++;
    else if (diffX < 0 && posX > 0) posX--;
    servoX.write(posX);
  }

  // Vertical movement
  if (abs(diffY) > 50) {
    if (diffY > 0 && posY < 180) posY++;
    else if (diffY < 0 && posY > 0) posY--;
    servoY.write(posY);
  }

  delay(100);
}
