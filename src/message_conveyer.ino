/*
  Button-Based Message Conveyer System for Paralysis Patients
  Button 1 -> D2; Button 2 -> D3; Button 3 -> D4
  Each input: 10 kOhm pull-down to GND; button connects input to 5V.
  I2C LCD: SDA -> A4, SCL -> A5 on Arduino Uno/Nano.
  HIGH = pressed; LOW = released.
  External pull-down wiring is used; do not use INPUT_PULLUP here.
  Default LCD address: 0x27 (change to 0x3F if required).
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte BUTTON_1_PIN = 2;
const byte BUTTON_2_PIN = 3;
const byte BUTTON_3_PIN = 4;
const byte LCD_ADDRESS = 0x27;
const unsigned long DEBOUNCE_MS = 35;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
byte stablePattern = 0;
byte lastRawPattern = 0;
byte lastShownPattern = 255;
unsigned long lastRawChange = 0;

byte readButtons() {
  byte value = 0;
  if (digitalRead(BUTTON_1_PIN) == HIGH) value |= 0b001;
  if (digitalRead(BUTTON_2_PIN) == HIGH) value |= 0b010;
  if (digitalRead(BUTTON_3_PIN) == HIGH) value |= 0b100;
  return value;
}

void showMessage(const char *line1, const char *line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void displayPattern(byte pattern) {
  switch (pattern) {
    case 0b000: showMessage("MESSAGE SYSTEM", "WAITING..."); break;
    case 0b001: showMessage("HELLO", "EVERYONE"); break;
    case 0b010: showMessage("BYE", "EVERYONE"); break;
    case 0b100: showMessage("I NEED HELP", ""); break;
    case 0b011: showMessage("EMERGENCY", ""); break;
    case 0b101: showMessage("PLEASE COME", "HERE"); break;
    case 0b110: showMessage("WATER", "PLEASE"); break;
    case 0b111: showMessage("I AM NOT OK", "HELP ME"); break;
    default:    showMessage("INPUT ERROR", ""); break;
  }
}

void setup() {
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);

  lcd.init();
  lcd.backlight();
  showMessage("MESSAGE SYSTEM", "INITIALIZING...");
  delay(1000);

  stablePattern = readButtons();
  lastRawPattern = stablePattern;
  displayPattern(stablePattern);
  lastShownPattern = stablePattern;
}

void loop() {
  unsigned long now = millis();
  byte rawPattern = readButtons();

  if (rawPattern != lastRawPattern) {
    lastRawPattern = rawPattern;
    lastRawChange = now;
  }

  if ((now - lastRawChange >= DEBOUNCE_MS) &&
      stablePattern != lastRawPattern) {
    stablePattern = lastRawPattern;
  }

  if (stablePattern != lastShownPattern) {
    displayPattern(stablePattern);
    lastShownPattern = stablePattern;
  }
}
