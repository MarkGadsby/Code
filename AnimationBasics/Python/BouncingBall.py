from turtle import Turtle, Screen, Shape

# SCREEN
screen = Screen()
screen.setup(640, 450)   # width, height
screen.tracer(0)         # We'll handle displaying of frames ourselves
screen.bgcolor("green")

# PLAY AREA
play_top    = screen.window_height() / 2 - 45   # top of screen minus 45 units
play_bottom = -screen.window_height() / 2 + 45  # 45 from bottom
play_left   = -screen.window_width() / 2 + 64   # 64 from left
play_right  = screen.window_width() / 2 - 64    # 64 from right

border_width = 16
border = border_width / 2

area = Turtle()
area.color("white", "light green")
area.begin_fill()
area.pensize(border_width)
area.hideturtle()
area.penup()
area.goto(play_right, play_top)
area.pendown()
area.goto(play_left, play_top)
area.goto(play_left, play_bottom)
area.goto(play_right, play_bottom)
area.goto(play_right, play_top)
area.end_fill()

# BALL
ball = Turtle()
ball.penup()
ball.shape("circle")
ball.color("green")
ball_size = 1

ball.shapesize(ball_size)
ball_radius = 10 * ball_size  # Save the new radius for later

ball_move_horiz = 4           # Horizontal movement per frame
ball_move_vert  = 6           # Vertical movement per frame

def update_ball_position ():
    global ball_move_vert, ball_move_horiz

    if ball.ycor() + ball_radius + border >= play_top:
        ball_move_vert *= -1
    elif ball.xcor() + ball_radius + border  >= play_right:
        ball_move_horiz *= -1
    if ball.ycor() - ball_radius - border  <= play_bottom:
        ball_move_vert *= -1
    elif ball.xcor() - ball_radius - border  <= play_left:
        ball_move_horiz *= -1
                
    ball.setx(ball.xcor() + ball_move_horiz)
    ball.sety(ball.ycor() + ball_move_vert)

def frame () :
    update_ball_position()
    screen.update()                      # show the new frame
    screen.ontimer(frame, framerate_ms)  # schedule this function to be called again a bit later

framerate_ms = 20  # Every how many milliseconds must frame function be called?
frame()
