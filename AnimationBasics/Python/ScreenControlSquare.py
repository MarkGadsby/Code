import turtle

screen = turtle.Screen()    # create a new screen
screen.setup(500,500)       # 500 x 500 window
screen.tracer(0)            # take control of the screen drawing
screen.bgcolor("orange")

turt = turtle.Turtle()      # create a new turtle
turt.pencolor("yellow")
turt.pensize(4)
turt.speed(0)

# define a function that draws one square
def draw_square() : 
    for side in range(4) :
        turt.forward(100)
        turt.left(90)

# go off-screen on the left
turt.penup() 
turt.goto(-350, 0)
turt.pendown()

# do this repeatedly, to animate
while True :        
    if (turt.xcor() <= 250) :   # once across the screen, stop
        turt.clear()        # - clear all the turtle's previous drawings
        draw_square()       # - draw a square
        screen.update()
        turt.forward(0.05)  # - move 
    else :
        break

screen.bye()
