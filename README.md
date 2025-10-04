# VIBRATION_ALART_SYSTEM
This project continuously monitors vibration levels using a vibration sensor, displays real-time readings on a 16x2 I2C LCD, and classifies the system state as SAFE or DANGER based on a predefined threshold—activating a green LED and displaying "Status: SAFE" when vibration is low, and triggering a blinking red LED, buzzer alert, and "Status: DANGER!!"  
# ⚠️ Vibration Alert System (Arduino UNO)

## Overview
This project implements a vibration detection and alert system using Arduino UNO and a piezo or vibration sensor. It monitors physical disturbances and triggers alerts when vibration exceeds a defined threshold. Ideal for security systems, machinery monitoring, or embedded learning. The repository includes source code, documentation, pin mapping, waveform logic, and circuit visuals for easy replication and understanding.

## Tech Stack
- Arduino UNO (`VIBRATION_ALERT_SYSTEM_WAVEFORM.ino`)
- Vibration or piezo sensor
- Buzzer or LED for alert output
- Excel for pin configuration
- Word and PowerPoint for documentation and presentation

## Files Included
- `VIBRATION_ALERT_SYSTEM_WAVEFORM.ino`: Arduino sketch for vibration detection and alert logic
- `Vibration_Alert_System.docx`: Detailed documentation of system design and operation
- `Vibration_Alert_System.pptx`: Presentation slides summarizing the project
- `VIBRATION_ALERT_SYSTEM_PIN_OUTS.xlsx`: Pin configuration and hardware mapping
- `vibration_alert_system.jpg`: Photo of the physical setup
- `circuit_image (6).png`: Circuit diagram
- `README.md`: Project overview and instructions

## Highlights
- Real-time vibration detection with threshold-based alerting
- Waveform-based logic for accurate signal interpretation
- Modular code structure for easy customization
- Clear documentation and pin mapping for reproducibility
- Visual assets for hardware setup and presentation-ready slides

## How It Works
- The vibration sensor detects physical disturbances and sends analog signals to the Arduino
- Arduino processes the signal and compares it against a sensitivity threshold
- If vibration exceeds the limit, an alert is triggered via buzzer or LED
- Circuit and pin mapping ensure accurate signal flow and control

## Author
**Manohar** – Embedded Systems Enthusiast  
📫 [GitHub Profile](https://github.com/manohar146)
