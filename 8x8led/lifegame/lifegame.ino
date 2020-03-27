#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

#include <Wire.h>

struct location {
  int x;
  int y;
};

location locs[8] = {
  { -1, -1}, {0, -1}, {1, -1},
  { -1, 0},               {1, 0},
  { -1, 1}, {0, 1}, {1, 1}
};

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

boolean cells[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
};

void setup() {
  Serial.begin(9600);
  matrix.begin(0x70);
//  
//    for (int x = 0; x < 8; x++) {
//        for (int y = 0; y < 8; y++) {
//          cells[x][y] = random(2) == 0;
//        }
//    }
}


void loop() {
  matrix.clear();
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      boolean isalive = cells[x][y];
      if (isalive) {
        matrix.drawPixel(x, y, LED_ON);
      }
    }
  }
  matrix.writeDisplay();
  delay(1000);
  tick();
}

void tick() {
  boolean new_cells[8][8] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      new_cells[x][y] = isaliveable(x, y);
    }
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      cells[x][y] = new_cells[x][y];
    }
  }
}

boolean isaliveable(int x, int y) {
  int neighbors = 0;
  for (int i = 0; i < 8; i++) {
    location loc = locs[i];
    if(cells[(8 + x + loc.x) % 8][(8 + y + loc.y) % 8]){
      neighbors++;
    }
  }
  if(cells[x][y]){
    if(neighbors < 2 || neighbors >= 4){
      return false;
    }else{
      return true;
    }
  }else{
    if(neighbors == 3){
      return true;
    }else{
      return false;
    }
  }
}
