#include <WiFi.h>

const char* ssid = "your-ssid";
const char* password = "your-password";
int esp32_port = 80;

int steeringPin1 = 19;
int steeringPin2 = 21;
int backWheelsPin1 = 22;
int backWheelsPin2 = 23;
int enablePin = 2;

WiFiServer server(esp32_port);

void setup() {
    Serial.begin(115200);
    delay(5000);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    delay(2000);
    Serial.print("Connected to WiFi. IP address: ");
    Serial.println(WiFi.localIP());

    server.begin();

    // Initialize motor control pins
    pinMode(steeringPin1, OUTPUT);
    pinMode(steeringPin2, OUTPUT);
    pinMode(backWheelsPin1, OUTPUT);
    pinMode(backWheelsPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        while (client.connected()) {
            if (client.available()) {
                char command = client.read();
                executeCommand(command);
            }
        }
        client.stop();
    }
}

void executeCommand(char command) {
    Serial.print("Received command: ");
    Serial.println(command);

    switch (command) {
        case 'F':
            moveForward();
            break;
        case 'B':
            moveBackward();
            break;
        case 'L':
            turnLeft();
            break;
        case 'R':
            turnRight();
            break;
        case 'S':
            stopMoving();
            break;
        default:
            Serial.println("Invalid command");
            break;
    }
}



void moveForward() {
    digitalWrite(steeringPin1, LOW);
    digitalWrite(steeringPin2, LOW);
    digitalWrite(backWheelsPin1, HIGH);
    digitalWrite(backWheelsPin2, LOW);
    digitalWrite(enablePin, HIGH);  // Set enable pin to HIGH for full speed
}

void moveBackward() {
    digitalWrite(steeringPin1, LOW);
    digitalWrite(steeringPin2, LOW);
    digitalWrite(backWheelsPin1, LOW);
    digitalWrite(backWheelsPin2, HIGH);
    digitalWrite(enablePin, HIGH);  // Set enable pin to HIGH for full speed
}

void turnLeft() {
    digitalWrite(steeringPin1, HIGH);
    digitalWrite(steeringPin2, LOW);
    digitalWrite(enablePin, HIGH);  // Set enable pin to HIGH for full speed
}

void turnRight() {
    digitalWrite(steeringPin1, LOW);
    digitalWrite(steeringPin2, HIGH);
    digitalWrite(enablePin, HIGH);  // Set enable pin to HIGH for full speed
}

void stopMoving() {
    digitalWrite(steeringPin1, LOW);
    digitalWrite(steeringPin2, LOW);
    digitalWrite(backWheelsPin1, LOW);
    digitalWrite(backWheelsPin2, LOW);
    digitalWrite(enablePin, LOW);  // Set enable pin to LOW to stop the motors
}

