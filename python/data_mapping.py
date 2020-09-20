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
        try:    
            ser_bytes = ser.readline()          # Get a line from the serial monitor
            data = ser_bytes.decode().split()   # Split each line by whitespace
            if (len(data) != 4):                # A complete line must have 4 numbers
                continue
            distancesFL.append(float(data[0])) 
            distancesFR.append(float(data[1]))
            distancesSL.append(float(data[2]))
            distancesSR.append(float(data[3]))
            
            if turns % 4 == 0:
                if (not(data[0] <= 10.00) and not(data[0] <= 10.00)):
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x, data[3]) #SR
                    x += 1
                else:
                    turns += 1
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x, data[3]) #SR
            elif turns % 4 == 1:
                if not(data[0] <= 10.00) and not(data[0] <= 10.00):
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x - 10, data[3]) #SR
                else:
                    turns += 1
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x - 10, data[3]) #SR
            elif turns % 4 == 2:
                if not(data[0] <= 10.00) and not(data[0] <= 10.00):
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x - 10, data[3]) #SR
                    x -= 1
                else:
                    turns += 1
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x - 10, data[3]) #SR
            elif turns % 4 == 3:
                if not(data[0] <= 10.00) and not(data[0] <= 10.00):
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x + 10, data[3]) #SR
                else:
                    turns += 1
                    plt.scatter(x, data[2]) #SL
                    plt.scatter(x - 10, data[3]) #SR
                    
            plt.show()
            plt.pause(0.0001)
            
        except:
            print("Keyboard Interrupt")         # Send signal to abort task, ex CTRL + C
            break


main()
