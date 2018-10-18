Recursive circles with Turtle Graphics in Python
================================================

To get the turtle graphic library into your code use:

_from turtle import *_

You can find all the latest help [HERE][helplink]:

[helplink]:https://docs.python.org/3.7/library/turtle.html
	
	a little way down is list of Turtle methods, some for turtle motion (move and draw)

---
---
**Challenge:** Using the circle method can you write some code to draw a circle with a 100 pixel radius?

**Observation:** Note where the drawing starts and stops and in which direction the Turtle is pointing when it’s first initialised.

**Enhancement:** Can you find the methods needed to make the circle draw in a particular colour, line width and speed?

---
---
**Challenge:** Draw concentric circles, that’s circles decreasing in size inside each other. Think about using a while loop with the value for the radius as the controlling variable.

**Observation:** Are the circles all inside each other but not centred?

**Enhancement:** Can we ‘wrap’ the circle() function so that each circle is drawn from it’s centre? Such a enhanced function could go in separate ‘module’ to be imported wherever we need it. 

---
---
	Hints: You can use  xcor() and ycor() to find the current coordinates of the turtle. penup() and pendown() allow you to move the turtle without drawing on the screen  

---
---
**Challenge:** Once you have the concentric circles drawing correctly using the while loop can you achieve the same result using a recursive function instead?

