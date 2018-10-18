from DrawingToolbox import *
import turtle

def DrawConcentricCircles(radius, reduction):
    if radius < reduction:
        return
    DrawCentredCircle(radius)
    radius -= reduction
    DrawConcentricCircles(radius, reduction)

turtle.tracer(0, 0)
DrawConcentricCircles(300, 60)


