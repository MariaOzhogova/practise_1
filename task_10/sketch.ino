// проверяется значение, если оно корректное, сервопривод двигается
// можно резулировать скорость движения через delay()
#include <Servo.h>
Servo myServo;
int currentAngle = 0;
int targetAngle = 0; 
void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  myServo.write(0);
  Serial.println("Введите значение угла (0-180):");
}
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    bool isNumber = true;
    for (int i = 0; i < input.length(); i++) {
      if (!isDigit(input.charAt(i))) {
        isNumber = false;
        break;
      }
    }
    if (isNumber) {
      int angle = input.toInt();
      if (angle >= 0 && angle <= 180) {
        targetAngle = angle;
        Serial.print("Moving to ");
        Serial.println(targetAngle);
        moveSmoothly(targetAngle);
      } else {
        Serial.println("Ошибка!Значение должно быть: 0..180");
      }
    } else {
      Serial.println("Ошибка! Введите число.");
    }
  }
}
void moveSmoothly(int target) {
  if (target == currentAngle) {
    Serial.println("Уже на этом значении");
    return;
  }
  int step = (target > currentAngle) ? 1 : -1;
  for (int angle = currentAngle; angle != target; angle += step) {
    myServo.write(angle);
    delay(15);
  }
  myServo.write(target);
  currentAngle = target;
  Serial.println("Позиция изменена.");
}