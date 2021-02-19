from turtle import Turtle

banana = Turtle()

def DrawPShape():
    banana.forward(60)
    banana.right(90)
    banana.forward(600)
    banana.left(90)
    banana.forward(60)
    banana.left(90)
    banana.forward(600)

def DrawRow():    
    banana.left(90)
    DrawPShape()
    banana.left(180)

def DrawCol():    
    DrawPShape()
    banana.right(90)

def DrawGrid():
    banana.shape("turtle")
    banana.pencolor("navy")
    banana.pensize(5)
    banana.penup()  
    banana.setpos(-300, -300)
    banana.pendown()

    while banana.ycor() < 300:
        DrawRow()

    while banana.xcor() < 300:
        DrawCol()      