# 🔥FIRE-FIGHTING-ROBOT-USING-ARDUINO

An autonomous fire detection and extinguishing robot designed using Arduino UNO, ultrasonic and flame sensors, and servo-controlled water spray. Developed as a diploma final-year project under the Department of Electrical & Electronics Engineering.

---

## 🛠️ Project Overview

This robot autonomously detects fire using IR-based flame sensors and navigates toward it using an ultrasonic sensor for obstacle avoidance. Upon detecting the flame, a water pump controlled by a servo nozzle extinguishes the fire.

> 🎯 Objective: To minimize human intervention in hazardous environments and demonstrate real-time fire-response automation using embedded systems.

---

## 🚀 Features

- 🔥 IR Flame detection with 60° coverage
- 🚗 Obstacle detection and avoidance using ultrasonic sensor
- 💧 Water spraying via 5V pump + servo-controlled nozzle
- 🧠 Controlled by ATmega328 (Arduino UNO)
- 🧰 Embedded C-based programming using Arduino IDE

---

## 🧩 Components Used

| Component              | Description                          |
|------------------------|--------------------------------------|
| Arduino UNO            | Main microcontroller board (ATmega328) |
| Flame Sensor (IR)      | Detects fire within a defined range  |
| Ultrasonic Sensor (HC-SR04) | Measures distance to avoid obstacles |
| Servo Motor            | Controls water spray direction       |
| Water Pump (5V)        | Sprays water to extinguish fire      |
| L293D Motor Driver IC  | Controls 4 DC motors for movement    |
| DC Motors (x4)         | Robot chassis propulsion             |
| Power Supply (9V Battery / Adapter) | Supplies power           |

---

## 🔁 Working Principle

1. Flame sensors detect fire in their field of view.
2. Robot navigates toward the fire using DC motors.
3. Ultrasonic sensor avoids obstacles en route.
4. Upon reaching fire, the pump activates to extinguish it.
5. Servo rotates the nozzle to sweep water across the flame area.

---

## 🧪 Testing & Results

- Tested in indoor and outdoor environments.
- Real-time flame detection and accurate direction targeting.
- Water spraying reached a 1-meter effective distance.

---

## 🔧 Setup Instructions

### 1. Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- Embedded C++ / Arduino language
- USB A-B cable for uploading code

### 2. Uploading Code
```bash
# Open Arduino IDE
# Load code/fire_fighting_robot.ino
# Select Board: Arduino UNO
# Select Port: COMx (your Arduino port)
# Click Upload
