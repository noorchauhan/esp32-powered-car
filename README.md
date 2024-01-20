# ESP32-Powered Car

This project involves building a car using an ESP32 microcontroller and an L298N or L293D motor driver to control the steering and back wheels motors.

## Pin Connections for L298N:

### Steering Motor:
- **ESP32 Pin 19 (`steeringPin1`):** Connected to IN1 of L298N.
- **ESP32 Pin 21 (`steeringPin2`):** Connected to IN2 of L298N.

### Back Wheels Motor:
- **ESP32 Pin 22 (`backWheelsPin1`):** Connected to IN3 of L298N.
- **ESP32 Pin 23 (`backWheelsPin2`):** Connected to IN4 of L298N.

### Speed Control:
- **ESP32 Pin 2 (`enablePin`):** Connected to ENA (Enable A) of L298N. Control motor speed using analogWrite.

## Pin Connections for L293D:

### Steering and Back Wheels Motors:
- **ESP32 Pin 19 (`steeringPin1`):** Connected to IN1 of L293D.
- **ESP32 Pin 21 (`steeringPin2`):** Connected to IN2 of L293D.
- **ESP32 Pin 22 (`backWheelsPin1`):** Connected to IN3 of L293D.
- **ESP32 Pin 23 (`backWheelsPin2`):** Connected to IN4 of L293D.

### Speed Control:
- **ESP32 Pin 4 (`enablePin`):** Connected to EN_X of L293D. Control motor speed using analogWrite.

### Power Supply:
- **VIN of L293D:** Connected to Positive (+) of 9V Battery.
- **GND of L293D:** Connected to Negative (-) of 9V Battery.

## My Actual Setup:
![Car](https://github.com/noorchauhan/esp32-powered-car/blob/main/Car.jpg)

## Instructions:
1. Connect the ESP32 GPIO pins to the respective L298N or L293D inputs and enable pins as specified.
2. Connect the GND of ESP32 to GND of the motor driver.
3. Connect VIN or 5V of ESP32 to VCC of the motor driver.
4. Connect the motors to the motor driver outputs.
5. Connect a separate power supply (e.g., battery) to the specified input of the motor driver.

Use power supply according to your motor driver, in 2 attemps I fried my L293D motor driver, I suggest using L298N motor driver as it is the best in handling excessive power, also for powering the ESP32 you can try different methods. Please Note that a 9V battery is not sufficient to power the ESP32 properly. Feel free to customize the connections based on your hardware setup and specifications.

### Controlling the Car:

To control the car, use the provided Python script `keyboard_control.py`. This script allows you to drive the car using keyboard inputs on your computer.

#### Prerequisites:

- Python installed on your computer
- Keyboard library (`pip install keyboard`)

#### Usage:

1. Ensure both the computer and the ESP32 are connected to the same Wi-Fi network.

2. Open a terminal and navigate to the directory containing `keyboard_control.py`. Use the "W" "A" "S" "D" keys to naviagte the car after running the script

3. Run the script:

   ```bash
   python keyboard_control.py

You can reach me out on my email here: [Mail me here](mailto:numerchauhan@gmail.com)
