#include <Adafruit_BME280.h>

#include <rgb_lcd.h>

#include <Wire.h>
rgb_lcd lcd;

Adafruit_BME280 bme; // use I2C interface
Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

byte celciusTemp[8] {
  0b01000,
  0b10100,
  0b01000,
  0b00111,
  0b01000,
  0b01000,
  0b00111,
  0b00000,
};

void setup() {
  Serial.begin(9600);

  if (!bme.begin()) {
    Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
    while (1) delay(10);
  }

  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 128);
  lcd.createChar(0, celciusTemp);
}


void loop() {
  sensors_event_t temp_event, pressure_event, humidity_event;
  bme_temp->getEvent(&temp_event);
  bme_pressure->getEvent(&pressure_event);
  bme_humidity->getEvent(&humidity_event);
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp_event.temperature);
  lcd.write((unsigned char) 0);
  lcd.print(",H:");
  lcd.print(humidity_event.relative_humidity);
  lcd.print("%");
  lcd.setCursor(2, 1);
  lcd.print("P:");
  lcd.print(pressure_event.pressure);
  lcd.print("hPa");
  delay(1000);
}
