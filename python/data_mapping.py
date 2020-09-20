import serial
import matplotlib.pyplot as plt
import numpy as np

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
    
    distancesFL = []
    distancesFR = []
    distancesSL = []
    distancesSR = []
    
    plt.ion()
    fig = plt.figure()
    x = 0;
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
        
        distancesFL.append(FL) 
        distancesFR.append(FR)
        distancesSL.append(L)
        distancesSR.append(R)
        
        w = 5
        v = 7
        
        if turns % 4 == 0:
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(150 - FL - v, L + w)
                plt.scatter(150 - FL - v, R)
            else:
                turns += 1
                plt.scatter(150 - FL - v, L + w)
                plt.scatter(150 - FL - v, R)
        elif turns % 4 == 1:
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(150 - L - w, FL - v)
                plt.scatter(150 - R, FL - v)
            else:
                turns += 1
                plt.scatter(150 - L - w, FL - v)
                plt.scatter(150 - R, FL - v)
        elif turns % 4 == 2:
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(FL + v, 150 - L)
                plt.scatter(FL + v, R)
            else:
                turns += 1
                plt.scatter(FL + v, 150 - L)
                plt.scatter(FL + v, R)
        elif turns % 4 == 3:
            if (FL > 10.00) or (FR > 10.00):
                plt.scatter(L + w, FL + v)
                plt.scatter(L + w, R)
            else:
                turns += 1
                plt.scatter(L + w, FL + v)
                plt.scatter(L + w, R)
                    
        plt.show()
        plt.pause(0.0001)



main()
