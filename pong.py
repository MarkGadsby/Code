from turtle import Turtle, Screen, Shape
from random import randint

# SCREEN
screen = Screen()
screen.setup(600, 400)   # width, height
screen.tracer(0)         # We'll handle displaying of frames ourselves

# PLAY AREA
play_top    = screen.window_height() / 2 - 100    # top of screen minus 100 units
play_bottom = -screen.window_height() / 2 + 100   # 100 from bottom
play_left   = -screen.window_width() / 2 + 50     # 50 from left
play_right  = screen.window_width() / 2 - 50      # 50 from right

area = Turtle()
area.hideturtle()
area.penup()
area.goto(play_right, play_top)
area.pendown()
area.goto(play_left, play_top)
area.goto(play_left, play_bottom)
area.goto(play_right, play_bottom)
area.goto(play_right, play_top)

# BALL
ball = Turtle()
ball.penup()
ball.shape("circle")

ball_move_horiz = 4           # Horizontal movement per frame
ball_move_vert  = 2           # Vertical movement per frame


def update_ball_position ():
    global ball_move_vert, ball_move_horiz
    if ball.ycor() + 10 >= play_top:
        ball_move_vert *= -1
    elif ball.xcor() + 10 >= play_right:
        ball_move_horiz *= -1
    if ball.ycor() - 10 <= play_bottom:
        ball_move_vert *= -1
    elif ball.xcor() - 10 <= play_left:
        ball_move_horiz *= -1
        
        
        
    ball.setx(ball.xcor() + ball_move_horiz)
    ball.sety(ball.ycor() + ball_move_vert)

def frame () :
    update_ball_position()
    screen.update()                      # show the new frame
    screen.ontimer(frame, framerate_ms)  # schedule this function to be called again a bit later

framerate_ms = 2  # Every how many milliseconds must frame function be called?
frame()
    

