import serial
import matplotlib.pyplot as plt
import numpy as np

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
    
    plt.ion()
    fig = plt.figure()
    turns = 0;
    
    while True:    
        ser_bytes = ser.readline()          # Get a line from the serial monitor
        data = ser_bytes.decode().split()   # Split each line by whitespace
        if (len(data) != 4):                # A complete line must have 4 numbers
            continue
            
        FL = float(data[0])
        FR = float(data[1])
        L = float(data[2])
        R = float(data[3])
        
        w = 5
        v = 7
        
        if turns % 4 == 0: # up
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(L + w, FL + v, c = "black")
                plt.scatter(L + w, R, c = "black")
            else:
                turns += 1
                plt.scatter(L + w, FL + v, c = "black")
                plt.scatter(L + w, R, c = "black")
        elif turns % 4 == 1: #right
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(150 - L - w, FL - v, c = "black")
                plt.scatter(150 - R, FL - v, c = "black")
            else:
                turns += 1
                plt.scatter(150 - L - w, FL - v, c = "black")
                plt.scatter(150 - R, FL - v, c = "black")
        elif turns % 4 == 2: #down
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(FL + v, 150 - L, c = "black")
                plt.scatter(FL + v, R, c = "black")
            else:
                turns += 1
                plt.scatter(FL + v, 150 - L, c = "black")
                plt.scatter(FL + v, R, c = "black")
        elif turns % 4 == 3: #left
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(150 - FL - v, L + w, c = "black")
                plt.scatter(150 - FL - v, R, c = "black")
            else:
                turns += 1
                plt.scatter(150 - FL - v, L + w, c = "black")
                plt.scatter(150 - FL - v, R, c = "black")
                    
        plt.show()
        plt.pause(0.01)

main()
