from DrawingToolbox import *

def DrawCirclePattern(x, y, radius):
    setpos(x, y)
    DrawCentredCircle(radius)
    if radius > 20:
        DrawCirclePattern(x + radius, y, radius/2)
        DrawCirclePattern(x - radius, y, radius/2)
        DrawCirclePattern(x, y + radius, radius/2)
        DrawCirclePattern(x, y - radius, radius/2)

tracer(0,0)
DrawCirclePattern(0,0, 200)


