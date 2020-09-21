import serial
import matplotlib.pyplot as plt
import numpy as np
import csv
import time


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
    
    plt.ion()
    #fig = plt.figure()
    #x = 0
    turns = 0


    fieldnames = ["x_valueCar", "y_valueCar", "x_valueObject", "y_valueObject"]

    x_valueCar = 0
    y_valueCar = 0
    x_valueObject = 0
    y_valueObject = 0

    #open data.csv to write
    with open('data.csv', 'w') as csv_file:
        csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        csv_writer.writeheader()

    while True:    
        ser_bytes = ser.readline()          # Get a line from the serial monitor
        data = ser_bytes.decode().split()   # Split each line by whitespace
        if (len(data) != 4):                # A complete line must have 4 numbers
            continue
            
        FL = float(data[0])
        FR = float(data[1])
        L = float(data[2])
        R = float(data[3])
        print (data)
        if (FL > 150) or (FR > 150) or (L > 150) or (R > 150):
            continue
        distancesFL.append(FL)
        distancesFR.append(FR)
        distancesSL.append(L)
        distancesSR.append(R)
        
        w = 7
        v = 12

        with open('data.csv', 'a') as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

            info = {
                "x_valueCar": x_valueCar,
                "y_valueCar": y_valueCar,
                "x_valueObject": x_valueObject,
                "y_valueObject": y_valueObject,
            }

            csv_writer.writerow(info)
            print(x_valueCar, y_valueCar)
            print(x_valueObject,y_valueObject)


        time.sleep(1)
        
        if turns % 4 == 0:
            if (FL > 10.00) or (FR > 10.00):
                ##plt.scatter(150 - FL - v, L + w)
                ##plt.scatter(150 - FL - v, R)
                x_valueCar = 150 - FL - v
                y_valueCar = L + w
                x_valueObject = 150 - FL - v
                y_valueObject = R + (w*2)
            else:
                turns += 1
                #plt.scatter(150 - FL - v, L + w)
                #plt.scatter(150 - FL - v, R)
                x_valueCar = 150 - FL - v
                y_valueCar = L + w
                x_valueObject = 150 - FL - v
                y_valueObject = R + (w*2)
        elif turns % 4 == 1:
            if (FL > 10.00) or (FR > 10.00):
                #plt.scatter(150 - L - w, FL - v)
                #plt.scatter(150 - R, FL - v)
                x_valueCar = 150 - L - w
                y_valueCar = FL - v
                x_valueObject = 150 - R - (w*2)
                y_valueObject = FL - v
            else:
                turns += 1
                #plt.scatter(150 - L - w, FL - v)
                #plt.scatter(150 - R, FL - v)
                x_valueCar = 150 - L - w
                y_valueCar = FL - v
                x_valueObject = 150 - R - (w*2)
                y_valueObject = FL - v
        elif turns % 4 == 2:
            if (FL > 10.00) or (FR > 10.00):
                #plt.scatter(FL + v, 150 - L)
                #plt.scatter(FL + v, R)
                x_valueCar = FL + v
                y_valueCar = 150 - L
                x_valueObject = FL + v
                y_valueObject = R
            else:
                turns += 1
                #plt.scatter(FL + v, 150 - L)
                #plt.scatter(FL + v, R)
                x_valueCar = FL + v
                y_valueCar = 150 - L
                x_valueObject = FL + v
                y_valueObject = R
        elif turns % 4 == 3:
            if (FL > 10.00) or (FR > 10.00):
                #plt.scatter(L + w, FL + v)
                #plt.scatter(L + w, R)
                x_valueCar = L + w
                y_valueCar = FL + v
                x_valueObject = R + (w*2)
                y_valueObject = FL + v
            else:
                turns += 1
                #plt.scatter(L + w, FL + v)
                #plt.scatter(L + w, R)
                x_valueCar = L + w 
                y_valueCar = FL + v
                x_valueObject = R + (w*2)
                y_valueObject = FL + v
        
        #ax.set_xlim(-2, 2)
        #ax.set_ylim(-1.5, 1.5)
                    
        plt.show()
        plt.pause(0.0001)

main()
