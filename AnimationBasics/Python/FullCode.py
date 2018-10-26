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

# PADDLES

L = Turtle()
R = Turtle()
L.penup()
R.penup()

# Paddles shape
paddle_w_half = 10 / 2      # 10 units wide
paddle_h_half = 40 / 2      # 40 units high
paddle_shape = Shape("compound")
paddle_points = ((-paddle_h_half, -paddle_w_half),
                 (-paddle_h_half, paddle_w_half),
                 (paddle_h_half, paddle_w_half),
                 (paddle_h_half, -paddle_w_half))
paddle_shape.addcomponent(paddle_points, "black")
screen.register_shape("paddle", paddle_shape)
L.shape("paddle")
R.shape("paddle")

# Move paddles into position
L.setx(play_left + 10)
R.setx(play_right - 10)

paddle_L_move_direction = 0   # L paddle movement direction in next frame
paddle_R_move_direction = 0   # R paddle movement direction in next frame

paddle_move_vert   = 4        # Vertical movement distance per frame

def paddle_is_allowed_to_move_here (new_y_pos) :
    if (play_bottom > new_y_pos - paddle_h_half) : # bottom of paddle below bottom of field
        return False
    if (new_y_pos + paddle_h_half > play_top) :    # top of paddle above top of field
        return False
    return True

def update_paddle_positions () :
    L_new_y_pos = L.ycor() + (paddle_L_move_direction * paddle_move_vert)
    R_new_y_pos = R.ycor() + (paddle_R_move_direction * paddle_move_vert)
    if paddle_is_allowed_to_move_here (L_new_y_pos):
        L.sety( L_new_y_pos )
    if paddle_is_allowed_to_move_here (R_new_y_pos):
        R.sety( R_new_y_pos )

def L_up() :
    global paddle_L_move_direction
    paddle_L_move_direction = 1

def L_down() :
    global paddle_L_move_direction
    paddle_L_move_direction = -1

def L_off() :
    global paddle_L_move_direction
    paddle_L_move_direction = 0

def R_up() :
    global paddle_R_move_direction
    paddle_R_move_direction = 1

def R_down() :
    global paddle_R_move_direction
    paddle_R_move_direction = -1

def R_off() :
    global paddle_R_move_direction
    paddle_R_move_direction = 0

screen.onkeypress(L_up, "w")
screen.onkeypress(L_down, "z")
screen.onkeypress(R_up, "Up")
screen.onkeypress(R_down, "Down")
screen.onkeyrelease(L_off, "w")
screen.onkeyrelease(L_off, "z")
screen.onkeyrelease(R_off, "Up")
screen.onkeyrelease(R_off, "Down")
screen.listen()

# SCORE

score_turtle = Turtle()
score_turtle.penup()
score_turtle.hideturtle()

score_L = 0
score_R = 0

def write_scores() :
    score_turtle.clear()
    score_turtle.goto(-screen.window_width()/4, screen.window_height()/2 - 80)
    score_turtle.write(score_L, align="center", font=("Arial", 32, "bold"))
    score_turtle.goto(screen.window_width()/4, screen.window_height()/2 - 80)
    score_turtle.write(score_R, align="center", font=("Arial", 32, "bold"))

def check_if_someone_scores() :
    global score_L, score_R
    if (ball.xcor() + ball_radius) >= play_right :   # right of ball at right of field
        score_L += 1
        write_scores()
        reset_ball()
    elif play_left >= (ball.xcor() - ball_radius) :  # left of ball at left of field
        score_R += 1
        write_scores()
        reset_ball()

# BALL

ball = Turtle()
ball.penup()
ball.shape("circle")        # Use the built-in shape "circle"
ball.shapesize( 0.5, 0.5)   # Stretch it to half default size
ball_radius = 10 * 0.5      # Save the new radius for later

ball_move_horiz = 3           # Horizontal movement per frame
ball_move_vert  = 2           # Vertical movement per frame

def ball_collides_with_paddle (paddle) :
    x_distance = abs(paddle.xcor() - ball.xcor())
    y_distance = abs(paddle.ycor() - ball.ycor())
    overlap_horizontally = (ball_radius + paddle_w_half >= x_distance)  # either True or False
    overlap_vertically   = (ball_radius + paddle_h_half >= y_distance)  # either True or False
    return overlap_horizontally and overlap_vertically                  # so it returns either True or False

def update_ball_position () :
    global ball_move_horiz, ball_move_vert
    if ball.ycor() + ball_radius >= play_top :       # top of ball at or above top of field
        ball_move_vert *= -1
    elif play_bottom >= ball.ycor() - ball_radius :  # bottom of ball at or below bottom of field
        ball_move_vert *= -1
    if ball_collides_with_paddle(R) or ball_collides_with_paddle(L) :
        ball_move_horiz *= -1
    ball.setx(ball.xcor() + ball_move_horiz)
    ball.sety(ball.ycor() + ball_move_vert)

def reset_ball() :
    global ball_move_vert, ball_move_horiz
    ball.setpos(0, 0)
    speed_horiz = randint(2,4)
    speed_vert = randint(2,4)
    direction_horiz = 1
    direction_vert = 1
    if randint(0,100) > 50 :  # 50% chance of going left instead of right
        direction_horiz = -1
    if randint(0,100) > 50 :  # 50% chance of going down instead of up
        direction_vert = -1
    ball_move_horiz = direction_horiz * speed_horiz
    ball_move_vert  = direction_vert * speed_vert

# FRAME

def frame () :
    check_if_someone_scores()
    update_paddle_positions()
    update_ball_position()
    screen.update()                      # show the new frame
    screen.ontimer(frame, framerate_ms)  # schedule this function to be called again a bit later

write_scores()
framerate_ms = 40  # Every how many milliseconds must frame function be called?
frame()
