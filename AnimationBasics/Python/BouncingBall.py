from turtle import Turtle, Screen

# Screen
screen = Screen()
screen.setup(640, 450)   # width, height
screen.tracer(0)         # We'll handle displaying of frames ourselves
screen.bgcolor("Indigo")

# Area
play_top    = screen.window_height() / 2 - 45   # top of screen minus 45 units
play_bottom = -screen.window_height() / 2 + 45  # 45 from bottom
play_left   = -screen.window_width() / 2 + 64   # 64 from left
play_right  = screen.window_width() / 2 - 64    # 64 from right

border_width = 26
border = border_width / 2

area = Turtle()
area.color("Thistle", "Azure")
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

# Square
square = Turtle()
square.penup()
square.shape("square")
square.color("Sienna","plum")
square.shapesize(5,5,2)
square_half_width = 10 * 5; 
square_move_horiz = 2           # Horizontal movement per frame
square_move_vert  = 3           # Vertical movement per frame

walls = True

def switch(x, y):
    global walls
    if (walls):
        walls = False
    else:
        walls = True

def k1():
    square.color("plum","Sienna")
    

square.onclick(switch)
screen.onkey(k1, "Up")
screen.listen()

# Ball
ball = Turtle()
ball.penup()
ball.shape("circle")
ball.color("navy")
ball.shapesize(1.5)
ball_radius = 15              # Save the new radius for later

ball_move_horiz = 6           # Horizontal movement per frame
ball_move_vert  = 7.5          # Vertical movement per frame


def update_ball_position():
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

def update_ball_position_square():
    global ball_move_vert, ball_move_horiz, square

    if ball.ycor() + ball_radius >= square.ycor() + square_half_width:
        ball.sety((square.ycor() + square_half_width) - ball_radius)
        ball_move_vert *= -1
    elif ball.xcor() + ball_radius >= square.xcor() + square_half_width:
        ball.setx(square.xcor() + square_half_width - ball_radius)
        ball_move_horiz *= -1
    if ball.ycor() - ball_radius <= square.ycor() - square_half_width:
        ball.sety((square.ycor() - square_half_width) + ball_radius)
        ball_move_vert *= -1
    elif ball.xcor() - ball_radius <= square.xcor() - square_half_width:
        ball.setx(square.xcor() - square_half_width + ball_radius)
        ball_move_horiz *= -1
                
    ball.setx(ball.xcor() + ball_move_horiz)
    ball.sety(ball.ycor() + ball_move_vert)


def update_square_position():
    global square_move_vert, square_move_horiz

    if square.ycor() + square_half_width + border >= play_top:
        square_move_vert *= -1
    elif square.xcor() + square_half_width + border  >= play_right:
        square_move_horiz *= -1
    if square.ycor() - square_half_width - border  <= play_bottom:
        square_move_vert *= -1
    elif square.xcor() - square_half_width - border  <= play_left:
        square_move_horiz *= -1
                
    square.setx(square.xcor() + square_move_horiz)
    square.sety(square.ycor() + square_move_vert)

def frame ():
    global walls
    if (walls):
        update_ball_position_square()
        square.color("Sienna","plum")
    else:
        update_ball_position()
        square.color("plum","plum")
    
    update_square_position()
    screen.update()                      # show the new frame
    screen.ontimer(frame, framerate_ms)  # schedule this function to be called again a bit later

framerate_ms = 20  # Every how many milliseconds must frame function be called?
frame()
