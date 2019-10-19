import pgzrun

alien = Actor('alien')
alien.topright = 0, 10

WIDTH = 1400
HEIGHT = alien.height + 20

speed = 1

def update():
    alien.left += speed
    if alien.left > WIDTH:
        alien.right = 0

def draw():
    screen.clear()
    alien.draw()
    
def on_mouse_down(pos):
    if alien.collidepoint(pos):
        set_alien_hurt()

def set_alien_hurt():
    global speed
    alien.image = 'alien_hurt'
    sounds.eep.play()
    speed += 0.4
    clock.schedule_unique(set_alien_normal, 0.1)
    
def set_alien_normal():
    alien.image = 'alien'
    
pgzrun.go()
