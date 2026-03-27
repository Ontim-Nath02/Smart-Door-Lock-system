# Smart Door Lock System (Arduino + Proteus)

# Overview

This project presents a password-based smart door locking system using Arduino UNO, simulated in Proteus 8. The system enhances security by allowing access only when the correct password is entered through a keypad.


#⚙️ Components Used

* Arduino UNO
* 4×4 Matrix Keypad
* 16×2 LCD Display
* Servo Motor
* Buzzer
* Red and Green LEDs
* Potentiometer (10kΩ)
* External 5V DC external Power Supply



#Features

* Password-based authentication system
* Hidden password input (displayed as `*`)
* Buzzer alert for incorrect password
* LED indicators (Green = Access Granted, Red = Access Denied)
* 3-attempt security lock system
* Reset input using `#` key
* Automatic door locking after access


#Working Principle

1. The user enters a 4-digit password using the keypad
2. The input is hidden for security purposes
3. The Arduino compares the input with the predefined password
4. If the password is correct:

   * Servo motor rotates to unlock the door
   * Green LED turns ON
   * LCD displays "Access Granted"
5. If the password is incorrect:

   * Red LED turns ON
   * Buzzer sounds
   * LCD displays "Access Denied"
6. After three incorrect attempts:

   * The system temporarily locks


## 📐 Circuit Diagram



## 📸 Simulation Preview

![Simulation](proteus/simulation.png)



# Important Notes

* An external 5V DC power supply is required for proper servo motor operation in Proteus
* All components must share a common ground
* LCD contrast should be adjusted using the potentiometer


# Key Learning Outcomes

* Interfacing multiple hardware components with Arduino
* Implementing password-based security logic
* Understanding the importance of external power for actuators
* Avoiding pin conflicts in embedded systems


# Tools & Software Used

* Arduino IDE
* Proteus 8 Professional


# Future Improvements

* Fingerprint sensor integration
* Bluetooth or WiFi-based control
* EEPROM-based password storage


# Author

Ontim Nath
Electrical & Electronic Engineering Student, East Delta University. 
GitHub: https://github.com/Ontim-Nath02
