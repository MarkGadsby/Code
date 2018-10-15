# load the turtle library

from turtle import *

radius = 200

colormode(255)
pencolor(255,0,0)
pensize(2)
speed(10)

while radius > 10:
    circle(radius)
    radius -= 20
