#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A0
#define RELAY_PIN 8

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Smart Garden");
  delay(2000);
  lcd.clear();
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);
  int moisturePercent = map(soilValue, 1023, 0, 0, 100);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT Error");
    delay(2000);
    return;
  }

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("% | Temp: ");
  Serial.print(t);
  Serial.print("C | Humidity: ");
  Serial.print(h);
  Serial.println("%");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moist:");
  lcd.print(moisturePercent);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C H:");
  lcd.print(h);
  lcd.print("%");

  if (moisturePercent < 40) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Motor: ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Motor: OFF");
  }

  delay(3000);
}
