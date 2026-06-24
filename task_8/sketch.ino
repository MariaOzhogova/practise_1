
// две анимации со случайными цветами:
// 1. Дождь
// 2. Смайлик
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 64
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int getLedIndex(int x, int y) {
  if (x < 0 || x > 7 || y < 0 || y > 7) return -1;
  if (y % 2 == 0) return (y * 8) + 7 - x;
  else return (y * 8) + x;
}
void drawPixel(int x, int y, uint32_t color) {
  int index = getLedIndex(x, y);
  if (index != -1) pixels.setPixelColor(index, color);
}
uint32_t randomColor() {
  return pixels.Color(random(50, 255), random(50, 255), random(50, 255));
}
// Дождь
void rainAnimation() {
  int dropY[8];
  uint32_t dropColor[8];
  for (int i = 0; i < 8; i++) {
    dropY[i] = random(-4, 0);
    dropColor[i] = randomColor();
  }
  for (int frame = 0; frame < 40; frame++) {
    pixels.clear();
    for (int x = 0; x < 8; x++) {
      for (int t = 0; t < 4; t++) {
        int y = dropY[x] - t;
        if (y >= 0 && y < 8) {
          uint8_t r = ((dropColor[x] >> 16) & 0xFF) / (t + 1);
          uint8_t g = ((dropColor[x] >> 8)  & 0xFF) / (t + 1);
          uint8_t b = ((dropColor[x])        & 0xFF) / (t + 1);
          drawPixel(x, y, pixels.Color(r, g, b));
        }
      }
      dropY[x]++;
      if (dropY[x] > 9) {
        dropY[x] = random(-5, 0);
        dropColor[x] = randomColor();
      }
    }
    pixels.show();
    delay(80);
  }
}
// Смайлик
uint8_t smileOpen[8][8] = {
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,1,0,0,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0}
};
void drawFrame(uint8_t frame[8][8], uint32_t color) {
  pixels.clear();
  for (int y = 0; y < 8; y++)
    for (int x = 0; x < 8; x++)
      if (frame[y][x] == 1)
        drawPixel(x, y, color);
  pixels.show();
}
void smileAnimation() {
  uint32_t col = randomColor();
  drawFrame(smileOpen, col);
  delay(2000);
}
void setup() {
  randomSeed(analogRead(0));
  pixels.begin();
  pixels.setBrightness(80);
  pixels.show();
}
void loop() {
  rainAnimation();
  delay(300);
  smileAnimation();
  delay(300);
}