# Importing necessary modules
from sense_hat import SenseHat
from time import sleep
from random import randint

sense = SenseHat()

# Declaring initial variables
yellow = (255, 255, 0)
blank = (0, 0, 0)

c1 = blank
c2 = yellow
# Modifying to switch between random colours

for i in range(5):
    rotates = [0, 90, 180, 270]
    randrot = randint(0, 3)
    c2 = (randint(0, 255), randint(0, 255), randint(0, 255))
    # c2 = (randint(0, 255), randint(0, 255), randint(0, 255))
    c1 = blank
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
    sleep(1)
    sense.clear()