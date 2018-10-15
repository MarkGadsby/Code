from DrawingToolbox import *

def DrawConcentricCircles(radius, reduction):
    if radius < reduction:
        return
    DrawCentredCircle(radius)
    radius -= reduction
    DrawConcentricCircles(radius, reduction)

DrawConcentricCircles(300, 60)


