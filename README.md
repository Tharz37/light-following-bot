# Light Follower Robot

A simple Arduino-based **Light Follower Robot** that follows the brightest light source using **LDR sensors, an L298N motor driver, and BO motors**.

## Components Required
- **Arduino Uno**
- **L298N Motor Driver**
- **3 LDR Sensors** (Light Dependent Resistors)
- **2 BO Motors**
- **Wheels & Chassis**
- **12V Battery / Power Supply**
- **Jumper Wires**

## Circuit Connections
| Component  | Arduino Pin |
|------------|-------------|
| LDR Left   | A0         |
| LDR Center | A1         |
| LDR Right  | A2         |
| Motor ENA  | 9         |
| Motor IN1  | 8         |
| Motor IN2  | 7         |
| Motor ENB  | 10        |
| Motor IN3  | 6         |
| Motor IN4  | 5         |

## Working Principle
- The LDR sensors detect light intensity.
- The Arduino compares LDR values to determine the brightest direction.
- Based on the light direction, the motors are controlled via the L298N driver:
  - **Move Forward** if the center LDR gets the most light.
  - **Turn Left** if the left LDR gets more light.
  - **Turn Right** if the right LDR gets more light.
  - **Stop** if no significant light is detected.

## Installation & Uploading Code
1. Connect the circuit as per the **wiring table** above.
2. Install the **Arduino IDE** and connect your **Arduino Uno**.
3. Upload the `light_follower.ino` sketch.
4. Power the setup and test the movement!

## Usage
- Use a **torch or flashlight** to guide the robot.
- Place it in a **dim environment** for better results.
- Adjust **PWM values** in the code for speed tuning.

## Code Repository
Check out the source code on GitHub: [Your Repository Link]

## License
This project is open-source under the **MIT License**. Feel free to modify and improve it! 🚀

## Teammates
Tharun Oommen Jacob
Shahazad Abdulla 
Sidharth Sajith
