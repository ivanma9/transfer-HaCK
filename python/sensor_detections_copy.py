import serial

coordinate_dict = {

}
baud = 9600
port = "/dev/tty.HC-05-DevB"

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
            frData = float(data[-2])
            #flData = float(data[-2])
            distances.append()     # Append the distance to the list (second from last position)
            coordinate_dict ['ultraFrontRight'] = float(data[-2])
            #coordinate_dict ['ultraFrontLeft']  = float(data[-2])
        except:
            print("Keyboard Interrupt")         # Use CTRL + C
            print(distances)
            break



main()