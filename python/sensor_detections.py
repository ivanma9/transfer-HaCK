import serial

baud = 9600
port = "/dev/cu.usbmodem14201"

def main():
    try:
        ser = serial.Serial(port, baud)
        print("Connected to Arduino port:" + port)
    except:
        print("Error connecting to Arduino port")
        exit()
    
    ser.flushInput()
    
    distances = []
    while True:
        try:    
            ser_bytes = ser.readline()          # Get a line from the serial monitor
            data = ser_bytes.decode().split()   # Split each line by whitespace
            if (len(data) != 4):                # A complete line must have 4 elements: Distance = X cm
                continue
            distances.append(int(data[-2]))     # Append the distance to the list (second from last position)
            #print(ser_bytes.decode(), end = "")
        except:
            print("Keyboard Interrupt")         # Use CTRL + C
            print(distances)
            break


main()