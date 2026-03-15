# embedded-keypad-lock-system
Password-protected embedded lock system using Arduino, keypad, LCD, servo motor and buzzer.

Overview

This project implements a password-protected electronic door lock system using an Arduino microcontroller. A 4×4 matrix keypad is used to enter the password, while a 16×2 I2C LCD provides system feedback. A buzzer is included to signal successful or incorrect authentication attempts.

The system operates using a state-based logic where the door remains locked by default and only unlocks when the correct password is entered. A password reset mode allows the user to securely change the existing password.

This project demonstrates fundamental embedded systems concepts, including:

->Microcontroller-based input/output control

->Keypad interfacing

->LCD communication via I2C

->State machine design

->User authentication logic



Features:

->4-digit password authentication

->Masked password entry on LCD for privacy

->Error indication using buzzer alerts

->Password reset functionality



Hardware Components

| Component         | Description             |
| ----------------- | ----------------------- |
| Arduino Uno       | Main microcontroller    |
| 4×4 Matrix Keypad | User input for password |
| 16×2 LCD (I2C)    | System status display   |
| Buzzer            | Audio feedback          |
| Breadboard        | Circuit prototyping     |
| Jumper wires      | Connections             |



Circuit Connections
Keypad
| Keypad Pin | Arduino Pin |
| ---------- | ----------- |
| R1         | 12          |
| R2         | 11          |
| R3         | 10          |
| R4         | 9           |
| C1         | 8           |
| C2         | 7           |
| C3         | 6           |
| C4         | 5           |

Other Components
| Component | Arduino Pin |
| --------- | ----------- |
| Buzzer    | 13          |
| LCD SDA   | A4          |
| LCD SCL   | A5          |

The LCD communicates with the Arduino using the I2C protocol, reducing the number of required pins.



System Logic

The system operates in three main states:

1. Locked State

->Default state after startup

->LCD prompts the user to enter a password

->Input is masked with *

2. Unlocked State

->Activated when the correct password is entered

->LCD displays Door Unlocked

->Buzzer emits a short confirmation tone

3. Password Reset Mode

->Triggered when the reset code #### is entered

->System prompts the user to enter a new 4-digit password

->The new password replaces the existing one

->Modular and easy-to-understand Arduino code

->Simple hardware implementation suitable for prototyping




Repository Structure

```
embedded-keypad-lock-system 
│ 
├── code 
│   └── keypad_lock.ino 
│
├── circuit 
│   └── circuitDiagram.png 
│
├── images 
│   ├── door_unlocked.png 
│   ├── enter_code_prompt.png
│   └── error_code.png
│
├── simulation 
│   └── link.txt 
│
└── README.md
```


Simulation

->The repository includes a simulation of the system for testing and demonstration purposes.

->Simulation link is provided in the simulation folder.




Demonstration

->Demo images showing the working prototype are available in the images directory.




Setup Instructions

->Clone the repository

git clone https://github.com/NPandey117/embedded-keypad-lock-system.git

->Open the project in Arduino IDE

->Install required libraries:

LiquidCrystal_I2C

Keypad

->Connect the hardware according to the circuit diagram.

->Upload the code to the Arduino board.




Possible Enhancements

->Servo or solenoid-based physical lock mechanism

->EEPROM-based password storage (retain password after power loss)

->Multiple user passwords

->RFID or biometric authentication

->Mobile app or Bluetooth control



License

This project is intended for educational and demonstration purposes.
