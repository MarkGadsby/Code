from turtle import Turtle, Screen
from time import sleep
from random import randrange

import DrawingFunctions

# procedure to handle a single move
def MoveForwardOneSquare():
    global forward
    xpos = banana.xcor()
    ypos = banana.ycor()
    
    if (forward == True):
        if  (xpos < 270):
            xpos += 60 
        else:
            banana.left(180)    
            ypos += 60 
            forward = False
    else:
        if  (xpos > -270):
            xpos -= 60 
        else:

            banana.left(180)    
            ypos += 60 
            forward = True

    banana.setpos(xpos,ypos)
    window.update()

# Setup window
window = Screen()
window.setup(600, 600)
window.bgcolor("black")

window.tracer(0)
DrawingFunctions.DrawGrid()

banana = Turtle() 

# Set starting pos
banana.penup()
banana.color("white")
banana.shape("turtle")

banana.setpos(-270, -270)
window.update()
forward = True

print("YOU HAVE NOW COMMENCED THE GAME!!!")

# while still got some board left
while (banana.ycor() <= 270 ):
    input("Press any key to take turn")
    roll = int(randrange(1, 7))
    # excellent guys you have used the 'f' and everthing!
    print(f"You rolled  {roll}!")

    for i in range(roll):
        MoveForwardOneSquare()
        
i = 3
print("You're done!")

while (i):
    sleep(1)
    i = ii - 1