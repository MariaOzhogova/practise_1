// фоторезистор работает так: чем больше света, тем меньше сопротивление, 
/ тем меньше значение на analogRead => нужно ставить условие не 
// "значение больше 512 - открываем дверь", а наоборот
#define PIN_GREEN 5
#define PIN_RED   9
#define PIN_PHOTO A0
#define THRESHOLD 512
#define DOOR_OPEN_TIME 3000
void setup() {
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
  Serial.println("Система запущена. Двери закрыты.");
}
void loop() {
  int photoValue = analogRead(PIN_PHOTO);
  if (photoValue < THRESHOLD) {
    digitalWrite(PIN_RED, LOW);
    digitalWrite(PIN_GREEN, HIGH);
    Serial.println("Двери открываются.");
    delay(DOOR_OPEN_TIME);
    photoValue = analogRead(PIN_PHOTO);
    if (photoValue < THRESHOLD) {
      Serial.println("Человек всё ещё рядом. Двери остаются открытыми.");
    } else {
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_RED, HIGH);
      Serial.println("Двери закрываются.");
    }
  }

  delay(100);
}