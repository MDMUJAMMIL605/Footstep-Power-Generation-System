// Final Arduino Code for Smart Footsteps Power Generation System
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F (most common) for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 is common, change to 0x3F if needed

int piezoPin = A0; // Piezo output connected to A0
int steps = 0;     // Step counter
float voltage = 0; // Voltage value

void setup() {
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on backlight

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("Footstep Power");
  lcd.setCursor(0, 1);
  lcd.print("Generation");

  delay(2000); // wait for 2 seconds

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Using Piezo");
  lcd.setCursor(0, 1);
  lcd.print("Sensor");

  delay(2000); // wait for 2 seconds

  lcd.clear(); // Ready for live display
}

void loop() {
  int sensorValue = analogRead(piezoPin);

  // Convert analog reading to voltage
  voltage = sensorValue * (5.0 / 1023.0);

  // If voltage exceeds threshold, count as a footstep
  if (voltage > 1.5) {
    steps++;
    delay(300); // debounce delay
  }

  // Display Steps and Voltage
  lcd.setCursor(0, 0);
  lcd.print("Steps:");
  lcd.print(steps);
  lcd.print("   "); // Clear extra digits

  lcd.setCursor(0, 1);
  lcd.print("Voltage:");
  lcd.print(voltage);
  lcd.print("V ");

  delay(500); // refresh every half second
}