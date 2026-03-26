#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// ---------------- LCD ----------------
// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(A4, A5, A0, A1, A2, A3);

// ---------------- SERVO ----------------
Servo myServo;

// ---------------- BUZZER & LED ----------------
#define buzzer 13
#define greenLED 12
#define redLED 11

// ---------------- KEYPAD ----------------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------------- PASSWORD ----------------
String password = "1234";
String input = "";
int attempts = 0;

// ---------------- SETUP ----------------
void setup() {
  lcd.begin(16, 2);
  lcd.print("Smart Door Lock");

  myServo.attach(10);
  myServo.write(0); // Locked

  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  delay(2000);
  lcd.clear();
  lcd.print("Enter Password:");
}

// ---------------- LOOP ----------------
void loop() {
  char key = keypad.getKey();

  if (key) {

    // Reset input
    if (key == '#') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password:");
      return;
    }

    // Show * instead of actual number
    lcd.setCursor(0, 1);
    input += key;
    lcd.print("*");

    // When 4 digits entered
    if (input.length() == 4) {

      if (input == password) {
        // Correct Password
        lcd.clear();
        lcd.print("Access Granted");

        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);

        myServo.write(90); // Unlock
        delay(3000);
        myServo.write(0);  // Lock

        digitalWrite(greenLED, LOW);
        attempts = 0;
      } 
      else {
        // Wrong Password
        lcd.clear();
        lcd.print("Access Denied");

        digitalWrite(redLED, HIGH);

        // Buzzer alert
        digitalWrite(buzzer, HIGH);
        delay(2000);
        digitalWrite(buzzer, LOW);

        digitalWrite(redLED, LOW);

        attempts++;
      }

      // Lock system after 3 wrong attempts
      if (attempts >= 3) {
        lcd.clear();
        lcd.print("System Locked!");
        
        digitalWrite(buzzer, HIGH);
        delay(5000);
        digitalWrite(buzzer, LOW);

        attempts = 0;
      }

      // Reset system
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password:");
      input = "";
    }
  }
}