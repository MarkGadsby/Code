from turtle import *

def DrawCentredCircle(radius):
    penup()
    setpos(xcor(), ycor() - radius)
    pendown()
    circle(radius)
    penup()
    setpos(xcor(), ycor() + radius)
