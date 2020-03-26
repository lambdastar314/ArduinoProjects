#include <Adafruit_MMA8451.h>

#include <Wire.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  Serial.begin(9600);
  mma.begin();
  mma.setRange(MMA8451_RANGE_8_G);
  Serial.println("x, y, z");
}

void loop() {
  mma.read();
  sensors_event_t event;
  mma.getEvent(&event);
  Serial.print("");
  Serial.print(event.acceleration.x);
  Serial.print(", ");
  Serial.print(event.acceleration.y);
  Serial.print(", ");
  Serial.println(event.acceleration.z);
  delay(100);
}
