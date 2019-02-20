import turtle

screen = turtle.Screen()    # create a new screen
screen.setup(500,500)       # 500 x 500 window

turt = turtle.Turtle()      # create a new turtle
turt.speed(2)               # make it move faster
turt.pencolor("blue")
turt.pensize(4)

i = 9
# define a function that draws one square
def draw_square() : 
    for side in range(4) :
        turt.forward(100)
        turt.left(90)

turt.penup() # go off-screen on the left
turt.goto(-350, 0)
turt.pendown()

while True : # now do this repeatedly, to animate :
    turt.clear() # - clear all the turtle's previous drawings
    draw_square() # - draw a square
    turt.forward(10) # - move forward a bit
