import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()


def animate(i):
    data = pd.read_csv('data.csv')
    x1 = data['x_valueCar']
    y1 = data['y_valueCar']
    x2 = data['x_valueObject']
    y2 = data['y_valueObject']

    plt.cla()

    plt.plot(x1, y1, label='Car Position')
    plt.plot(x2, y2, label='Object Position')

    plt.legend(loc='upper left')
    plt.tight_layout()


ani = FuncAnimation(plt.gcf(), animate, interval=1000)

plt.tight_layout()
plt.show()
