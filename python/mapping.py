import tkinter as tk # importing tkinter library so we can use graphics
from PIL import ImageTk, Image
import matplotlib.pyplot as plt

# NOTE: Tkinter window's top left corner is (0,0). 
# X-axis increases when goes right. Y-axis increases when goes down

# global variables for specifying window's size
WINDOW_HEIGHT = 600
WINDOW_WIDTH = 600

car_queue = [] # list/array for storing car
dot_canvas_list = [] # list/array for storing dot

class Car:
    def __init__(self, canvas):
        # initialize position of car and draw on canvas
        # <self> refers to the class itself. Below codes are essentially "attributes" for car's class
        self.x1 = 10
        self.y1 = 10
        self.x2 = 60
        self.y2 = 50
        self.draw(canvas)

    def draw(self, canvas):
        # remove car from the list if the list is not empty
        if len(car_queue) != 0: # len() return amount of data in the parameter
            canvas.delete(car_queue[0]) # delete car from canvas. If don't do this, then previous car will stay there
            car_queue.pop()
        
        size = 30
        # create yellow car on canvas. create_oval(x1, y1, x2, y2) draws a circle. 
        # Topleft is at (x1,y1). Bottomright at (x2,y2)
        x = canvas.create_rectangle(self.x1, self.y1, self.x2, self.y2, fill='red')
        #x = canvas.create_oval(self.x - size, self.y - size, self.x + size, self.y + size, fill='yellow')
        # store car at the list
        car_queue.append(x)
    
    def moveLeft(self, event, canvas):
        self.x -= 10
        self.draw(canvas)
    
    def moveRight(self, event, canvas):
        self.x += 10
        self.draw(canvas)

    def moveUp(self, event, canvas):
        self.y -= 10
        self.draw(canvas)

    def moveDown(self, event, canvas):
        self.y += 10
        self.draw(canvas)

class Dot:
    def __init__(self, canvas, car):
        # initialize position by randomization
        # call randrange() function from random library. Random number in range (0, WINDOW_WIDTH)
        self.x = ((car.x2 - car.x1) / 2) + car.x1
        self.y = ((car.y2 - car.y1) / 2) + car.y1
        self.draw(canvas) # draw the dot on canvas

    # draw a dot on canvas
    def draw(self, canvas):
        size = 5
        # create a circle on canvas
        x = canvas.create_oval(self.x - size, self.y - size, self.x + size, self.y + size, fill='white')
        # append the dot to dot list
        dot_canvas_list.append(x)



# check if car is on top of dot or not
def check(car, dot, canvas, window):
    if car.x - 30 <= dot.x <= car.x + 30\
        and car.y - 30 <= dot.y <= car.y + 30:
        canvas.delete(dot_canvas_list[0]) # erase dot from canvas
        dot_canvas_list.pop() # remove dot from list
        dot.changePos() # reassign a new position and draw on canvas
        dot.draw(canvas)

    window.after(100, check, car, dot, canvas, window) # use check() every 100 milliseconds
    # tk.after(<time-interval>, <function>, argument1, argument2, ...) call the <function> in every <time-interval>
    # and passing argument1, argument2, ... into the function
    
# check if car is on top of ghost or not
def gameOver(car, ghost, canvas, window):
    if car.x - 30 <= ghost.x <= car.x + 30\
        and car.y - 30 <= ghost.y <= car.y + 30:
        canvas.delete(ghost_canvas_list[0]) # erase ghost from canvas
        ghost_canvas_list.pop() # remove ghost from list
        canvas.delete(dot_canvas_list[0]) # erase dot from canvas
        dot_canvas_list.pop() # remove dot from list
        canvas.delete(car_queue[0])
        window.unbind("<KeyPress-Left>") # need to pass event, otherwise won't work
        window.unbind("<KeyPress-Right>")
        window.unbind("<KeyPress-Up>")
        window.unbind("<KeyPress-Down>")
        canvas.configure(bg='white')
        canvas.create_text(WINDOW_WIDTH/2,WINDOW_HEIGHT/2,fill="darkblue",font=("Times 20 italic bold",70),
                        text="GAME OVER")

    window.after(100, gameOver, car, ghost, canvas, window)
 
def main():
    window = tk.Tk() # create window pop-up
    canvas = tk.Canvas(window, width=WINDOW_WIDTH, height=WINDOW_HEIGHT, bg='black') # create Canvas widget for drawing
    canvas.pack() # pack() organize, aka update, widgets onto canvas

    path = "mango.jpg"

    car = Car(canvas) # pass in canvas so car can be drawn

    # read in continuously the data points

    dot = Dot(canvas, car)
    '''
    #Creates a Tkinter-compatible photo image, which can be used everywhere Tkinter expects an image object.
    img = ImageTk.PhotoImage(Image.open(path).resize((30, 30), Image.ANTIALIAS))
    ## The (250, 250) is (height, width)
    ghost = Ghost(canvas, img)'''


    window.after(100, check, car, dot, canvas, window) # call check() to check dot&car after 100 milliseconds
    window.mainloop() # tk.mainloop() -> keep looping until there's an update

main()