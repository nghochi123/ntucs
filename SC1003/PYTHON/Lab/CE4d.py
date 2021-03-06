from sense_hat import SenseHat
from time import sleep
from random import randint

sense = SenseHat()

# Setup variables

red = (255, 0, 0)
green = (0, 255, 0)
blank = (0, 0, 0)

g = 1
delay = 1

score = 0


while True:
    # Display image of green arrow in random orientation.
    rotates = [0, 90, 180, 270]
    randrot = randint(0, 3)
    userrot = -1
    c1 = blank
    c2 = green
    image_pixels = [c1, c1, c1, c1, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c2, c2, c2, c1, c1, c1,
                    c1, c2, c1, c2, c1, c2, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c1, c1, c1, c1, c1]
    sense.set_rotation(rotates[randrot])
    sense.set_pixels(image_pixels)
    sleep(delay)
    acc = sense.get_accelerometer_raw()
    x = round(acc['x'])
    y = round(acc['y'])
    z = round(acc['z'])
    sense.clear()
    # After 1 second, read the accelerometer data.
    if y > g/2:
        # If +y facing downwards:
        userrot = 0
    elif x < -g/2:
        # If +x facing downwards:
        userrot = 1
    elif y < -g/2:
        # If -y facing downwards:
        userrot = 2
    elif x > g/2:
        # If -x facing downwards:
        userrot = 3
    if userrot != randrot:
        # If user rotation does not match the random rotation, end game.
        c2 = red
        image_pixels = [c1, c1, c1, c1, c1, c1, c1, c1,
                        c1, c1, c1, c2, c1, c1, c1, c1,
                        c1, c1, c2, c2, c2, c1, c1, c1,
                        c1, c2, c1, c2, c1, c2, c1, c1,
                        c1, c1, c1, c2, c1, c1, c1, c1,
                        c1, c1, c1, c2, c1, c1, c1, c1,
                        c1, c1, c1, c2, c1, c1, c1, c1,
                        c1, c1, c1, c1, c1, c1, c1, c1]
        sense.set_pixels(image_pixels)
        sleep(1)
        sense.show_message(str(score),
                          text_colour=red,
                          back_colour=blank)
        exit()
    else:
        # Add to score if user rotation matches
        score += 1
        delay -= 0.1