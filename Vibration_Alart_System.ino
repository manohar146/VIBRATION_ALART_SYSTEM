#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int vibrationPin = A0;
const int redLedPin = 8;
const int greenLedPin = 9;
const int buzzerPin = 10;

int dangerThreshold = 400;
unsigned long dangerHoldTime = 2000;
unsigned long lastDangerTime = 0;

bool dangerMode = false;

void setup() {
  pinMode(vibrationPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Vibration Monitor");
  delay(2000);
  lcd.clear();

  Serial.begin(9600); // Start serial communication
}

void loop() {
  int vibrationValue = analogRead(vibrationPin);
  unsigned long currentTime = millis();

  // Send raw value to Serial Plotter
  Serial.println(vibrationValue);

  lcd.setCursor(0, 0);
  lcd.print("Vib Level: ");
  lcd.print(vibrationValue);
  lcd.print("   ");

  // Check for danger level
  if (vibrationValue >= dangerThreshold) {
    dangerMode = true;
    lastDangerTime = currentTime;
  }

  // Maintain danger mode for at least 2 seconds
  if (dangerMode && (currentTime - lastDangerTime > dangerHoldTime)) {
    dangerMode = false;
  }

  if (dangerMode) {
    // Blink red LED every 300ms
    if (currentTime % 600 < 300) {
      digitalWrite(redLedPin, HIGH);
    } else {
      digitalWrite(redLedPin, LOW);
    }

    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Status: DANGER!! ");
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE     ");
  }

  delay(50); // Fast update for smoother plot
}
