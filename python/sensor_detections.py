import serial

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
    
    distancesFL = []
    distancesFR = []
    distancesSL = []
    distancesSR = []
    while True:
        try:
            #data is for front sensor 1, sensor    
            ser_bytes = ser.readline()              # Get a line from the serial monitor
            #print(ser_bytes)
            data = ser_bytes.decode().split()               # Split each line by whitespace
            if (len(data) != 4):                    # A complete line must have 4 elements: Distance = X cm
                continue
            print(data)
            distancesFL.append(float(data[0]))        # Append the distance to the list (second from last position)
            distancesFR.append(float(data[1]))
            distancesSL.append(float(data[2]))
            distancesSR.append(float(data[3]))
            
            # distance + " " + distance2 + " " + distance3 + " " + distance4

            #print(ser_bytes.decode(), end = "")
            #print(data)
        except:
            print("Keyboard Interrupt")         # Use CTRL + C
            print("Distances 1 Front Left")
            print(distancesFL)
            print("Distances 2 Front Right")
            print(distancesFR)
            print("Distances 3 Side Left")
            print(distancesSL)
            print("Distances 4 Side Right")
            print(distancesSR)

            break
    print("after while: SL")
    print(distancesSL)



main()