import socket
import keyboard
import time

# Replace with the actual IP address of your ESP32
esp32_ip = "192.168.10.219"
esp32_port = 80

def send_command(command):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((esp32_ip, esp32_port))
            s.sendall(command.encode())
            time.sleep(0.1)  # Small delay to allow ESP32 to process the command
    except Exception as e:
        print(f"Error sending command: {e}")

def main():
    keys_pressed = set()

    while True:
        active_keys = set(key for key in ['w', 's', 'a', 'd'] if keyboard.is_pressed(key))
        new_keys = active_keys - keys_pressed
        released_keys = keys_pressed - active_keys

        for key in new_keys:
            keys_pressed.add(key)
            handle_key_press(key)

        for key in released_keys:
            keys_pressed.remove(key)
            handle_key_release(key)

        time.sleep(0.1)  # Add a small delay to avoid excessive CPU usage

def handle_key_press(key):
    if key == 'w':
        send_command('F')
    elif key == 's':
        send_command('B')
    elif key == 'a':
        send_command('L')
    elif key == 'd':
        send_command('R')
        
def handle_key_release(key):
    if key in ['w', 's', 'a', 'd']:
        send_command('S')

if __name__ == "__main__":
    main()
